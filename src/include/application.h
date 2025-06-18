//
// Created by Shuai Zeng on 6/17/25.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include "config.h"
#include "channel.h"
#include <mutex>

class Application {
public:
    static void Init(int argc, char *argv[]);
    static Application &GetInstance();
    static void Destroy();
    static Config &GetConfig();
    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;
private:
    static Config config_;
    static Channel *channel_;
    static std::mutex mutex_;
    Application() = default;
    ~Application() = default;
};
#endif //APPLICATION_H
