# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/PTSD/lib/glew"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-build"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-subbuild/glew-populate-prefix"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-subbuild/glew-populate-prefix/tmp"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-subbuild/glew-populate-prefix/src/glew-populate-stamp"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-subbuild/glew-populate-prefix/src"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-subbuild/glew-populate-prefix/src/glew-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-subbuild/glew-populate-prefix/src/glew-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/glew-subbuild/glew-populate-prefix/src/glew-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()