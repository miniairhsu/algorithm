cmake_minimum_required( VERSION 3.8 )
project( mine_layout)

set( CMAKE_CXX_STANDARD 20 )

set( public_include_dir ${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_subdirectory(sln)

add_executable( mine_layout src/main.cpp )
target_link_libraries(mine_layout mine_layout_solution)
target_include_directories(mine_layout PUBLIC ${public_include_dir})

