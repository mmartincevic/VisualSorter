#include "StateGame.h"
#include "../../../helpers/SDL/SDLManager.h"
#include "../../../project/Sources/definitions.h"
#include "../../../project/Sources/functions.h"
#include "../../../project/Sources/SDLImgui.h"
#include <iostream>

void StateGame::Enter(StateManager* manager)
{
    std::cout << "State game enter" << '\n';
    // Entering this gamestate

    randomVector = generateRandomVector(1, 800);
    vectorSize = randomVector.size();
    steps = 0;
    swapped = false;
    i = 0;
    j = 0;

    //SDLImgui::Instance().Initialize(SDLManager::Instance().Window(), SDLManager::Instance().Renderer());
}

void bubbleSortStep(std::vector<int>& arr, int& i, int& j, bool& swapped)
{
    if (i >= arr.size() - 1)
    {
        return; // Array is sorted
    }

    if (j < arr.size() - i - 1)
    {
        if (arr[j] > arr[j + 1])
        {
            std::swap(arr[j], arr[j + 1]);
            swapped = true;
        }
        j++;
    }
    else
    {
        j = 0;
        i++;
        if (!swapped)
        {
            i = arr.size(); // Forces outer loop to end
        }
        swapped = false;
    }
}

void StateGame::Update(StateManager* manager)
{
    //SDLImgui::Instance().Update();
    bubbleSortStep(randomVector, i, j, swapped);
}

void StateGame::Draw(StateManager* manager)
{
    //SDLImgui::Instance().Render();

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
