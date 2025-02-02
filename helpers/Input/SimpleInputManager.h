/*
*           ___            __    ___  __    ___       _ _                 _       _
*          / __\ __  _ __ / _\  /   \/ /   / __\ ___ (_) | ___ _ __ _ __ | | __ _| |_ ___
*         / / | '_ \| '_ \\ \  / /\ / /   /__\/// _ \| | |/ _ \ '__| '_ \| |/ _` | __/ _ \
*        / /__| |_) | |_) |\ \/ /_// /___/ \/  \ (_) | | |  __/ |  | |_) | | (_| | ||  __/
*        \____/ .__/| .__/\__/___,'\____/\_____/\___/|_|_|\___|_|  | .__/|_|\__,_|\__\___|
*             |_|   |_|                                            |_|
*
* Created by:   djomla
* Updated by:   djomla
*/

#pragma once

#include "SDL.h"
#include <map>
#include <vector>

class SimpleInputManager
{

public:
    SimpleInputManager(const SimpleInputManager&) = delete;
    SimpleInputManager& operator=(const SimpleInputManager&) = delete;
    static SimpleInputManager& Instance()
    {
        static SimpleInputManager instance; // Guaranteed to be destroyed, instantiated on first use
        return instance;
    }

public:
    void KeyPress(SDL_Scancode key)
    {
        keyStates[key] = true;
    }

    void KeyRelease(SDL_Scancode key)
    {
        keyStates[key] = false;
    }

    bool IsKeyPressed(SDL_Scancode key) const
    {
        auto it = keyStates.find(key);
        if (it != keyStates.end())
        {
            return it->second;
        }
        return false;
    }

    bool IsAnyKeyPressed() const
    {
        for (const auto& [key, pressed] : keyStates)
        {
            if (pressed)
            {
                return true;
            }
        }
        return false;
    }

    void ReleaseKeys()
    {
        keyStates.clear();
    }

    std::vector<SDL_Scancode> KeysPressed() const
    {
        std::vector<SDL_Scancode> pressedKeys;
        for (const auto& [key, pressed] : keyStates)
        {
            if (pressed)
            {
                pressedKeys.push_back(key);
            }
        }
        return pressedKeys;
    }
private:
    SimpleInputManager() {}

private:
    std::map<SDL_Scancode, bool> keyStates;
};