cmake_minimum_required(VERSION 3.14)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)
FetchContent_MakeAvailable(sfml)

add_executable(GameOfLife
    src/main.cpp
    src/Cell.cpp
    src/GameBoard.cpp
    src/Boundary.cpp
    src/LiveRules.cpp
    src/Neighbor.cpp
)

target_link_libraries(GameOfLife
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

target_include_directories(GameOfLife
    PRIVATE
        ${sfml_SOURCE_DIR}/include
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_custom_command(TARGET GameOfLife POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE_DIR:sfml-graphics>/sfml-graphics-d-2.dll
            $<TARGET_FILE_DIR:sfml-window>/sfml-window-d-2.dll
            $<TARGET_FILE_DIR:sfml-system>/sfml-system-d-2.dll
            $<TARGET_FILE_DIR:GameOfLife>
    )
endif()