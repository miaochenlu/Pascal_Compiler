include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(ast)
include_directories(gen)
include_directories(gen/Env)


add_custom_command(
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/scanner.cpp
        COMMAND flex -o ${CMAKE_CURRENT_LIST_DIR}/scanner.cpp ${CMAKE_CURRENT_LIST_DIR}/pascal.l
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/pascal.l ${CMAKE_CURRENT_LIST_DIR}/parser.hpp
)
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_LIST_DIR}/parser.cpp ${CMAKE_CURRENT_LIST_DIR}/parser.hpp
        COMMAND bison -d -o ${CMAKE_CURRENT_LIST_DIR}/parser.cpp ${CMAKE_CURRENT_LIST_DIR}/pascal.y
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/pascal.y
)

execute_process(COMMAND llvm-config --libs OUTPUT_VARIABLE LLVM_LINK_LIBRARIES)
string(STRIP "${LLVM_LINK_LIBRARIES}" LLVM_LINK_LIBRARIES)

add_executable(Pascal_Compiler
        ast/ast.cpp
        ast/ast.h
        gen/Env/GenFuncEnv.cpp
        gen/Env/GenFuncEnv.h
        gen/Env/GenValueEnv.cpp
        gen/Env/GenValueEnv.h
        gen/Env/GenTypeEnv.cpp
        gen/Env/GenTypeEnv.h
        gen/Env/GenLabelEnv.cpp
        gen/Env/GenLabelEnv.h
        gen/llvm/GenLLVMType.cpp
        gen/llvm/GenLLVMType.h
        gen/llvm/GenLLVMConstant.cpp
        gen/llvm/GenLLVMConstant.h
        gen/GenEnv.cpp
        gen/GenEnv.h
        analyze.cpp
        analyze.h
        symTab.cpp
        symTab.h
        main.cpp
        parser.cpp
        parser.hpp
        scanner.cpp)

target_link_libraries( Pascal_Compiler ${LLVM_LINK_LIBRARIES} )
