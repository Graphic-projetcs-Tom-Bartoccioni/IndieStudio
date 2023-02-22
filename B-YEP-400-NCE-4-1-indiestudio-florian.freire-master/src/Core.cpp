/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Core
*/

#include "../include/Core.hpp"

Core::Core()
{
    _screenWidth = 1920;
    _screenHeight = 1080;
    SetTraceLogLevel(LOG_WARNING | LOG_ERROR);
    InitWindow(1920, 1080, "IndieStudio");
    InitAudioDevice();
    ToggleFullscreen();
    SetExitKey(999);
    SetTargetFPS(60);
    _scene = new Menu;
    _save = new Saving;
    _state = 0;
}

void Core::switchScene(int which)
{
    if (which == 0)
        _scene = new Menu;
    else if (which == 1)
        _scene = new Settings;
    else if (which == 2)
        _scene = new Game;
    else if (which == 3)
        _scene = new End;
    else
        exit(0);
}

void Core::run()
{
    while (!WindowShouldClose()) _scene->run(this);
    CloseWindow();
    return ;
}

Saving *Core::getSave()
{
    return _save;
}

Core::~Core()
{
}
