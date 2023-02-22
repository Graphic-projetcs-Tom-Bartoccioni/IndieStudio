/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../Scene.hpp"
#include "../Button.hpp"

class Menu : public Scene
{
    public:
        Menu();
        ~Menu();

        void run(Core *core);

    protected:
    private:
        Button *_exitButton, *_settingsButton, *_playButton;
        Texture2D _backgroundImage;
        Texture2D _titleImage;
        int _fade;
};

#endif /* !MENU_HPP_ */
