# GetEnvValue-cpp

- Get environment value of OS.
    - It uses only Modern C++ (C++17).

- How to install 
    - Just include ```GetEnvValue-cpp.h```

- Case of obtaining ```PATH``` variable

```cpp
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
```

## License

- GetEnvValue-cpp is under MIT License.
- It's a part of jaytwo(j2) library.
- https://github.com/JayTwoLab/GetEnvValue-cpp


