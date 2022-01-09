SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 002_add_two_numbers
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(002_add_two_numbers PRIVATE benchmark::benchmark benchmark::benchmark_main)