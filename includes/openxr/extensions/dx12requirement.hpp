#pragma once

#define XR_USE_GRAPHICS_API_D3D12

#include <vector>
#include <d3d12.h>
#include "openxr/graphicrequirement.hpp"
#include "openxr/thirdparties/openxr/openxr_platform.h"


class Dx12Requirement : public GraphicRequirement {
    public:
        Dx12Requirement(std::vector<D3D_FEATURE_LEVEL> levels);

        ~Dx12Requirement();

        bool validate(XrInstance instance, XrSystemId systemId);

    private:
        std::vector<D3D_FEATURE_LEVEL> supportedLevels;
};
