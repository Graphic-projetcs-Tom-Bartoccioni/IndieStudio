/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include "./AObjects.hpp"

class Wall : public AObjects {
    public:
        Wall(Vector3 pos, Vector3 size, std::string textureName);
        ~Wall();

        int run();         // +++ cpp
        void destruct();    // +++ cpp
        void explosion();
        int isExplose();

    protected:
    private:
};

#endif /* !WALL_HPP_ */
