cmake_minimum_required(VERSION 3.30)

# Set the project name
project(NexusLoggerProject LANGUAGES CXX)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- fmt Library ---
add_subdirectory(vendor/fmt)

# --- NexusLogger Library ---
add_library(NexusLogger INTERFACE)

target_sources(NexusLogger INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/NexusLogger.h
)

# Specify the include directory for NexusLogger
target_include_directories(NexusLogger INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link NexusLogger to fmt for its public interface.
target_link_libraries(NexusLogger INTERFACE
    fmt
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/NexusLogger.h
    DESTINATION include
)

add_executable(NexusLoggerExample src/example.cpp)
target_link_libraries(NexusLoggerExample PRIVATE NexusLogger)

# Set some common CMake properties for Visual Studio
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT NexusLoggerExample)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)