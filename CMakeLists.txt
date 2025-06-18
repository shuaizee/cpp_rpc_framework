cmake_minimum_required(VERSION 3.10)
project(cpp_rpc_framework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glog REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
add_executable(${PROJECT_NAME} src/main.cpp
        src/include/application.h
        src/include/config.h
        src/include/channel.h
        src/include/zookeeperclient.h
        src/main.cpp
        src/include/zookeeperclient.h
        src/include/logger.h)
target_link_libraries(${PROJECT_NAME} glog::glog) 