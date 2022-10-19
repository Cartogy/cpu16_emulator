add_library(operators operator_table.cpp operator.cpp opers.cpp oper_utils.cpp)


target_include_directories(operators INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
