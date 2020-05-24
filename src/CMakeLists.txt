include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(ast)
include_directories(gen)
include_directories(gen/Env)


add_custom_command(
        OUTPUT scanner.cpp
        COMMAND flex -o scanner.cpp ${CMAKE_CURRENT_LIST_DIR}/pascal.l
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/pascal.l parser.hpp
)
add_custom_command(
        OUTPUT parser.cpp parser.hpp
        COMMAND bison -d -o parser.cpp ${CMAKE_CURRENT_LIST_DIR}/pascal.y
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
        gen/GenEnv.cpp
        gen/GenEnv.h
        main.cpp
        parser.cpp
        parser.hpp
        scanner.cpp)

target_link_libraries( Pascal_Compiler ${LLVM_LINK_LIBRARIES} )
