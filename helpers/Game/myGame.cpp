#include "myGame.h"
#include "../SDL/SDLManager.h"
#include "State/StateManager.h"
#include "State/StateGame.h"
#include "../../vendors/imgui/imgui.h"
#include "../../vendors/imgui/backends/imgui_impl_sdl2.h"
#include "../../vendors/imgui/backends/imgui_impl_sdlrenderer2.h"
#include <iostream>

void myGame::Start()
{
    m_IsRunning = true;
    std::cout << "Game started!" << std::endl;
    SDLManager::Instance();
}

myGame::~myGame()
{
    SDLManager::Instance().Cleanup();
}

bool myGame::IsRunning() const
{
    return m_IsRunning;
}

void myGame::Stop()
{
    m_IsRunning = false;
    m_StateManager->Exit();
    std::cout << "Game stopped!" << std::endl;
}

void myGame::Update(float deltaTime)
{
    if (m_IsRunning)
    {
        m_StateManager->Update();
    }
}

void myGame::Clear()
{
    SDLManager::Instance().Clear();
}

void myGame::Draw(float deltaTime)
{
    if (m_IsRunning)
    {
        m_StateManager->Draw();
    }

    SDLManager::Instance().Present();
}

void myGame::Init()
{
    SDLManager::Instance().Init(m_gameParams.gameTitle, m_gameParams.screenWidth, m_gameParams.screenHeight);
    m_StateManager->SetState(new StateGame());
}

void myGame::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);

        if (event.type == SDL_QUIT)
        {
            Stop();
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {

            }
        }

        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
            case SDLK_w:
                SimpleInputManager::Instance().KeyPress(SDL_SCANCODE_UP);
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                SimpleInputManager::Instance().KeyPress(SDL_SCANCODE_RIGHT);
                break;
            case SDLK_LEFT:
            case SDLK_a:
                SimpleInputManager::Instance().KeyPress(SDL_SCANCODE_LEFT);
                break;
            case SDLK_DOWN:
            case SDLK_s:
                SimpleInputManager::Instance().KeyPress(SDL_SCANCODE_DOWN);
                break;
            }
        }


        /*if (event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
            case SDLK_w:
                Input().KeyRelease(SDL_SCANCODE_UP);
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                Input().KeyRelease(SDL_SCANCODE_RIGHT);
                break;
            case SDLK_LEFT:
            case SDLK_a:
                Input().KeyRelease(SDL_SCANCODE_LEFT);
                break;
            case SDLK_DOWN:
            case SDLK_s:
                Input().KeyRelease(SDL_SCANCODE_DOWN);
                break;
            }
        }*/
        // Handle other events like keyboard, mouse, etc.
    }
}