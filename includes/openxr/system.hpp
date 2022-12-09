#pragma once

#include "thirdparties/openxr/openxr.h"

#include "graphicrequirement.hpp"

class System {
public:
    System(const XrInstance &instance, GraphicRequirement &requirement);
    virtual ~System();


    XrSystemId systemId;
private:
    
};