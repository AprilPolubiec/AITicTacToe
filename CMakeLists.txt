cmake_minimum_required(VERSION 3.10)

# set the project name
project(TicTacToe)
add_library(Board src/Board.cpp)
# add the executable
add_executable(TicTacToe src/TTT.cpp)

target_link_libraries(TicTacToe PUBLIC Board)