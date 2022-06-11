cmake_minimum_required(VERSION 3.5)

project(VeryyyyyyCool2DGameCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VeryyyyyyCool2DGameCore
    src/main.cpp
    src/utilities.h
    src/window.h src/window.cpp
    src/game.h src/game.cpp
    src/gui/textbox.h src/gui/textbox.cpp
    src/gui/gui.h src/gui/gui.cpp
    src/assetmanager.h src/assetmanager.cpp
    src/eventmanager.h src/eventmanager.cpp
    src/states/state.h
    src/states/statemanager.h src/states/statemanager.cpp
    src/states/game_state.h src/states/game_state.cpp
    src/states/pause_state.h src/states/pause_state.cpp
    src/states/intro_state.h src/states/intro_state.cpp
    src/animator.h src/animator.cpp
    src/states/mainmenu_state.h src/states/mainmenu_state.cpp)

target_link_libraries(VeryyyyyyCool2DGameCore lua sfml-graphics sfml-window sfml-system sfml-audio)

FILE(COPY res/keys.cfg DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY res/fonts/FreeMono.otf DESTINATION "${CMAKE_BINARY_DIR}/fonts")
