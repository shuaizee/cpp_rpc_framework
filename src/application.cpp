//
// Created by Shuai Zeng on 6/18/25.
//


#include "application.h"
#include <cstdlib>
#include <unistd.h>

Config application::config_;
std::mutex application::mutex_;
application* application::app_ = nullptr;

void application::Init(const int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: command -i [config_file]" << std::endl;
        exit(EXIT_FAILURE);
    }

    int opt;
    std::string config_file;
    while ((opt = getopt(argc, argv, "i:")) != -1) {
        if (opt == 'i') {
            config_file = optarg;
        } else {
            std::cerr << "Usage: command -i [config_file]" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    config_.load_config(config_file);
}

application &application::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (app_ == nullptr) {
        app_ = new application();
        atexit(application::Destroy);
    }
    return *app_;
}

void application::Destroy() {
    if (app_ != nullptr) {
        delete app_;
        app_ = nullptr;
    }
}

Config &application::GetConfig() {
    return config_;
}
