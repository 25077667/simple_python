set(INCLUDE_DIR ${INCLUDE_DIR}  ${CMAKE_SOURCE_DIR}/include)

set(MODULE_NAME simple_python_lib)

# Add the source files
set(SRC ${SRC} 
    Object.cpp
    Integer.cpp
    Str.cpp
    List.cpp
    Tuple.cpp
    Dict.cpp
    Pair.cpp
)

include_directories (${INCLUDE_DIR})
add_library(${MODULE_NAME} STATIC ${SRC})
