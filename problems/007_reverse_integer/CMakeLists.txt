SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 007_reverse_integer
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(007_reverse_integer PRIVATE benchmark::benchmark benchmark::benchmark_main)