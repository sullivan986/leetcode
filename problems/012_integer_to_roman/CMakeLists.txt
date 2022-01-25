SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 012_integer_to_roman
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(012_integer_to_roman PRIVATE benchmark::benchmark benchmark::benchmark_main)