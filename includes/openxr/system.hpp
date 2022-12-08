#pragma once

#include "thirdparties/openxr/openxr.h"

class System {
public:
    System(const XrInstance &instance);
    virtual ~System();


    XrSystemId systemId;
private:
    
};