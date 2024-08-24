#ifndef GETENVVALUECPP_H
#define GETENVVALUECPP_H

#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <sstream>

#include <cstdlib>  // std::getenv

namespace j2 {

// Function to get environment variable value as an optional string
std::optional<std::string> getEnvVar(const std::string &key) {
    const char *val = std::getenv(key.c_str());
    if (val == nullptr) {
        return std::nullopt; // Environment variable not found
    } else {
        return std::string(val); // Environment variable found
    }
}


std::vector<std::string> splitPath(const std::string &path, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(path);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

} // namespace

#endif // GETENVVALUECPP_H
