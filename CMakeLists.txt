cmake_minimum_required(VERSION 3.26)
project(SuperMario1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(PTSD)
add_library(Framework ${PTSD_SRC_FILES} $<TARGET_OBJECTS:PracticalToolsForSimpleDesign>)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES}
        src/AnimatedCharacter.cpp
        include/AnimatedCharacter.h
        include/Character.h
        src/Character.cpp
        include/App.h
        include/BackgroundImage.h
        src/AppStartOne.cpp
        src/AppUpdate.cpp
        src/AppEnd.cpp
        include/MarioJump.h
        src/MarioJump.cpp
        include/QuestionTiles.h
        src/QuestionTiles.cpp
        include/TEXTS.h
        src/TEXTS.cpp
        include/Mario.h
        src/Mario.cpp
        include/Mushroom.h
        src/Mushroom.cpp
        include/Koopa.h
        src/Koopa.cpp
        include/YellowMush.h
        src/YellowMush.cpp
        src/App.cpp
        include/MenuPhase.h
        src/MenuPhase.cpp
        include/Phase.h
        src/Phase.cpp
        include/BeginningPhase.h
        src/BeginningPhase.cpp
        include/FirstWorldOne.h
        src/FirstWorldOne.cpp
        include/FirstWorldTwo.h
        src/FirstWorldTwo.cpp
        src/AppStartTwo.cpp
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE GA_RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Resources")
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE GA_RESOURCE_DIR="${CMAKE_INSTALL_PREFIX}/Resources")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${DEPENDENCY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Framework
        ${DEPENDENCY_LINK_LIBRARIES}
)

target_link_libraries(${PROJECT_NAME}
        SDL2::SDL2main
        Framework
)
