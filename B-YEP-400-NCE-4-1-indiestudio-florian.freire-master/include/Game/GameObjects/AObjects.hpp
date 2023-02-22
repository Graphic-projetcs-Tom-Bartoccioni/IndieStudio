/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** AObjects
*/

#ifndef AOBJECTS_HPP_
#define AOBJECTS_HPP_

#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

class AObjects {
    public:
        AObjects(int solide, int destructible, Vector3 pos, Vector3 size, std::string textureName, int id);
        virtual ~AObjects() = 0;

        int const getSolide();
        int const getDestructible();
        int const getId();
        float getPosX();
        float getPosY();
        Color getColor();
        Vector3 getPos();
        Vector3 getSize();
        Texture2D getTexture();

        virtual int run() = 0;
        virtual void destruct() = 0;
        virtual void explosion() = 0;
        virtual int isExplose() = 0;

    protected:
        int _solide;
        int _destructible;
        Vector3 _pos;
        Vector3 _size;
        Texture2D _texture;
        Color _color;
        int _id;
    private:
};

#endif /* !AOBJECTS_HPP_ */
