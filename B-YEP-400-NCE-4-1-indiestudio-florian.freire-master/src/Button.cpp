/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Button
*/

#include "../include/Button.hpp"

Button::Button(std::string path, Vector2 pos, Vector2 widthHeight)
{
    _button = LoadTexture(path.c_str());
    _pos = pos;
    _button.width = widthHeight.x;
    _button.height = widthHeight.y;
    _isImage = true;
}

Button::Button(Color color, Vector2 pos, Vector2 widthHeight)
{
    _color = color;
    _pos = pos;
    _button.width = widthHeight.x;
    _button.height = widthHeight.y;
    _isImage = false;
}

int const Button::getX()
{
    return _pos.x;
}

int const Button::getY()
{
    return _pos.y;
}

int const Button::getWidth()
{
    return _button.width;
}

int const Button::getHeight()
{
    return _button.height;
}

bool const Button::getImage()
{
    return _isImage;
};


void Button::setX(int x)
{
    _pos.x = x;
}

void Button::setY(int y)
{
    _pos.y = y;
}

bool Button::isClick(Vector2 mousePos)
{
    if (mousePos.x >= _pos.x && mousePos.x <= (_pos.x + _button.width)
    && mousePos.y >= _pos.y && mousePos.y <= (_pos.y + _button.height))
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            return true;
    return false;
}

void Button::print()
{
    if (_isImage)
    DrawTexture(_button, _pos.x, _pos.y, WHITE);
    else DrawRectangle(_pos.x, _pos.y, _button.width, _button.height, _color);
}

void Button::changeColor(Color color)
{
    _color = color;
}

Button::~Button()
{
    if (_isImage)
        UnloadTexture(_button);
}
