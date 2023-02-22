/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Saving
*/

#include "../include/Saving.hpp"
#include "algorithm"

std::vector<int> fillVector(std::vector<int> vec, std::vector<int> list)
{
    for(size_t i = 0; i < list.size(); i++)
    {
        vec.push_back(list[i]);
    }
    return vec;
}

Saving::Saving()
{
    _showFPS = false;
    std::vector<int> m1;
    m1 = fillVector(m1, {KEY_W, KEY_A, KEY_S, KEY_D, KEY_Q, 0});
    std::vector<int> m2;
    m2 = fillVector(m2, {KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT, KEY_RIGHT_SHIFT, 0});
    std::vector<int> m3;
    m3 = fillVector(m3, {KEY_Y, KEY_G, KEY_H, KEY_J, KEY_T, 1});
    std::vector<int> m4;
    m4 = fillVector(m4, {KEY_O, KEY_K, KEY_L, KEY_SEMICOLON, KEY_I, 1});
    _playerMovements.push_back(m1);
    _playerMovements.push_back(m2);
    _playerMovements.push_back(m3);
    _playerMovements.push_back(m4);
    _mainMusic = LoadMusicStream("asset/mainMusic.mp3");
    PlayMusicStream(_mainMusic);
    _musicVolume = 2;
    SetMusicVolume(_mainMusic, _musicVolume);
}

int const Saving::getUp(int id)
{
    return _playerMovements[id][0];
}

int const Saving::getRight(int id)
{
    return _playerMovements[id][3];
}

int const Saving::getDown(int id)
{
    return _playerMovements[id][2];
}

int const Saving::getLeft(int id)
{
    return _playerMovements[id][1];
}

int const Saving::getUse(int id)
{
    return _playerMovements[id][4];
}

bool Saving::isAI(int id)
{
    if (_playerMovements[id][5] == 1) return true;
    else return false;
}

void Saving::use()
{
    UpdateMusicStream(_mainMusic);
    if (_showFPS) DrawFPS(10, 10);
}

void Saving::switchFPS()
{
    _showFPS = !_showFPS;
}

bool Saving::isFPSshown()
{
    return _showFPS;
}

void Saving::switchIA(int id)
{
    if (_playerMovements[id][5] == 1) _playerMovements[id][5] = 0;
    else _playerMovements[id][5] = 1;
}

void Saving::setUp(int id, int key)
{
    _playerMovements[id][0] = key;
}

void Saving::setRight(int id, int key)
{
    _playerMovements[id][1] = key;
}

void Saving::setDown(int id, int key)
{
    _playerMovements[id][2] = key;
}

void Saving::setLeft(int id, int key)
{
    _playerMovements[id][3] = key;
}

void Saving::setUse(int id, int key)
{
    _playerMovements[id][4] = key;
}

float Saving::getVolume()
{
    return _musicVolume;
}

void Saving::addVolume()
{
    _musicVolume += 0.1;
    SetMusicVolume(_mainMusic, _musicVolume);
}

void Saving::subVolume()
{
    if (_musicVolume <= 0.0)
        return;
    _musicVolume -= 0.1;
    SetMusicVolume(_mainMusic, _musicVolume);
}

void Saving::setVolume(float nb)
{
    _musicVolume = nb;
    SetMusicVolume(_mainMusic, _musicVolume);
}

void Saving::addWinner(int i)
{
    for (int j = 0; j < winner.size(); j++)
    {
        if (winner[j] == i)
            return;
    }
    winner.push_back(i);
}

std::vector<int> Saving::getWinner()
{
    return winner;
}

void Saving::prepareWinner()
{
    std::reverse(winner.begin(), winner.end());
}

Saving::~Saving()
{
}
