add_library(popertable popertable.cpp)

add_subdirectory(InsCategory)

target_link_libraries(popertable inscategory)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
