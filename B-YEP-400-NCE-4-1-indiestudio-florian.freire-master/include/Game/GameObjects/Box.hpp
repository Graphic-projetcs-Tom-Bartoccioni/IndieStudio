/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "./AObjects.hpp"

class Box : public AObjects {
    public:
        Box(Vector3 pos, Vector3 size, std::string textureName);
        ~Box();

        int run();
        void destruct();
        void explosion();
        int isExplose();

    protected:
    private:
};

#endif /* !BOX_HPP_ */
