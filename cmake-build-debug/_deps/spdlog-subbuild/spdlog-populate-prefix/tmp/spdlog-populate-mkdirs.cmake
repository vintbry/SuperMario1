# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/bryant/SuperMarioBros_10May2024/PTSD/lib/spdlog"
  "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-build"
  "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix"
  "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/tmp"
  "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
  "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src"
  "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/bryant/SuperMarioBros_10May2024/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
