//
// Created by Shuai Zeng on 6/17/25.
//

#ifndef CONFIG_H
#define CONFIG_H
#include <unordered_map>
#include <string>

class Config {
public:
    void load_config(const std::string&);
    std::string get_value(const std::string&);
private:
    std::unordered_map<std::string, std::string> config_map;
};
#endif //CONFIG_H
