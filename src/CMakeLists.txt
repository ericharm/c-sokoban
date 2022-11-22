add_library(
  src
  app.h
  colors.h
  entity.h
  game.h
  logger.h
  point.h
  app.c
  entity.c
  game.c
  logger.c
  point.c
)

target_include_directories(
  src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
