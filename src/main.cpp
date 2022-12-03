#include <iostream>

#include <vector>
#include <string>

#include "openxr/extensioncatalog.hpp"
#include "openxr/instance.hpp"

#ifdef DEBUG
#define APP_NAME "Avatar [Debug]"
#else 
#define APP_NAME "Avatar"
#endif

#ifndef APP_VERSION // Release versions should define on command line this flag (unsigned int).
#define APP_VERSION 0
#endif

int main() {
    try {
        ExtensionCatalog extensionsCatalog;
        std::vector<const char*> enabledExtensions = extensionsCatalog.extractEnabledExtensions({
            XR_EXT_D3D12 // TODO: What if D3D12 unavailable ?
        });

        Instance appInstance(APP_NAME, APP_VERSION, enabledExtensions);
        System vrSystem = appInstance.getVRSystem();
        
    } catch (std::exception& ex) {
        std::cerr << "An error occured." << std::endl
            << ex.what() << std::endl;
        return 1;
    }

    return 0;
}