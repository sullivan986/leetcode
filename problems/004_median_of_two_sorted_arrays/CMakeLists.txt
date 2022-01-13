SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 004_median_of_two_sorted_arrays
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(004_median_of_two_sorted_arrays PRIVATE benchmark::benchmark benchmark::benchmark_main)