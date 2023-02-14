#pragma once
#include <iostream>
#include <cstdint>
#include <memory>
/*----------------------------------------------------------------------------------------*/


namespace SalsaEngine {

// tells the compiler that EM is a struct. No more details are necessary
// because RenderSystem only stores a reference to EM.
struct EntityManager_t; 

struct RenderSystem_t {
    explicit RenderSystem_t(
        std::string_view gameTitle, 
        uint32_t screenWidth, uint32_t screenHeight, 
        EntityManager_t& entityManager
    );
    
    ~RenderSystem_t();

    bool Update() const;
    void DrawAllEntities() const;    

    // Constants // 
    static constexpr uint32_t kR = 0x00FF0000U;                      // red   hex
    static constexpr uint32_t kG = 0x0000FF00U;                      // green hex
    static constexpr uint32_t kB = 0x000000FFU;                      // blue  hex
    static constexpr uint32_t kW = 0xFFFFFFFFU;                      // white hex

    static constexpr const uint32_t kSPRITE_TEST[8*8] = {
        kG, kG, kG, kG, kG, kG, kG, kG,
        kG, kB, kR, kR, kR, kB, kB, kG,
        kG, kB, kR, kW, kW, kR, kB, kG,
        kG, kB, kR, kR, kR, kR, kB, kG,
        kG, kB, kR, kR, kR, kR, kB, kG,
        kG, kB, kR, kR, kR, kR, kB, kG,
        kG, kB, kR, kB, kB, kR, kB, kG,
        kG, kG, kG, kG, kG, kG, kG, kG
    };

private:
    const uint32_t _screenWidth { 0 }, _screenHeight { 0 }, _screenResolution { 0 };
    std::unique_ptr<uint32_t[]> _frameBuffer { nullptr };
    EntityManager_t& _entityManager;

};

} // namespace SalsaGameEngine
