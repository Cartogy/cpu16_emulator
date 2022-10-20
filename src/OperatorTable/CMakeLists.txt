add_library(operator_table operator_table.cpp oper_utils.cpp)

add_subdirectory(Operator)


target_include_directories(operator_table INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
