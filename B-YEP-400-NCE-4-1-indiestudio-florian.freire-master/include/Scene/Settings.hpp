/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "../Scene.hpp"
#include "../Button.hpp"

class Settings : public Scene
{
    public:
        Settings();
        ~Settings();

        void run(Core *core);
        void printSettings();
        void checkUserSettings(Core *core);
        int alreadyUse(Core *core, int key);

    protected:
    private:
        Button *_backButton, *_showFPSButton;
        Button *_upVolumeButton, *_downVolumeButton, *_stopVolumeButton;
        std::vector<Button*> _IAButtons;
        std::vector<std::vector<Button*>> _playerKeys;
        int _tmp, _keyTmp, _idTmp;
};

#endif /* !SETTINGS_HPP_ */
