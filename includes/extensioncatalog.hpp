#pragma once

#include "thirdparties/openxr/openxr.h"
#include <vector>

class ExtensionCatalog {
    public:
        ExtensionCatalog();
        virtual ~ExtensionCatalog();

    private:
        std::vector<XrExtensionProperties> availableExtensions;
};