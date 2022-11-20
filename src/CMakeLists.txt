add_library(
  src
  app.h
  entity.h
  game.h
  player.h
  app.c
  boulder.c
  colors.c
  entity.c
  game.c
  player.c
)

target_include_directories(
  src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
