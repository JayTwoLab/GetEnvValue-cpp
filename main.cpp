
#include "GetEnvValue-cpp.h"

int main() {

    // get PATH
    std::string envVarName = "PATH";
    std::optional<std::string> envVarValue = j2::getEnvVar(envVarName);
    if (!envVarValue) {
        std::cout << envVarName << " is not set.\n";
        return 0;
    }

#ifdef _WIN32
    char delimiter = ';';
#elif __APPLE__
    char delimiter = ':';
#elif __linux__
    char delimiter = ':';
#else
    std::cout << "Unknown platform." << std::endl;
    return 0;
#endif

    std::string path = envVarValue.value();
    std::vector<std::string> directories = j2::splitPath(path, delimiter);
    for (const auto &dir : directories) {
        std::cout << dir << std::endl;
    }

    return 0;
}
