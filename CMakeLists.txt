cmake_minimum_required(VERSION 3.10)

# Set the project name
project(tictactoe)

# Find the Qt5 libraries
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Add the executable
add_executable(tictactoe ai.cpp main.cpp mainmenu.cpp mainwindow.cpp sec_player_login.cpp tic_tac_toe.cpp tic_tac_toe_ai.cpp tic_tac_toe_rand.cpp )  # Replace with details

# Link the Qt5 libraries
target_link_libraries(tictactoe Qt5::Widgets)

