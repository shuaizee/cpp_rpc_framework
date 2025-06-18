//
// Created by Shuai Zeng on 6/18/25.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <google/protobuf/service.h>
#include <string>

class Controller final : public google::protobuf::RpcController {
public:
    Controller();
    void Reset() override;
    [[nodiscard]] bool Failed() const override;
    [[nodiscard]] std::string ErrorText() const override;
    void SetFailed(const std::string &reason) override;
private:
    bool failed_;
    std::string error_text_;
    // TODO
    void StartCancel() override;
    [[nodiscard]] bool IsCanceled() const override;
    void NotifyOnCancel(google::protobuf::Closure *callback) override;
};
#endif //CONTROLLER_H
