/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** End
*/

#include "../../include/Scene/End.hpp"
#include "../../include/Core.hpp"
#include "algorithm"

End::End()
{
    Podium.push_back(std::make_pair(850, 300));
    Podium.push_back(std::make_pair(650, 450));
    Podium.push_back(std::make_pair(1050, 520));
    Podium.push_back(std::make_pair(1400, 590));
    _redbutton = new Button(RED, {0, 0}, {100, 100});
    _bluebutton = new Button(BLUE, {0, 0}, {100, 100});
    _yellowbutton = new Button(YELLOW, {0, 0}, {100, 100});
    _graybutton = new Button(GRAY, {0, 0}, {100, 100});
    _backgroundImage = LoadTexture("asset/over.png");
    _menuButton = new Button(WHITE, {25, 995}, {300, 45});
}

void End::run(Core *core)
{
    if (_menuButton->isClick(GetMousePosition())) core->switchScene(0);
    BeginDrawing();

    for (int i = 0; i < core->getSave()->getWinner().size(); i++)
    {
        if (core->getSave()->getWinner()[i] == 0)
        {
            _graybutton->setX(Podium[i].first);
            _graybutton->setY(Podium[i].second);
        }
        else if (core->getSave()->getWinner()[i] == 1)
        {
            _yellowbutton->setX(Podium[i].first);
            _yellowbutton->setY(Podium[i].second);
        }
        else if (core->getSave()->getWinner()[i] == 2)
        {
            _redbutton->setX(Podium[i].first);
            _redbutton->setY(Podium[i].second);
        }
        else if (core->getSave()->getWinner()[i] == 3)
        {
            _bluebutton->setX(Podium[i].first);
            _bluebutton->setY(Podium[i].second);
        }
    }

        ClearBackground(BLACK);

        DrawTexture(_backgroundImage, 0, 0, WHITE);

        _redbutton->print();
        _bluebutton->print();
        _yellowbutton->print();
        _graybutton->print();
        _menuButton->print();


        for (int i = 0; i < Podium.size(); i++)
        {
            std::string a = std::to_string(i+1);
            DrawText(a.c_str(), Podium[i].first + 30, Podium[i].second + 15, 75, RAYWHITE);
        }

        DrawText("<- GO MENU", _menuButton->getX(), _menuButton->getY(), 50, BLACK);
        DrawText("Well Played All !", 700, 850, 125, WHITE);

        core->getSave()->use();

    EndDrawing();
}

End::~End()
{
}
