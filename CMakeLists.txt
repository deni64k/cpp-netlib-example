cmake_minimum_required(VERSION 2.8)
project(draft)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

include(ExternalProject)
set_directory_properties(PROPERTIES EP_PREFIX ${PROJECT_BINARY_DIR}/ThirdParty)
ExternalProject_Add(cpp-netlib
  GIT_REPOSITORY "https://github.com/cpp-netlib/cpp-netlib.git"
  CMAKE_ARGS -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER} -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX:PATH=${PROJECT_BINARY_DIR}/cpp-netlib -DCPP-NETLIB_BUILD_SINGLE_LIB:BOOL=OFF -DCPP-NETLIB_BUILD_TESTS:BOOL=OFF -DCPP-NETLIB_BUILD_EXAMPLES:BOOL=OFF
  INSTALL_COMMAND ""
  INSTALL_DIR "${PROJECT_BINARY_DIR}/cpp-netlib"
)
ExternalProject_Get_Property(cpp-netlib source_dir)
ExternalProject_Get_Property(cpp-netlib binary_dir)
set(cpp-netlib_INCLUDE_DIRS "${source_dir}/config/src" "${source_dir}/uri/src" "${source_dir}/logging/src" "${source_dir}/http/src" "${source_dir}")
set(cpp-netlib_LIBRARY_DIRS "${binary_dir}/config/src" "${binary_dir}/uri/src" "${binary_dir}/logging/src" "${binary_dir}/http/src" "${binary_dir}")
set(cpp-netlib_LIBRARIES "network-uri" "network-http-v2-client")

find_package(Boost 1.55 COMPONENTS "system" "thread" REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ICU)

set (EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set (LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

add_subdirectory("src")
