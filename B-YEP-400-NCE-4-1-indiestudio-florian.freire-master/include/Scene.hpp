/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include "raylib.h"

class Core;
class Button;

class Scene {
    public:
        Scene();
        ~Scene();

        virtual void run(Core *core);

    protected:
    private:
};

#endif /* !SCENE_HPP_ */