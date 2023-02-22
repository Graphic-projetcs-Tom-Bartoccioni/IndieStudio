/*
** EPITECH PROJECT, 2021
** Indie Studio
** File description:
** Bombes
*/

#include "../../../include/Game/GameObjects/Bombes.hpp"

Bombes::Bombes(Vector3 pos, Vector3 size, std::string textureName, int id) : AObjects(1, 1, pos, size, textureName, id),
    _timer(3),
    _frames(0)
{
    _spawnTime = time(NULL);
    _color = BLACK;
}

Bombes::~Bombes()
{
}

void Bombes::explosion()
{
    _timer = 0;
}

int Bombes::isExplose()
{
    return 1;
}

void Bombes::destruct(){}
int Bombes::run()
{
    if (time(NULL) - _spawnTime >= _timer) {
        return 1;
    }
    else return 0;
}