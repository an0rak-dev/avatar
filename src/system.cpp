#include "system.hpp"

#include "exception.hpp"

System::System(const XrInstance &instance) {
    XrSystemGetInfo getSystemInfo = { XR_TYPE_SYSTEM_GET_INFO };
    getSystemInfo.formFactor = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY;
    XrResult result = xrGetSystem(instance, &getSystemInfo, &this->systemId);
    XRASSERT(result, "Unable to retrieve the VR system");
}

System::~System() {

}