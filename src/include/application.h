//
// Created by Shuai Zeng on 6/17/25.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include "config.h"
#include "channel.h"
#include <mutex>

class application {
public:
    static void Init(int argc, char *argv[]);
    static application &GetInstance();
    static void Destroy();
    static Config &GetConfig();
    application(const application &) = delete;
    application &operator=(const application &) = delete;
private:
    static Config config_;
    static application *app_;
    static std::mutex mutex_;
    application() = default;
    ~application() = default;
};
#endif //APPLICATION_H
