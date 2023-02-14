extern "C" { 
    #include <../libs/tinyPTC/src/tinyptc.h>
}

#include <memory>
#include <cstdint>
#include <iostream>
#include <exception>
#include "main.hpp"
#include "systems/Render.hpp"
/*----------------------------------------------------------------------------------------*/

int main() {
    try {
        const SalsaEngine::RenderSystem_t renderSystem { "Mi primer motor owo", 640U, 360U };

        while(renderSystem.Update());
    }
    catch (...) {
        std::cout << "Exception captured\n";
    }

    return 0;
}