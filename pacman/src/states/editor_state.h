#pragma once

#include "states/state.h"
#include "entity/events.h"
#include "level.h"
#include "common.h"
#include "entity/rendering_system.h"
#include "entity/animation_system.h"
#include "ui.h"

#include <array>
#include <cstdint>
#include <vector>

#include <robinhood/robinhood.h>

namespace pac
{
/*!
 * \brief The EditorState is run when the user is in the level editor
 */
class EditorState : public State
{
private:
    /*!
     * \brief The EMode enum describes the current editor stat
     */
    enum class EMode
    {
        TilePlacement,
        EntityPlacement
    };

    /* Level we are editing */
    Level m_level{};

    /* All positions on the map can hold a single entity */
    robin_hood::unordered_map<glm::ivec2, std::string, detail::custom_ivec2_hash> m_entities{};

    /* Active Systems */
    std::vector<std::unique_ptr<System>> m_systems{};

    /* Entities availalbe to spawn */
    std::vector<std::string> m_entity_prototypes{};

    /* Level Name */
    std::array<char, 64> m_level_name{};

    /* Current Level Size */
    glm::ivec2 m_size = {28, 36};

    /* Current Cursor Tile */
    glm::ivec2 m_hovered_tile = {0, 0};

    /* Current editor mode */
    EMode m_editor_mode = EMode::TilePlacement;

    /* Current tile tex */
    unsigned m_current_tex = 0u;

    /* Current entity to place */
    std::string m_current_entity{};

    /* ID of Entity that is about to be spawned */
    entt::entity m_entity_about_to_spawn = entt::null;

    /* Overlay */
    TextureID m_overlay = {};

    /* Tileset selector UI */
    ui::TilesetSelector m_tileselect_ui{};

    /* Animation Editor */
    ui::AnimationEditor m_anim_editor{};

public:
    using State::State;

    void on_enter() override;

    void on_exit() override;

    bool update(float dt) override;

    bool draw() override;

    /*!
     * \brief recieve_key accepts input actions and updates the editor state based on that
     * \param input is the event data
     */
    void recieve_key(const EvInput& input);

    /*!
     * \brief recieve_mouse accepts mouse input and updates the currently selected editor tile
     * \param input is the event data
     */
    void recieve_mouse(const EvMouseMove& input);

    void set_selection(unsigned selection);

private:
    /*!
     * \brief draw_ui draws the editor UI
     * \param dt is the delta time
     */
    void draw_ui(float dt);

    /*!
     * \brief load_get_entities is called after loading a level to store the current loaded entities in the entity map
     */
    void load_get_entities();

    /*!
     * \brief load_entity_prototypes searches the entity folder for available Entity prototypes so we can choose between them
     */
    void load_entity_prototypes();

    /*!
     * \brief spawn_entity spawns the current entity at the currently hovered location (tile) if possible
     */
    void spawn_entity();

    /*!
     * \brief remove_entity removes entity at the currently hovered tile position if any
     */
    void remove_entity();
};
}  // namespace pac
