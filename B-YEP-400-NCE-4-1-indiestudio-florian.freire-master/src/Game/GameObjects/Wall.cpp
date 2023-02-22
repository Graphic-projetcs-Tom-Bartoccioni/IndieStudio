/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** Wall
*/

#include "../../../include/Game/GameObjects/Wall.hpp"

Wall::Wall(Vector3 pos, Vector3 size, std::string textureName) : AObjects(1, 0, pos, size, textureName, -1)
{
}

Wall::~Wall()
{
}

void Wall::destruct(){}
int Wall::run(){ return 0; }
void Wall::explosion(){}
int Wall::isExplose(){return 0;}