#include <iostream>

#include <vector>
#include <string>

#include "openxr/extensioncatalog.hpp"
#include "openxr/instance.hpp"
#include "openxr/dx12requirement.hpp"

#ifdef DEBUG
#define APP_NAME "Avatar [Debug]"
#else 
#define APP_NAME "Avatar"
#endif

#ifndef APP_VERSION // Release versions should define on command line this flag (unsigned int).
#define APP_VERSION 0
#endif

// IDEA(an0rak): Find a way to reduce build time by skipping untouched source files
int main() {
    try {
        ExtensionCatalog extensionsCatalog;
        std::vector<const char*> enabledExtensions = extensionsCatalog.extractEnabledExtensions({ // TODO(an0rak): method names should start with an Uppercase
            XR_EXT_D3D12
        });
        Dx12Requirement requirement({D3D_FEATURE_LEVEL_12_1,
                                    D3D_FEATURE_LEVEL_12_0,
                                    D3D_FEATURE_LEVEL_11_1,
                                    D3D_FEATURE_LEVEL_11_0});

        Instance appInstance(APP_NAME, APP_VERSION, enabledExtensions);
        System vrSystem = appInstance.getVRSystem(requirement);

        std::cout << std::endl << " System configuration" << std::endl
                  << "============================" << std::endl
                  << "Name                 : " << vrSystem.getName() << std::endl
                  << "Image max ratio      : " << vrSystem.getImageRatio() << std::endl
                  << "Orientation tracking : " << (vrSystem.isTrackingOrientation() ? "yes" : "no") << std::endl
                  << "Position tracking    : " << (vrSystem.isTrackingPosition() ? "yes" : "no") << std::endl
                  << std::endl;

    } catch (std::exception& ex) {
        std::cerr << "An error occured." << std::endl
            << ex.what() << std::endl;
        return 1;
    }

    return 0;
}