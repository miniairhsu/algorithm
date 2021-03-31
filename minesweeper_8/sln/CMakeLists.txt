project( mine_layout_solution C)

add_library( mine_layout_solution solution.c )
target_compile_features(mine_layout_solution PUBLIC c_std_11)
target_include_directories(mine_layout_solution PUBLIC ${public_include_dir})
