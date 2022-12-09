#pragma once

#include <string>
#include <vector>
#include "thirdparties/openxr/openxr.h"

#include "graphicrequirement.hpp"
#include "system.hpp"

class Instance {
public:
    Instance(const char* appName, unsigned int appVersion, std::vector<const char*> extensions);
    virtual ~Instance();

    System getVRSystem(GraphicRequirement& requirement) const;


    XrInstance instance;    
private:
    
};