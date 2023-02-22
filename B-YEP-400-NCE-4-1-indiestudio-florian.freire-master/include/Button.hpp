/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"

class Button {
    public:
        Button(std::string path, Vector2 pos, Vector2 widthHeight);
        Button(Color color, Vector2 pos, Vector2 widthHeight);
        ~Button();

        const int getX();
        const int getY();
        const int getWidth();
        const int getHeight();
        const bool getImage();
        void setX(int x);
        void setY(int y);
        void print();
        bool isClick(Vector2 mousePos);
        void changeColor(Color color);

    private:
        Vector2 _pos;
        Texture2D _button;
        Color _color;
        bool _isImage;
};

#endif /* !BUTTON_HPP_ */
