#include <stdexcept>
#include <cstdlib>
#include "application.h"

int main(int argc, const char *argv[]) {

    VulkanApplication app;
    try {
        app.run();
    } catch(const std::exception &e) {
        std::cerr << e.what() <<  std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
