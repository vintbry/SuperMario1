# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/bryant/super_mario_bros_20240328/PTSD/lib/glm"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-build"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-subbuild/glm-populate-prefix"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-subbuild/glm-populate-prefix/tmp"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-subbuild/glm-populate-prefix/src"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/bryant/super_mario_bros_20240328/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
