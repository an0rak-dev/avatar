#include "instance.hpp"

#include "exception.hpp"

Instance::Instance(const char* appName, unsigned int appVersion, std::vector<const char*> extensions) {
    XrInstanceCreateInfo creationInfo = { XR_TYPE_INSTANCE_CREATE_INFO };
    creationInfo.enabledExtensionCount = extensions.size();
    creationInfo.enabledExtensionNames = extensions.data();

    strncpy(creationInfo.applicationInfo.applicationName, appName, XR_MAX_APPLICATION_NAME_SIZE);
    creationInfo.applicationInfo.applicationVersion = 0;
    strncpy(creationInfo.applicationInfo.engineName, "Avatar", XR_MAX_ENGINE_NAME_SIZE);
    creationInfo.applicationInfo.engineVersion = 0;
    creationInfo.applicationInfo.apiVersion = XR_CURRENT_API_VERSION;

    XrResult result = XR_SUCCESS;
    result = xrCreateInstance(&creationInfo, &this->instance);
    XRASSERT(result, "Unable to create the OpenXR Instance");
}

Instance::~Instance() {
    xrDestroyInstance(this->instance);
}

System Instance::getVRSystem() const {
    return System(this->instance);
}