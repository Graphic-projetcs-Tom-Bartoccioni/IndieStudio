/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** MainGame
*/

#ifndef MAINGAME_HPP_
#define MAINGAME_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "GameObjects/AObjects.hpp"
#include "GameObjects/BomberMan.hpp"
#include "GameObjects/Bombes.hpp"
#include "GameObjects/Box.hpp"
#include "GameObjects/PowerUp.hpp"
#include "GameObjects/Wall.hpp"
#include "../Player.hpp"

#include "../Core.hpp"
class Core;

class MainGame {
    public:
        MainGame();
        ~MainGame();

        const std::vector<AObjects*> getAllObjects();
        const std::vector<BomberMan*> getAllBomberMans();

        int run(Core *core);
        int routine();
        void takeMap(std::string mapeName);
        void movements(Core *core);
        void colision();
        void explode();

    protected:
    private:
        std::vector<AObjects*> _allObjects;
        std::vector<BomberMan*> _bomberMans;
        std::vector<Bombes*> _bombes;
        BoundingBox _bomberMan1;
};

#endif /* !MAINGAME_HPP_ */
