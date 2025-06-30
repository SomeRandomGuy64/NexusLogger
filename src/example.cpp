#include "NexusLogger.h"

int main() {

	Nexus::Logger logger;

	logger.log("Hello from NexusLogger!");
	logger.log("Hello from NexusLogger! (with time)", true);

	//colour and emphasis output

	logger.log("\n");
	logger.log("White, default (bold)", true, logger.White);
	logger.log("Green, blink", true, logger.Green, logger.Blink);
	logger.log("Blue, conceal", true, logger.Blue, logger.Conceal);
	logger.log("Yellow, faint", true, logger.Yellow, logger.Faint);
	logger.log("Orange, italic", true, logger.Orange, logger.Italic);
	logger.log("Red, reverse", true, logger.Red, logger.Reverse);
	logger.log("Purple, strikethrough", true, logger.Purple, logger.Strikethrough);
	logger.log("Pink, underline", true, logger.Pink, logger.Underline);

	// other types

	logger.log("\n");
	logger.critical("Critical");
	logger.error("Error");
	logger.warn("Warn");
	logger.info("Info");
	logger.trace("Trace");
	logger.debug("Debug");

}