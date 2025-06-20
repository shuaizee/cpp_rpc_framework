//
// Created by Shuai Zeng on 6/17/25.
//

#ifndef CHANNEL_H
#define CHANNEL_H
#include <google/protobuf/service.h>
#include "zookeeperclient.h"

class channel : public google::protobuf::RpcChannel {
public:
    explicit channel(bool connected = false);
    ~channel() override;
    void CallMethod(const google::protobuf::MethodDescriptor *method,
                    google::protobuf::RpcController *controller,
                    const google::protobuf::Message *request,
                    google::protobuf::Message *response,
                    google::protobuf::Closure *done) override;

private:
    int client_fd;
    std::string service_name;
    std::string method_name;
    std::string m_ip;
    uint16_t m_port;
    int m_idx;
    bool Connect(const char *ip, uint16_t port);
    std::string QueryServiceHost(ZookeeperClient *zookeeper_client, const std::string &service_name,
                                 const std::string &method_name, int &idx);
};
#endif //CHANNEL_H
