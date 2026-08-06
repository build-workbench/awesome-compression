cmake_minimum_required(VERSION 3.16)

project(awesome_compression_examples LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
include(cmake/Dependencies.cmake)

add_library(example_common STATIC src/common.cpp)
target_include_directories(example_common PUBLIC src)

function(add_compression_example target source)
  add_executable(${target} ${source})
  target_link_libraries(${target} PRIVATE example_common ${ARGN})
  add_test(NAME ${target} COMMAND ${target} ${CMAKE_CURRENT_SOURCE_DIR}/data/sample.txt)
endfunction()

add_compression_example(zstd_example src/zstd_example.cpp libzstd_static)
add_compression_example(lz4_example src/lz4_example.cpp lz4_static)
add_compression_example(zlib_example src/zlib_example.cpp zlibstatic)
add_compression_example(brotli_example src/brotli_example.cpp brotlienc brotlidec brotlicommon)

if(LIBLZMA_FOUND)
  add_compression_example(lzma_example src/lzma_example.cpp LibLZMA::LibLZMA)
else()
  message(WARNING "LibLZMA was not found. lzma_example will not be built.")
endif()

if(AWESOME_COMPRESSION_ENABLE_BSC)
  add_compression_example(bsc_example src/bsc_example.cpp bsc::libbsc)
else()
  message(STATUS "BSC example is disabled. Reconfigure with -DAWESOME_COMPRESSION_ENABLE_BSC=ON to try it.")
endif()
