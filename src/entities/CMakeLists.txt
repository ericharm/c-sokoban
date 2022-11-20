add_library(
  entities
  boulder.c
  player.h
  player.c
)

target_include_directories(
  entities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/entities"
)
