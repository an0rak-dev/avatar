#pragma once

#include <string>
#include <vector>
#include "thirdparties/openxr/openxr.h"

class Instance {
public:
    Instance(const char* appName, unsigned int appVersion, std::vector<const char*> extensions);
    virtual ~Instance();

private:
    XrInstance instance;
};