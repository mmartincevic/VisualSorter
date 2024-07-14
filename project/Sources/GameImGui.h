#pragma once

#include "SDLImgui.h"
#include "../../vendors/imgui/imgui.h"

class GameImGui : public SDLImguiMenuItem
{
public:
    GameImGui() {}

    const char* GetName() const override
    {
        return "Game Settings";
    }

    virtual void RenderWindow() override
    {

        ImGui::SeparatorText("Game settings");
        ImGui::Begin("Game stuff", &isOpen);
        ImGui::Text("Frames passed: %d", 120);

        std::string game_state = "FREEZE";
        ImGui::Text("Game state: %s", game_state.c_str());

        ImGui::SeparatorText("Cheats:");
        if (ImGui::Button("Freeze game"))
        {
            //m_Game->TogglePause();
        }

        if (ImGui::Button("Next Frame"))
        {
            //m_Game->NextFrame();
        }

        ImGui::End();
    }
};