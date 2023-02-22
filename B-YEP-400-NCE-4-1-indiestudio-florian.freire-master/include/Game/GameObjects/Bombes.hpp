/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Bombes
*/

#ifndef BOMBES_HPP_
#define BOMBES_HPP_

#include "./AObjects.hpp"

class Bombes : public AObjects {
    public:
        Bombes(Vector3 pos, Vector3 size, std::string textureName, int id);
        ~Bombes();

        int run();         // +++ cpp
        void destruct();    // +++ cpp
        void explosion();
        int isExplose();

    protected:
    private:
        int _frames;
        int _timer;
        int _idBomberman;
        time_t _spawnTime;
};

#endif /* !BOMBES_HPP_ */
