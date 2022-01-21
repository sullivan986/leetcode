SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 008_string_to_integer_atoi
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(008_string_to_integer_atoi PRIVATE benchmark::benchmark benchmark::benchmark_main)