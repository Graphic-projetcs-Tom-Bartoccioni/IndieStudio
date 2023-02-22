/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Player
*/

#include "../include/Player.hpp"

Player::Player() : _anim(0)
{
}

void Player::setModels(std::string mod, std::string texture)
{
    std::string str;
    _texture = LoadTexture(texture.c_str());
    for (int i = 0; i < 40; i++) {
        if (i < 9) str = mod + "0" + std::to_string(i + 1) + ".obj";
        else str = mod + std::to_string(i + 1) + ".obj";
        _model.push_back(LoadModel(str.c_str()));
        _model[i].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
    }
}

void Player::rotate(int up, int right, int down, int left)
{
    if (IsKeyDown(up)) _yaw = 0.0f;
    else if (IsKeyDown(right)) _yaw = 90.0f;
    else if (IsKeyDown(down)) _yaw = -180.0f;
    else if (IsKeyDown(left)) _yaw = -90.0f;

    for (int i = 0; i < 40; i++)
        _model[i].transform = MatrixRotateXYZ((Vector3){ 0, DEG2RAD*_yaw, 0 });
}

void Player::print(Vector2 pos, int up, int right, int down, int left)
{
    DrawModel(_model[_anim], {pos.x, 0, pos.y}, 1.0f, WHITE);

    if (IsKeyDown(up)) _anim++;
    else if (IsKeyDown(right)) _anim++;
    else if (IsKeyDown(down)) _anim++;
    else if (IsKeyDown(left)) _anim++;
    else if (_anim != 0) _anim++;

    if (_anim >= 40) _anim = 0;
}

void Player::destroy()
{
    UnloadTexture(_texture);
    for (int i = 0; i < 40; i++)
        UnloadModel(_model[i]);
    std::cout << "Player Détruit" << std::endl;    
}

Player::~Player()
{
}