#include <iostream>

#include "thirdparties/openxr/openxr.h"

int main() {
    XrResult openXrStatus = XR_SUCCESS;
    uint32_t extensionsCount;
    openXrStatus = xrEnumerateInstanceExtensionProperties(nullptr, 0, &extensionsCount, nullptr);
    if (XR_FAILED(openXrStatus)) {
        throw std::exception("Failed to count extensions.");
    }
    return 0;
}