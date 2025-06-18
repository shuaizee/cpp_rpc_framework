//
// Created by Shuai Zeng on 6/18/25.
//

#ifndef RPC_PROVIDER_H
#define RPC_PROVIDER_H
#include "google/protobuf/service.h"
#include <muduo/net/EventLoop.h>
#include <google/protobuf/descriptor.h>
#include <string>
#include <unordered_map>

class RpcProvider {
public:
    void NotifyService(google::protobuf::Service *service);
    ~RpcProvider();
    void Run();
private:
    muduo::net::EventLoop loop_;
    struct ServiceInfo {
        google::protobuf::Service *service;
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> methods;
    };
    std::unordered_map<std::string, ServiceInfo> service_map_;

    void OnConnection(const muduo::net::TcpConnectionPtr &conn);
    void OnMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer* buffer, muduo::Timestamp received_time);
    void SendRpcResponse(const muduo::net::TcpConnectionPtr &conn, const google::protobuf::Message *response);
};
#endif //RPC_PROVIDER_H
