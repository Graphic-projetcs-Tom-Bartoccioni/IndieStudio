/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** Saving
*/

#ifndef SAVING_HPP_
#define SAVING_HPP_

#include "raylib.h"
#include <vector>
#include <iostream>

class Saving {
    public:
        Saving();
        ~Saving();

        void use();
        void switchFPS();
        void switchIA(int id);
        bool isFPSshown();
        int const getUp(int id);
        int const getRight(int id);
        int const getDown(int id);
        int const getLeft(int id);
        int const getUse(int id);
        bool isAI(int id);

        float getVolume();
        void addVolume();
        void subVolume();
        void setVolume(float nb);

        void setUp(int id, int key);
        void setRight(int id, int key);
        void setDown(int id, int key);
        void setLeft(int id, int key);
        void setUse(int id, int key);

        void addWinner(int i);
        std::vector<int> getWinner();
        void prepareWinner();

    protected:
    private:
        bool _showFPS;
        std::vector<std::vector<int>> _playerMovements;
        Music _mainMusic;
        float _musicVolume;
        std::vector<int> winner;
};

#endif /* !SAVING_HPP_ */
