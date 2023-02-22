/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** End
*/

#ifndef END_HPP_
#define END_HPP_

#include "../Scene.hpp"
#include "../Button.hpp"

class End : public Scene
{
    public:
        End();
        ~End();

        void run(Core *core);

    protected:
    private:
        Button *_redbutton;
        Button *_bluebutton;
        Button *_yellowbutton;
        Button *_graybutton;
        Button *_menuButton;
        Texture2D _backgroundImage;
        std::vector<std::pair<float, float>> Podium;
        
};

#endif /* !END_HPP_ */