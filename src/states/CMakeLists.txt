set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  states
  game.h
  game.c
  level_select.h
  level_select.c
  main_menu.h
  main_menu.c
)

target_include_directories(
  states PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/states"
)

