cmake_minimum_required(VERSION 3.25)

# set the project name and version
project(TracerServer VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_BUILD_TYPE Debug)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(config.h.in config.h)

# add the executable
add_executable(TracerServer 
    main.cpp
    Receiver.cpp
    AbstractTracerDb.h
    FileStorageTracerDb.h
    EventController.h
    EntityService.cpp
    rules/AbstractRule.cpp
    rules/RulesFactory.cpp
    rules/CountGetsRule.cpp
    parsers/HttpParser.cpp
    parsers/ParserFactory.cpp
    storage/FileStorage.cpp
)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}" .)
