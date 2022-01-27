import sys
import os

if __name__ == "__main__":
    a = 0
    for i in os.listdir('problems/'):
        if i[0:3] != "CMa":
            if int(i[0:3]) > a:
                a = int(i[0:3])
    a+=1
    str_s = "{:0>3}_".format(a) + sys.argv[1].replace("-","_")
    
    os.mkdir("./problems/{}".format(str_s))

    f = open("./problems/{}/main.cpp".format(str_s), "w+")
    f.close()
    f = open("./problems/{}/CMakeLists.txt".format(str_s), "w+")
    f.write('SET(CMAKE_CXX_FLAGS ${{CMAKE_CXX_FLAGS}} "-pthread")\n\nadd_executable( {}\n    main.cpp\n)\n\nfind_package(benchmark CONFIG REQUIRED)\ntarget_link_libraries({} PRIVATE benchmark::benchmark benchmark::benchmark_main)'.format(str_s, str_s))
    f.close()
    f = open("./problems/CMakeLists.txt", "a+")
    f.write("add_subdirectory({})\n".format(str_s))
    f.close()
