#include <iostream>

#include <vector>
#include <string>

#include "openxr/extensioncatalog.hpp"
#include "openxr/instance.hpp"
#include "openxr/extensions/dx12requirement.hpp"

#ifdef DEBUG
#define APP_NAME "Avatar [Debug]"
#else 
#define APP_NAME "Avatar"
#endif

#ifndef APP_VERSION // Release versions should define on command line this flag (unsigned int).
#define APP_VERSION 0
#endif

// TODO(an0rak): Find a way to reduce build time by skipping untouched source files
int main() {
    try {
        ExtensionCatalog extensionsCatalog;
        std::vector<const char*> enabledExtensions = extensionsCatalog.extractEnabledExtensions({
            XR_EXT_D3D12
        });
        Dx12Requirement requirement({D3D_FEATURE_LEVEL_12_1,
                                    D3D_FEATURE_LEVEL_12_0,
                                    D3D_FEATURE_LEVEL_11_1,
                                    D3D_FEATURE_LEVEL_11_0});

        Instance appInstance(APP_NAME, APP_VERSION, enabledExtensions);
        System vrSystem = appInstance.getVRSystem(requirement);

        vrSystem.printConfig(std::cout);

    } catch (std::exception& ex) {
        std::cerr << "An error occured." << std::endl
            << ex.what() << std::endl;
        return 1;
    }

    return 0;
}