//
// Created by Shuai Zeng on 6/17/25.
//

#ifndef ZOOKEEPERCLIENT_H
#define ZOOKEEPERCLIENT_H
#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>

class ZookeeperClient {
public:
    ZookeeperClient();
    ~ZookeeperClient();
    void Start();
    void Create(const std::string &path, const std::string &data, int datalen, int state = 0);
    std::string Get(const std::string &path);
private:
    zhandle_t *zh;
};
#endif //ZOOKEEPERCLIENT_H
