add_library(
  src
  app.h
  centerizer.h
  colors.h
  entity.h
  entity_list.h
  game.h
  level_reader.h
  level_select.h
  logger.h
  point.h
  app.c
  centerizer.c
  entity.c
  entity_list.c
  game.c
  level_reader.c
  level_select.c
  logger.c
  point.c
)

target_include_directories(
  src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
