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

#include "GameState.h"
#include "StateManager.h"
#include "../../Input/SimpleInputManager.h"

class StateGame : public IGameState
{
public:
    void Enter(StateManager* manager) override;
    void Exit(StateManager* manager) override;
    void Update(StateManager* manager) override;
    void Draw(StateManager* manager) override;
    void Toggle(StateManager* manager) override;

public:
    void DrawSomething();

private:
    int vectorSize;
    int steps;
    bool swapped;
    int i;
    int j;
    std::vector<int> randomVector;
};
