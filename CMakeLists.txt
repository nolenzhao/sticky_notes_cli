
cmake_minimum_required(VERSION 3.10)

project(sticky_notes_cli)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src/headers)
include_directories(${PROJECT_SOURCE_DIR}/src/commands)
include_directories(${PROJECT_SOURCE_DIR}/src/helpers)
include_directories(${PROJECT_SOURCE_DIR}/sqlite)
include_directories(${SQLite3_INCLUDE_DIRS})

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable target
add_executable(sticky_notes_cli ${SOURCES})

# Find and link SQLite3 library
find_package(SQLite3 REQUIRED)
target_link_libraries(sticky_notes_cli ${SQLite3_LIBRARIES})
target_link_libraries(sticky_notes_cli sqlite3)

# Find and link Core Foundation and Core Services frameworks
find_library(COREFOUNDATION_LIBRARY CoreFoundation)
find_library(CORESERVICES_LIBRARY CoreServices)
target_link_libraries(sticky_notes_cli ${COREFOUNDATION_LIBRARY} ${CORESERVICES_LIBRARY})
