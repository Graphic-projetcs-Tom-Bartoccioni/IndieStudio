/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../Scene.hpp"
#include "../Game/MainGame.hpp"

class MainGame;

class Game : public Scene {
    public:
        Game();
        ~Game();

        void run(Core *core);

    protected:
    private:
        MainGame *_mainGame;
        Camera3D _camera;
        Button *_returnbutton;
};

#endif /* !GAME_HPP_ */
