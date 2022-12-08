#pragma once

#include "thirdparties/openxr/openxr.h"

class GraphicRequirement {
    public:
        virtual bool validate(XrInstance instance, XrSystemId systemId) = 0;

    private:

};