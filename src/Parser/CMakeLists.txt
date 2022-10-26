add_library(parser asmparser.cpp parsernode.cpp)

add_subdirectory(POperTable)

target_link_libraries(parser popertable)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
