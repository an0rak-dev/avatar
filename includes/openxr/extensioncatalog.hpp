#pragma once

#include "openxr/thirdparties/openxr/openxr.h"
#include <string>
#include <vector>

#define XR_EXT_D3D12 "XR_KHR_D3D12_enable"

class ExtensionCatalog {
    public:
        ExtensionCatalog();
        virtual ~ExtensionCatalog();
        std::vector<const char*> extractEnabledExtensions(std::vector<const char*> wantedExtensions) const;

    private:
        std::vector<XrExtensionProperties> availableExtensions;
};