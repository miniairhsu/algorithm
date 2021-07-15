cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_C_COMPILER "gcc")
set(GSL_PATH "/home/swlib/gsl")
project(STATE_MACHINE VERSION "1.0" LANGUAGES C)
configure_file(version.h.in version.h)
add_executable(${PROJECT_NAME} main.c)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_subdirectory(queue)
add_subdirectory(st)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC queue)
target_include_directories(${PROJECT_NAME} PUBLIC st)
target_include_directories(${PROJECT_NAME} PUBLIC ${GSL_PATH}/include)
target_link_directories(${PROJECT_NAME} PRIVATE queue)
target_link_directories(${PROJECT_NAME} PRIVATE st)
target_link_directories(${PROJECT_NAME} PRIVATE ${GSL_PATH}/lib)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
target_link_libraries(${PROJECT_NAME} queue_util)
target_link_libraries(${PROJECT_NAME} st_util)
target_link_libraries(${PROJECT_NAME} gsl gslcblas)





