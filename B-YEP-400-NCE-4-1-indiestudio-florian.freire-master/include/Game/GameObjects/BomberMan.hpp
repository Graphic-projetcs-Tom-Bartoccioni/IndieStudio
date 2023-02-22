/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** BomberMan
*/

#ifndef BOMBERMAN_HPP_
#define BOMBERMAN_HPP_

#include "./AObjects.hpp"
#include "../../Player.hpp"
#include "PowerUp.hpp"

class BomberMan : public AObjects {
    public:
        BomberMan(Vector3 pos, Vector3 size, std::string textureName, int id);
        ~BomberMan();

        int getId();
        int getIa();
        int getPowerRange();
        float getPowerSpeed();
        int getPowerBomb();
        int getAlive();

        int run();          // +++ cpp
        void destruct();    // +++ cpp
        void explosion();
        int isExplose();

        int print(int up, int right, int down, int left);
        void spawnBombe();
        void takePowerUp(PowerUp *powerUp);
        void movements();
        void setAlive(int alive);
        void setPosX(float x);
        void setPosY(float y);

    protected:
    private:
        int _id;
        int _ia;
        float _powerSpeed;
        int _powerRange;
        int _powerMaxBombe;
        int _alive;
        std::vector<AObjects> _bombes;

        Player _player;
};

#endif /* !BOMBERMAN_HPP_ */
