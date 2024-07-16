#include "StateGame.h"

#include <iostream>

#include "../../../helpers/SDL/SDLManager.h"
#include "../../../project/Sources/functions.h"
#include "../../../project/Sources/SDLImgui.h"
#include "../../vendors/imgui/imgui.h"
#include "../../project/Sources/GameImGui.h"
#include "../../project/algos/bubblesort.h"
#include "../../project/algos/cyclesort.h"

void StateGame::Enter(StateManager* manager)
{
    std::cout << "State game enter" << '\n';

    randomVector = generateRandomVector(1, 800);

    auto mwin = SDLManager::Instance().Window();
    SDLImgui::Instance().Initialize(SDLManager::Instance().Window(), SDLManager::Instance().Renderer());
    SDLImgui::Instance().AddImguiWindow(std::make_shared<GameImGui>(*this));
}

void StateGame::resetVector()
{
    randomVector.clear();
    randomVector = generateRandomVector(1, 800);
}

void StateGame::Update(StateManager* manager)
{
    SDLImgui::Instance().Update();

    if (currentAlgorithm != runningAlgorithm)
    {
        runningAlgorithm = currentAlgorithm;
        resetVector();
        return;
    }

    switch (currentAlgorithm)
    {
        case 0:
        
            bubbleSortStep(randomVector);
            break;
        case 1:
            cycleSortStep(randomVector, 10);
            break;
        default:
            // Handle default case
            break;
    }
}

void StateGame::Draw(StateManager* manager)
{
    SDL_Color color;
    color = { 125, 0, 255, 255 };
    for (int i = 0; i < randomVector.size(); i++)
    {
        int vector_value = randomVector[i];
        int vector_position = i;

        int32_t linePosTopX = vector_position;
        int32_t linePosTopY = SCREEN_HEIGHT - vector_value;

        int32_t lineDownX = vector_position;
        int32_t lineDownY = SCREEN_HEIGHT;

        DrawLine(linePosTopX, linePosTopY, lineDownX, lineDownY, color);
    }

    switch (currentAlgorithm)
    {
    case 1:
        color = { 220, 20, 60, 255 };
        DrawLine(cycleSortParams.pos, 0, cycleSortParams.pos, SCREEN_HEIGHT, color);
        DrawLine(cycleSortParams.pos+1, 0, cycleSortParams.pos+1, SCREEN_HEIGHT, color);

        color = { 60, 219, 20, 255 };
        DrawLine(cycleSortParams.i, 0, cycleSortParams.i, SCREEN_HEIGHT, color);
        DrawLine(cycleSortParams.i+1, 0, cycleSortParams.i+1, SCREEN_HEIGHT, color);

        //DrawLine(cycleSortParams.pos, 0, cycleSortParams.cycle_start, SCREEN_HEIGHT, color);
        break;
    }

    SDLImgui::Instance().Render();
}

void StateGame::Exit(StateManager* manager) 
{
    // Cleanup on exit this state
}

void StateGame::Toggle(StateManager* manager) {}


void StateGame::DrawSomething()
{
    char buffer[50];
    std::sprintf(buffer, "SCORE: %d", randomIntInRange(2, 100));

    SDL_Color color = { 123, 123, 123, 255 };
    SDL_Texture* textTexture = SDLManager::Instance().renderText(buffer, color);

    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
    SDL_Rect destRect = { 10, 70, textWidth, textHeight };  // Position at (100, 100)
    SDL_RenderCopy(SDLManager::Instance().Renderer(), textTexture, nullptr, &destRect);
}