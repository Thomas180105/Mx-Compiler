cmake_minimum_required(VERSION 3.16)
project(MxCompiler_2023)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(MxAntlr)

include_directories(/usr/include/antlr4-runtime/)
#include_directories(/usr/local/include/antlr4-runtime)
include_directories(src/AST)
include_directories(src/Semantic)
include_directories(src/Utility)
include_directories(src/IR)
include_directories(src/ASM)
include_directories(MxAntlr)

file(GLOB_RECURSE sources src/*.cpp src/*.h)

add_executable(MxCompiler_2023 ${sources} src/IR/IRType.h src/IR/IRNode.cpp src/ASM/ASMBuilder.cpp src/ASM/ASMBuilder.h src/ASM/ASMNode.cpp src/ASM/ASMNode.h src/ASM/Register.h)

target_link_libraries(MxCompiler_2023 MxAntlr)

set(TestdataPath "${PROJECT_SOURCE_DIR}/testcases")

#set(SemaPath "${TestdataPath}/sema")
#file(GLOB_RECURSE test_files RELATIVE ${SemaPath} ${SemaPath}/*.mx)
#foreach (test_file ${test_files})
#    string(REGEX REPLACE ".*/" "" filename "${test_file}")
#    set(testname "sema|${filename}")
#    execute_process(COMMAND grep "Verdict: " "${SemaPath}/${test_file}" COMMAND sed "s/Verdict: //"
#            OUTPUT_VARIABLE verdict)
#    add_test(NAME ${testname}
#            COMMAND $<TARGET_FILE:MxCompiler_2023> ${SemaPath}/${test_file} "-fsyntax-only"
#            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
#    set_tests_properties(${testname} PROPERTIES LABELS "sema")
#    if (NOT "${verdict}" STREQUAL "Success\n")
#        set_tests_properties(${testname} PROPERTIES WILL_FAIL true)
#    endif ()
#endforeach ()

set(CodegenPath "${TestdataPath}/codegen")
file(GLOB_RECURSE test_files RELATIVE ${CodegenPath} ${CodegenPath}/**.mx)
foreach (test_file ${test_files})
    string(REGEX REPLACE ".*/" "" filename "${test_file}")
#    set(testname "ir|${filename}")
#    add_test(NAME ${testname}
#            COMMAND "${PROJECT_SOURCE_DIR}/run-llvm.bash" $<TARGET_FILE:MxCompiler_2023> ${CodegenPath}/${test_file}
#            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test")
#    set_tests_properties(${testname} PROPERTIES LABELS "ir" TIMEOUT 10)

    set(testname "asm|${filename}")
    add_test(NAME ${testname}
            COMMAND "${PROJECT_SOURCE_DIR}/run-risc-v.bash" $<TARGET_FILE:MxCompiler_2023> ${CodegenPath}/${test_file}
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/test")
    set_tests_properties(${testname} PROPERTIES LABELS "asm" TIMEOUT 40)
endforeach ()

enable_testing()