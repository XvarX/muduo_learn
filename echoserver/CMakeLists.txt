add_executable(myechoserver main.cpp)

# target_include_directories(myechoserver PRIVATE /home/xvar/space/learnspace/cpp/muduo_learn/build/release-install-cpp11/include)
# target_link_directories(myechoserver PRIVATE /home/xvar/space/learnspace/cpp/muduo_learn/build/release-install-cpp11/lib)

target_link_libraries(myechoserver muduo_net muduo_base pthread)

