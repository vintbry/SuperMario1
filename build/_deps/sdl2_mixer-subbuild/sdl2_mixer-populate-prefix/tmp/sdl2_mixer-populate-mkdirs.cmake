# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/PTSD/lib/sdl2_mixer"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-build"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/tmp"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/build/_deps/sdl2_mixer-subbuild/sdl2_mixer-populate-prefix/src/sdl2_mixer-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()