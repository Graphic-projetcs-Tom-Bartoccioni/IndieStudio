/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** Box
*/

#include "../../../include/Game/GameObjects/Box.hpp"

Box::Box(Vector3 pos, Vector3 size, std::string textureName) : AObjects(1, 1, pos, size, textureName, -1)
{
}

void Box::destruct()
{
    // +++ animation de destruction + random spawn powerup
    this->~Box();
}
int Box::run(){ return 0; }
void Box::explosion(){}
int Box::isExplose(){return 0;}

Box::~Box()
{
    UnloadTexture(_texture);
}