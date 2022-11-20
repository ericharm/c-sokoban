add_library(
  src
  app.h
  entity.h
  game.h
  app.c
  colors.c
  entity.c
  game.c
)

target_include_directories(
  src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
