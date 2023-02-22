/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "./AObjects.hpp"

class PowerUp : public AObjects {
    public:
        PowerUp(Vector3 pos, Vector3 size, std::string textureName, int type);
        ~PowerUp();

        int run();         // +++ cpp
        void destruct();    // +++ cpp
        int getPower();
        void explosion();
        int isExplose();

    protected:
    private:
        int _typeOfPower;
};

#endif /* !POWERUP_HPP_ */
