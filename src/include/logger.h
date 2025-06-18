//
// Created by Shuai Zeng on 6/17/25.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <glog/logging.h>

class Logger {
public:
    explicit Logger(const char *argv0) {
        google::InitGoogleLogging(argv0);
        FLAGS_colorlogtostderr = true;
        FLAGS_logtostderr = true;
    }

    ~Logger() {
        google::ShutdownGoogleLogging();
    }

    static void Info(const std::string &message) {
        LOG(INFO) << message;
    }

    static void Warning(const std::string &message) {
        LOG(WARNING) << message;
    }

    static void Error(const std::string &message) {
        LOG(ERROR) << message;
    }

    static void Fatal(const std::string &message) {
        LOG(FATAL) << message;
    }

    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
};

#endif //LOGGER_H
