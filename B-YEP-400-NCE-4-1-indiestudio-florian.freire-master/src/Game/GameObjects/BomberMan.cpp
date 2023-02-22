/*
** EPITECH PROJECT, 2021
** Indie studio
** File description:
** BomberMan
*/

#include "../../../include/Game/GameObjects/BomberMan.hpp"

BomberMan::BomberMan(Vector3 pos, Vector3 size, std::string textureName, int id) : AObjects(0, 1, pos, size, textureName, id),
    _powerMaxBombe(1),
    _powerRange(3),
    _powerSpeed(0.8f),
    _alive(1),
    _id(id)
{
    Player player;
    player.setModels("SteveObj/steve_0000", textureName);
    _player = player;
}

BomberMan::~BomberMan()
{
    _player.destroy();
}

void BomberMan::takePowerUp(PowerUp *powerUp)
{
    int power = powerUp->getPower();
    if (power == 1) _powerSpeed += 0.1f;
    else if (power == 2) _powerMaxBombe++;
    else if (power == 3) _powerRange += 2;
    else if (power == 4 && _powerSpeed > 1) _powerSpeed -= 0.1f;
    else if (power == 5 && _powerRange > 1) _powerRange -= 2;
    else if (power == 6 && _powerMaxBombe > 1) _powerMaxBombe--;
}

void BomberMan::spawnBombe()
{
    // +++ ajout d'une bombe dans le vecteur _bombes
}

void BomberMan::movements()
{
    if (_ia) {}
    else {
        if (IsKeyDown(KEY_Z)) _pos.y += (0.05 * _powerSpeed);
        if (IsKeyDown(KEY_Q)) _pos.y -= (0.05 * _powerSpeed);
        if (IsKeyDown(KEY_S)) _pos.x -= (0.05 * _powerSpeed);
        if (IsKeyDown(KEY_D)) _pos.x += (0.05 * _powerSpeed);
        if (IsKeyDown(KEY_SPACE)) this->spawnBombe();
    }
}

int BomberMan::getPowerRange()
{
    return _powerRange;
}

float BomberMan::getPowerSpeed()
{
    return _powerSpeed;
}

int BomberMan::getPowerBomb()
{
    return _powerMaxBombe;
}

int BomberMan::getId()
{
    return _id;
}

int BomberMan::getAlive()
{
    return _alive;
}

void BomberMan::setAlive(int alive)
{
    _alive = alive;
}

void BomberMan::setPosX(float x)
{
    _pos.x = x;
}

void BomberMan::setPosY(float y)
{
    _pos.z = y;
}

int BomberMan::print(int up, int right, int down, int left)
{
    _player.rotate(up, right, down, left);
    _player.print({_pos.x, _pos.z}, up, right, down, left);
    return 0;
}

void BomberMan::destruct(){}
void BomberMan::explosion(){}
int BomberMan::run(){return 0;}
int BomberMan::isExplose(){return 2;}