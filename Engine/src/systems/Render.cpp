extern "C" { 
    #include <../libs/tinyPTC/src/tinyptc.h>
}
#include "systems/Render.hpp"


namespace SalsaEngine {
// RAII //
RenderSystem_t::RenderSystem_t(std::string_view gameTitle, uint32_t screenWidth, uint32_t screenHeight)
    : _screenWidth { screenWidth }, _screenHeight { screenHeight }, _screenResolution { _screenWidth * _screenHeight },
      _frameBuffer { std::make_unique<uint32_t[]>(_screenResolution) }
{
    ptc_open(gameTitle.data(), screenWidth, screenHeight);
}

RenderSystem_t::~RenderSystem_t() { ptc_close(); }
// RAII //


// Render Game

// void RenderSystem_t::DrawSprite() const {

//     uint32_t* screenPtr = screen.get();
//     const uint32_t* spritePtr = kSPRITE_TEST;

//     for (uint32_t i{}; i < 8; ++i) {
//         for (uint32_t j{}; j < 8; ++j) {

//             *screenPtr = *spritePtr;

//             ++screenPtr;
//             ++spritePtr;
//         }

//         screenPtr += kSCREEN_WIDTH - 8;
//     }
// }

bool RenderSystem_t::Update() const {

    auto screen = _frameBuffer.get();

    for (uint32_t pixel=0; pixel < _screenResolution; ++pixel) {
        screen[pixel] = kB;
    }

    ptc_update(screen);

    return !ptc_process_events();
}




    
} // namespace SalsaEngine
