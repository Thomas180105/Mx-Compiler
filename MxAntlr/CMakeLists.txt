cmake_minimum_required(VERSION 3.16.3)

include_directories(/usr/include/antlr4-runtime/)

file(GLOB MxAntlrSources *.cpp)

add_library(MxAntlr STATIC ${MxAntlrSources})
target_link_libraries(MxAntlr PUBLIC antlr4-runtime)
