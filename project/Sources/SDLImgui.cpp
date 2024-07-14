#include "SDLImgui.h"

#include "definitions.h"

//#include "imgui.h"
//#include "imgui_impl_sdl2.h"
//#include "imgui_impl_sdlrenderer2.h"

#include "../../vendors/imgui/imgui.h"
#include "../../vendors/imgui/backends/imgui_impl_sdl2.h"
#include "../../vendors/imgui/backends/imgui_impl_sdlrenderer2.h"


SDLImgui& SDLImgui::Instance()
{
    static SDLImgui instance;
    return instance;
}

SDLImgui::~SDLImgui()
{
    Shutdown();
}

void SDLImgui::AddImguiWindow(std::shared_ptr<SDLImguiMenuItem> imguiWindow)
{
    menuItems.push_back(imguiWindow);
}

void SDLImgui::Initialize(SDL_Window* window, SDL_Renderer* renderer)
{
    if (m_initialized)
        return;

    m_window = window;
    m_renderer = renderer;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    m_initialized = true;
}

void SDLImgui::Update()
{
    if (!m_initialized)
        return;

    ImGui_ImplSDLRenderer2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void SDLImgui::Render()
{
    if (!m_initialized)
        return;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(SCREEN_HEIGHT, 30), ImGuiCond_Always);

    ImGui::Begin("ImGUI Debugger", nullptr, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove);

    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Menu"))
        {
            for (auto& item : menuItems)
            {
                if (ImGui::MenuItem(item->GetName()))
                {
                    item->isOpen = true;
                }
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    for (auto& item : menuItems)
    {
        if (item->isOpen)
        {
            item->RenderWindow();
        }
    }

    ImGui::End();
    ImGui::Render();
    SDL_RenderSetScale(m_renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
    SDL_SetRenderDrawColor(m_renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), m_renderer);
}

void SDLImgui::Shutdown()
{
    if (!m_initialized)
        return;

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    m_initialized = false;
}