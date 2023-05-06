add_library(
  src
  app.h
  centerizer.h
  colors.h
  entity.h
  entity_list.h
  level_reader.h
  logger.h
  point.h
  app.c
  centerizer.c
  entity.c
  entity_list.c
  level_reader.c
  logger.c
  point.c
)

target_include_directories(
  src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
