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

#define XR_USE_GRAPHICS_API_D3D12
#include <d3d12.h>

#include "openxr/thirdparties/openxr/openxr.h"
#include "openxr/thirdparties/openxr/openxr_platform.h"

int main() {
    try {
        ExtensionCatalog extensionsCatalog;
        std::vector<const char*> enabledExtensions = extensionsCatalog.extractEnabledExtensions({
            XR_EXT_D3D12 // TODO: What if D3D12 unavailable ?
        });

        Instance appInstance(APP_NAME, APP_VERSION, enabledExtensions);
        System vrSystem = appInstance.getVRSystem();
        
        XrResult result = XR_SUCCESS;
        XrGraphicsRequirementsD3D12KHR requirements = {XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR};
        
        // Extension functions needs to be dynamically searched at runtime using xrGetInstanceProcAddr
        // because they're only defined in the loader .dll and the current system.
        PFN_xrGetD3D12GraphicsRequirementsKHR xrGetD3D12GraphicsRequirementsKHR = nullptr;
        result = xrGetInstanceProcAddr(appInstance.instance, "xrGetD3D12GraphicsRequirementsKHR", (PFN_xrVoidFunction*) &xrGetD3D12GraphicsRequirementsKHR);
        result = xrGetD3D12GraphicsRequirementsKHR(appInstance.instance, vrSystem.systemId, &requirements);
    } catch (std::exception& ex) {
        std::cerr << "An error occured." << std::endl
            << ex.what() << std::endl;
        return 1;
    }

    return 0;
}