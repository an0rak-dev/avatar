#pragma once

#include "thirdparties/openxr/openxr.h"

#include "graphicrequirement.hpp"

// TODO(an0rak): Add docs everywhere
// TODO(an0rak): Add unit tests for most of the code
class System {
public:
    System(const XrInstance &instance, GraphicRequirement &requirement);
    virtual ~System();

    const char* getName();
    float getImageRatio();
    bool isTrackingOrientation();
    bool isTrackingPosition();

private:
    XrSystemId systemId;
    XrSystemProperties properties;
};