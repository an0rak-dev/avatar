#include "openxr/system.hpp"

#include "openxr/exception.hpp"

System::System(const XrInstance &instance, GraphicRequirement &requirement) {
    XrSystemGetInfo getSystemInfo = { XR_TYPE_SYSTEM_GET_INFO };
    getSystemInfo.formFactor = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY;
    XrResult result = xrGetSystem(instance, &getSystemInfo, &this->systemId);
    XRASSERT(result, "Unable to retrieve the VR system");
    if (!requirement.validate(instance, this->systemId)) { 
        throw Exception("Your system doesn't support the minimal graphic configuration required");
    }
}

System::~System() {

}