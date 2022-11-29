#include <iostream>
#include "extensioncatalog.hpp"

int main() {
    try {
        ExtensionCatalog extensionsCatalog;
    } catch (std::exception& ex) {
        std::cerr << "An error occured." << std::endl
            << ex.what() << std::endl;
        return 1;
    }

    return 0;
}