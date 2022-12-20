#include "openxr/extensions/dx12requirement.hpp"

Dx12Requirement::Dx12Requirement(std::vector<D3D_FEATURE_LEVEL> levels) : supportedLevels(levels) {}

Dx12Requirement::~Dx12Requirement() {}

bool Dx12Requirement::validate(XrInstance instance, XrSystemId systemId) {
    XrResult result = XR_SUCCESS;    
    // Extension functions needs to be dynamically searched at runtime using xrGetInstanceProcAddr
    // because they're only defined in the loader .dll and the current system.
    XrGraphicsRequirementsD3D12KHR requirements = {XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR};
    PFN_xrGetD3D12GraphicsRequirementsKHR xrGetD3D12GraphicsRequirementsKHR = nullptr;
    result = xrGetInstanceProcAddr(instance, "xrGetD3D12GraphicsRequirementsKHR", (PFN_xrVoidFunction*) &xrGetD3D12GraphicsRequirementsKHR);
    result = xrGetD3D12GraphicsRequirementsKHR(instance, systemId, &requirements);
    for (int i=0; i < this->supportedLevels.size(); i++) {
        if (this->supportedLevels.at(i) >= requirements.minFeatureLevel) {
            return true;
        }
    }
    return false;
}