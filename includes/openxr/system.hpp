#pragma once

#include <iostream>

#include "thirdparties/openxr/openxr.h"

#include "graphicrequirement.hpp"

// TODO(an0rak): Add docs everywhere
// TODO(an0rak): Add unit tests for most of the code
class System {
public:
    System(const XrInstance &instance, GraphicRequirement &requirement);
    virtual ~System();

    const char* getName();
    bool isTrackingOrientation();
    bool isTrackingPosition();
    void printConfig(std::ostream &out);

private:
    XrSystemId systemId;
    XrSystemProperties properties;
};