# Created library to be linked.
add_library(operator operator.cpp)


target_include_directories(operator INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

