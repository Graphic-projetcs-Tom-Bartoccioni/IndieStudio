/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "Scene/Menu.hpp"
#include "Scene/Settings.hpp"
#include "Scene/End.hpp"
#include "Saving.hpp"
#include "raylib.h"
#include "Scene/Game.hpp"

class Core {
    public:
        Core();
        ~Core();

        void run();
        void switchScene(int);
        Saving *getSave();

    private:
        int _screenWidth, _screenHeight;
        Scene *_scene;
        int _state, _lastState;
        Saving *_save;
};

// _state is for the statement of the game
// -1 is for an error occured and you need to close the game
// 0 for menu
// 1 for settings
// 2 for game

#endif /* !CORE_HPP_ */
