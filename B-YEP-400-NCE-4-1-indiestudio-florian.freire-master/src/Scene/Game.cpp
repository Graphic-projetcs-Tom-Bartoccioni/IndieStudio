/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Game
*/

#include "../../include/Scene/Game.hpp"
#include "../../include/Core.hpp"

Game::Game()
{
    _mainGame = new MainGame();
    _camera = { { 0.0f, 28.0f, 15.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 60.0f, 0 };
    _returnbutton = new Button(BLACK, {25, 25}, {280, 100});
}

void Game::run(Core *core)
{
    Color playerColor = GREEN;
    bool collision = false;

    _mainGame->run(core);

    std::vector<AObjects*> objects = _mainGame->getAllObjects();
    std::vector<BomberMan*> bombermans = _mainGame->getAllBomberMans();

    if (_returnbutton->isClick(GetMousePosition())) core->switchScene(0);

    BeginDrawing();

        ClearBackground(RAYWHITE);
        BeginMode3D(_camera);
            for (int i = 0; i < objects.size(); i++) {
                DrawCubeTexture(objects[i]->getTexture(), objects[i]->getPos(), objects[i]->getSize().x, objects[i]->getSize().y, objects[i]->getSize().z, objects[i]->getColor());
                DrawCubeWires(objects[i]->getPos(), objects[i]->getSize().x, objects[i]->getSize().y, objects[i]->getSize().z, DARKGRAY);
            }
            for (int i = 0; i < bombermans.size(); i++) {
                bombermans[i]->print(core->getSave()->getUp(bombermans[i]->getId()),
                                   core->getSave()->getRight(bombermans[i]->getId()),
                                   core->getSave()->getDown(bombermans[i]->getId()),
                                   core->getSave()->getLeft(bombermans[i]->getId()));
            }
            DrawGrid(30, 1.0f);

        EndMode3D();

        _returnbutton->print();
        DrawText("MENU", _returnbutton->getX() + 35, _returnbutton->getY() + 15, 75, WHITE);

        core->getSave()->use();

    EndDrawing();
}

Game::~Game()
{
    delete _mainGame;
}
