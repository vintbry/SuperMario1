# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/bryant/super_mario_bros_20240328/PTSD/lib/sdl2_mixer"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/tmp"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src"
  "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
