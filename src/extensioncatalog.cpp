#include "extensioncatalog.hpp"

#include "exception.hpp"

ExtensionCatalog::ExtensionCatalog() {
    XrResult openXrStatus = XR_SUCCESS;
    uint32_t extensionsCount = 0;
    
    openXrStatus = xrEnumerateInstanceExtensionProperties(nullptr, 0, &extensionsCount, nullptr);
    XRASSERT(openXrStatus, "Failed to count extensions");
    this->availableExtensions = std::vector<XrExtensionProperties>(extensionsCount, {XR_TYPE_EXTENSION_PROPERTIES});
    openXrStatus = xrEnumerateInstanceExtensionProperties(nullptr, extensionsCount, &extensionsCount, this->availableExtensions.data());
    XRASSERT(openXrStatus, "Failed to list available extensions");
}

ExtensionCatalog::~ExtensionCatalog() {

}