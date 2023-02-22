/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <string>
#include <iostream>

class Player {
    public:
        Player();
        ~Player();

        void setModels(std::string mod, std::string texture);
        void print(Vector2 pos, int up, int right, int down, int left);
        void rotate(int up, int right, int down, int left);
        void destroy();

        int const getId();

    protected:
    private:
        Texture2D _texture;
        std::vector<Model> _model;
        int _anim;
        float _yaw = 0.0f;
        int _id;
};

#endif /* !PLAYER_HPP_ */
