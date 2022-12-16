#include "openxr/system.hpp"

#include <iostream>
#include "openxr/exception.hpp"

System::System(const XrInstance &instance, GraphicRequirement &requirement) {
    XrSystemGetInfo getSystemInfo = { XR_TYPE_SYSTEM_GET_INFO };
    getSystemInfo.formFactor = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY;
    XrResult result = xrGetSystem(instance, &getSystemInfo, &this->systemId);
    XRASSERT(result, "Unable to retrieve the VR system");
    if (!requirement.validate(instance, this->systemId)) { 
        throw Exception("Your system doesn't support the minimal graphic configuration required");
    }

    this->properties = { XR_TYPE_SYSTEM_PROPERTIES };
    result = xrGetSystemProperties(instance, this->systemId, &this->properties);
    XRASSERT(result, "Unable to access the system properties");
}

System::~System() {

}

const char* System::getName() {
    return this->properties.systemName;
}

bool System::isTrackingOrientation() {
    return this->properties.trackingProperties.orientationTracking;
}

bool System::isTrackingPosition() {
    return this->properties.trackingProperties.positionTracking;
}

void System::printConfig(std::ostream &out) {
    out << std::endl << " System configuration" << std::endl
        << "============================" << std::endl
        << "Name                 : " << this->getName() << std::endl
        << "Orientation tracking : " << (this->isTrackingOrientation() ? "yes" : "no") << std::endl
        << "Position tracking    : " << (this->isTrackingPosition() ? "yes" : "no") << std::endl
        << std::endl;
}