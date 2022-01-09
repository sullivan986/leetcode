SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 001_two_sum
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(001_two_sum PRIVATE benchmark::benchmark benchmark::benchmark_main)