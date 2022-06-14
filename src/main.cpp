#include <iostream>
#include "window.h"
#include "game.h"
#include "assetmanager.h"

int main()
{
    //AssetManager manager;
    GameLoop game;
    while(!game.getWindow()->isDone())
    {
        game.handleInput();
        game.update();
        game.render();
    }
}
