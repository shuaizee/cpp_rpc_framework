cmake_minimum_required(VERSION 3.10)
project(cpp_rpc_framework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glog REQUIRED)
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_executable(${PROJECT_NAME}
        src/include/application.h
        src/include/config.h
        src/include/channel.h
        src/include/zookeeperclient.h
        src/include/logger.h
        src/include/controller.h
        src/include/rpc_provider.h
        src/Application.cpp
        src/Channel.cpp
        src/include/rpc_header.pb.h
        src/rpc_header.pb.cpp)
target_link_libraries(${PROJECT_NAME}
        glog::glog
        muduo_net
        muduo_base
)