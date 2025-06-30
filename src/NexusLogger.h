#pragma once

#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/color.h>
#include <chrono>
#include <string>

namespace Nexus {

	class Logger {

	public:

		enum Color {

			White = fmt::color::white,
			Red = fmt::color::red,
			Blue = fmt::color::aqua,
			Green = fmt::color::green,
			Yellow = fmt::color::yellow,
			Orange = fmt::color::orange,
			Purple = fmt::color::purple,
			Pink = fmt::color::deep_pink,

		};

		enum Emphasis {

			Blink = fmt::emphasis::blink,
			Bold = fmt::emphasis::bold,
			Conceal = fmt::emphasis::conceal,
			Faint = fmt::emphasis::faint,
			Italic = fmt::emphasis::italic,
			Reverse = fmt::emphasis::reverse,
			Strikethrough = fmt::emphasis::strikethrough,
			Underline = fmt::emphasis::underline,

		};

		void log(const std::string& message, bool logTime = false, const Color color = Color::White, const Emphasis emphasis = Emphasis::Bold) {

			const std::string timeNow{ getTime() };

			fmt::color fmtColor{ static_cast<fmt::color>(color) };
			fmt::emphasis fmtEmphasis{ static_cast<fmt::emphasis>(emphasis) };

			switch (logTime) {

				case false:
					fmt::print(fmtEmphasis | fg(fmtColor), "{}\n", message);
					break;

				case true:
					fmt::print(fmtEmphasis | fg(fmtColor), "[{}] {}\n", timeNow, message);
					break;
			}

		}

	private:

		const std::string getTime() {

			std::chrono::system_clock::time_point now{ std::chrono::system_clock::now() };
			std::time_t timeNow{ std::chrono::system_clock::to_time_t(now) };
			std::tm localTime{ *std::localtime(&timeNow) };

			std::string formattedTime{ fmt::format("{:%H:%M:%S}", localTime) };

			return formattedTime;

		}

	};

}