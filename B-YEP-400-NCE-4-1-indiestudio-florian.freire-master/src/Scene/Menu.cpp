/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Menu
*/

#include "../../include/Scene/Menu.hpp"
#include "../../include/Core.hpp"

Menu::Menu()
{
    _exitButton = new Button(BLACK, {800, 850}, {250, 100});
    _settingsButton = new Button(BLACK, {710, 620}, {460, 100});
    _playButton = new Button(BLACK, {780, 350}, {320, 100});
    _backgroundImage = LoadTexture("asset/a.png");
    _titleImage = LoadTexture("asset/title.png");
    _fade = 0;
    _titleImage.width = 1530;
    _titleImage.height = 285;
}

void Menu::run(Core *core)
{
    if (_exitButton->isClick(GetMousePosition())) core->switchScene(-1);
    if (_settingsButton->isClick(GetMousePosition())) core->switchScene(1);
    if (_playButton->isClick(GetMousePosition())) core->switchScene(2);
    if (IsKeyReleased(KEY_G)) core->switchScene(2);
    if (_fade < 255)
        _fade++;

    BeginDrawing();

        ClearBackground(WHITE);

        DrawTexture(_backgroundImage, 0, 0, CLITERAL(Color){255, 255, 255, (unsigned char)_fade});
        DrawTexture(_titleImage, 210, 0, WHITE);

        _exitButton->print();
        _settingsButton->print();
        _playButton->print();

        DrawText("EXIT", _exitButton->getX() + 35, _exitButton->getY() + 15, 75, WHITE);
        DrawText("SETTINGS", _settingsButton->getX() + 35, _settingsButton->getY() + 15, 75, WHITE);
        DrawText("START", _playButton->getX() + 35, _playButton->getY() + 15, 75, WHITE);

        core->getSave()->use();

    EndDrawing();
}

Menu::~Menu()
{
}
