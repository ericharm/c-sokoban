cmake_minimum_required(VERSION 3.22.3)

# set the project name
project(sokoban)

add_subdirectory(src)
# add_subdirectory(src/states)
# add_subdirectory(src/entities)

# specify the C++ standard
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# add the executable
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(
  ${PROJECT_NAME}
  src
  # states
  # entities
  ${CURSES_LIBRARIES}
)

