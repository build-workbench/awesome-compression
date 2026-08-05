include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

set(ZSTD_BUILD_PROGRAMS OFF CACHE BOOL "" FORCE)
set(ZSTD_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ZSTD_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(ZSTD_BUILD_STATIC ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  zstd
  GIT_REPOSITORY https://github.com/facebook/zstd.git
  GIT_TAG v1.5.6
  SOURCE_SUBDIR build/cmake
)

set(LZ4_BUILD_CLI OFF CACHE BOOL "" FORCE)
set(LZ4_BUILD_LEGACY_LZ4C OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  lz4
  GIT_REPOSITORY https://github.com/lz4/lz4.git
  GIT_TAG v1.9.4
  SOURCE_SUBDIR build/cmake
)

set(ZLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  zlib
  GIT_REPOSITORY https://github.com/madler/zlib.git
  GIT_TAG v1.3.1
)

set(BROTLI_DISABLE_TESTS ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  brotli
  GIT_REPOSITORY https://github.com/google/brotli.git
  GIT_TAG v1.1.0
)

FetchContent_MakeAvailable(zstd lz4 zlib brotli)

find_package(LibLZMA QUIET)

option(AWESOME_COMPRESSION_ENABLE_BSC "Build the optional BSC example" OFF)
if(AWESOME_COMPRESSION_ENABLE_BSC)
  FetchContent_Declare(
    libbsc
    GIT_REPOSITORY https://github.com/IlyaGrebnov/libbsc.git
    GIT_TAG master
  )
  FetchContent_MakeAvailable(libbsc)
  # Upstream libbsc never exposes its header include directory, so consumers
  # linking bsc::libbsc cannot resolve #include <libbsc.h>. Add it here.
  target_include_directories(libbsc PUBLIC ${libbsc_SOURCE_DIR}/libbsc)
endif()
