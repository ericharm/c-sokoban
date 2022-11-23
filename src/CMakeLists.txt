add_library(
  src
  app.h
  colors.h
  entity.h
  game.h
  level_reader.h
  logger.h
  point.h
  app.c
  entity.c
  game.c
  level_reader.c
  logger.c
  point.c
)

target_include_directories(
  src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
