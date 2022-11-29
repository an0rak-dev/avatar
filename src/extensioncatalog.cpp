#include "extensioncatalog.hpp"

#include "exception.hpp"

#define EXTENSION_MAX_SIZE 64

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

std::vector<const char*> ExtensionCatalog::extractEnabledExtensions(std::vector<const char*> wantedExtensions) const {
    std::vector<const char*> result = {};
    for (int i=0; i < wantedExtensions.size(); i++) {
        for (int j=0; j < this->availableExtensions.size(); j++) {
            if (0 == strncmp(wantedExtensions.at(i), this->availableExtensions.at(j).extensionName, EXTENSION_MAX_SIZE)) {
                result.push_back(wantedExtensions.at(i));
                break;
            }
        }
    }
    return result;
}