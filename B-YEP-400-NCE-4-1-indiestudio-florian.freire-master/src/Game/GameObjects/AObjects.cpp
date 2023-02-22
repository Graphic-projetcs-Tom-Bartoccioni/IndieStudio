/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** AObjects
*/

#include "../../../include/Game/GameObjects/AObjects.hpp"

AObjects::AObjects(int solide, int destructible, Vector3 pos, Vector3 size, std::string textureName, int id)  :
    _solide(solide),
    _destructible(destructible),
    _pos(pos),
    _size(size),
    _id(id)
{
    _texture = LoadTexture(textureName.c_str());
    if (_destructible && _solide) _color = WHITE;
    else if (!_solide) _color = WHITE;
    else _color = WHITE;
}

AObjects::~AObjects()
{
}

// Getters

int const AObjects::getSolide() { return _solide; }
int const AObjects::getDestructible() { return _destructible; }
int const AObjects::getId() { return _id; }
float AObjects::getPosX() { return _pos.x; }
float AObjects::getPosY() { return _pos.z; }
Vector3 AObjects::getPos() { return _pos; }
Vector3 AObjects::getSize() { return _size; }
Color AObjects::getColor() { return _color; }
Texture2D AObjects::getTexture() { return _texture; }