set(MY_PROJECT_NAME first-project)
set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.22.1)
project(${MY_PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../out)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
set(SRC_FILES src/main.cpp src/game.cpp src/player.cpp src/util.cpp src/eventListener.cpp)

add_executable(${MY_PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${MY_PROJECT_NAME} PUBLIC sfml-graphics)
target_link_libraries(${MY_PROJECT_NAME} PUBLIC sfml-window)
target_link_libraries(${MY_PROJECT_NAME} PUBLIC sfml-system)
