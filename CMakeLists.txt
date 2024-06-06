# cmake_minimum_required(VERSION 3.10)
# project(sticky_notes_cli)

# # Set the C++ standard
# set(CMAKE_CXX_STANDARD 17)

# # Include directories
# include_directories(include)

# # Add the executable target
# add_executable(sticky_notes_cli src/main.cpp)

# # Find and link SQLite3 library
# find_package(SQLite3 REQUIRED)
# include_directories(${SQLite3_INCLUDE_DIRS})
# include_directories(${CMAKE_SOURCE_DIR}/sqlite)
# add_library(sqlite3 STATIC ${CMAKE_SOURCE_DIR}/sqlite/sqlite3.c)
# target_link_libraries(sticky_notes_cli ${SQLite3_LIBRARIES})


cmake_minimum_required(VERSION 3.10)
project(sticky_notes_cli)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src/headers)
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
