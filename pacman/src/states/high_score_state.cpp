#include "high_score_state.h"
#include "state_manager.h"
#include "config.h"
#include "input.h"

#include <fstream>

#include <imgui/imgui.h>
#include <GLFW/glfw3.h>

namespace pac
{
void HighScoreState::on_enter()
{
    m_splash_texture = get_renderer().load_texture("res/hiscore_screen.png");

    input::InputState hs_input_state(true);
    hs_input_state.set_binding(GLFW_KEY_ESCAPE, [this] { m_context.state_manager->pop(); });
    input::get_input().push(std::move(hs_input_state));

    m_entries = load_high_score_entries_from_file();
}

void HighScoreState::on_exit() { input::get_input().pop(); }

bool HighScoreState::update(float dt)
{
    /* Position high score table properly */
    ImGui::SetNextWindowPos({SCREEN_W / 2.f, SCREEN_H / 2.f + 60.f}, 0, {.5f, .5f});
    ImGui::SetNextWindowSize({400.f, 500.f});
    ImGui::Begin("High Score", nullptr, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

    /* Set up a 3 column high score table */
    ImGui::Columns(3, "ScoreColumns", false);
    ImGui::SetColumnWidth(0, 25.f);
    ImGui::SetColumnWidth(1, 275.f);

    /* Print score for each element */
    int i = 1;
    for (const auto& e : m_entries)
    {
        ImGui::Text("%d", i++);
        ImGui::NextColumn();
        ImGui::Text("%s", e.name.c_str());
        ImGui::NextColumn();
        ImGui::Text("%d", e.score);
        ImGui::NextColumn();
        ImGui::Separator();
    }

    /* Reset columns and add a back buton */
    ImGui::Columns();
    if (ImGui::Button("Back"))
    {
        m_context.state_manager->pop();
    }

    ImGui::End();
    return false;
}

bool HighScoreState::draw()
{
    get_renderer().draw({{SCREEN_W / 2.f, SCREEN_H / 2.f}, glm::vec2(SCREEN_W, SCREEN_H), {1.f, 1.f, 1.f}, m_splash_texture});
    return false;
}

}  // namespace pac