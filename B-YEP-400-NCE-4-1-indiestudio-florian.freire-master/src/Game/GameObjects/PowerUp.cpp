/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** PowerUp
*/

#include "../../../include/Game/GameObjects/PowerUp.hpp"

PowerUp::PowerUp(Vector3 pos, Vector3 size, std::string textureName, int type) : AObjects(0, 1, pos, size, textureName, -1),
    _typeOfPower(type)
{
}

PowerUp::~PowerUp()
{
}

void PowerUp::destruct(){}
int PowerUp::run(){ return 0; }
int PowerUp::getPower() { return _typeOfPower; }
void PowerUp::explosion(){}
int PowerUp::isExplose(){return 0;}