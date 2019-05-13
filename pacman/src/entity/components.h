#pragma once

#include "input/input.h"
#include "rendering/renderer.h"

#include <glm/vec2.hpp>
#include <sol/function.hpp>
#include <robinhood/robinhood.h>

namespace pac
{
/* Position Component */
struct CPosition
{
    /* Grid position */
    glm::ivec2 position{};
};

/* Movement component */
struct CMovement
{
    /* Current movement direction */
    glm::ivec2 current_direction{};

    /* Desired movement direction */
    glm::ivec2 desired_direction{};

    /* Movement speed in tiles per second */
    float speed = 1.f;

    /* Current move progress */
    float progress = 0.f;
};

/* Animated sprite component */
struct CAnimationSprite
{
    /* Available animations (accessible by hash of their name */
    robin_hood::unordered_map<std::string, TextureID> available_animations{};

    /* Color tint */
    glm::vec3 tint = glm::vec3(1.f);

    /* The active animation sprite (from the map) */
    TextureID active_animation{};

    /* Current animation time */
    float animation_timer = 0.f;

    /* Number of FPS for animation */
    float fps = 24.f;
};

struct CSprite
{
    /* Sprite ID */
    TextureID sprite{};

    /* Color tint */
    glm::vec3 tint = glm::vec3(1.f);
};

/* Player component (Pacman) */
struct CPlayer
{
    /* Number of lives */
    int32_t lives = 3;

    /* Current score */
    int32_t score = 0;
};

/* Input Component */
struct CInput
{
    robin_hood::unordered_map<Action, sol::function> actions{};
};

/* Pickup component represents a pickuppable */
struct CPickup
{
    /* Score when picking up */
    int score = 50;

    /* Other effects */
};

/* Tag component that represents a collideable thing */
struct CCollision
{
};

}  // namespace pac
