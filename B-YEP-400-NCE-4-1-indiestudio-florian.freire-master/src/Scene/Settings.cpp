/*
** EPITECH PROJECT, 2021
** soup
** File description:
** Settings
*/

#include "../../include/Scene/Settings.hpp"
#include "../../include/Core.hpp"

#include <stdio.h>
#include <stdlib.h>

const char *getKey(int key)
{
    char e = key;
    std::string a;
    if (KEY_LEFT_CONTROL == key) return "LC";
    else if (KEY_LEFT_ALT == key) return "LA";
    else if (KEY_RIGHT_ALT == key) return "RA";
    else if (KEY_RIGHT_CONTROL == key) return "RC";
    else if (KEY_LEFT_SHIFT == key) return "LS";
    else if (KEY_RIGHT_SHIFT == key) return "RS";
    else if (KEY_CAPS_LOCK == key) return "CL";
    else if (KEY_TAB == key) return "Tab";
    else if (KEY_ENTER == key) return "↩";
    else if (KEY_BACKSPACE == key) return "BS";
    else if (KEY_INSERT == key) return "INS";
    else if (KEY_DELETE == key) return "DEL";
    else if (KEY_END == key) return "ED";
    else if (KEY_HOME == key) return "HM";
    else if (KEY_PAGE_UP == key) return "PU";
    else if (KEY_PAGE_DOWN == key) return "PD";
    else if (KEY_UP == key) return "UP";
    else if (KEY_RIGHT == key) return "->";
    else if (KEY_DOWN == key) return "DW";
    else if (KEY_LEFT == key) return "<-";
    else if (KEY_SPACE == key) return "SP";
    else { a.push_back(e); return (a.c_str()); }
}

Settings::Settings() : _tmp(-1), _keyTmp(0), _idTmp(-1)
{
    _backButton = new Button(BLACK, {25, 995}, {300, 45});
    _showFPSButton = new Button(WHITE, {550, 950}, {100, 100});
    _upVolumeButton = new Button(BLACK, {1650, 920}, {70, 70});
    _downVolumeButton = new Button(BLACK, {1400, 920}, {70, 70});
    _stopVolumeButton = new Button(BLACK, {1525, 1000}, {70, 70});
    for (int i = 0, j = 735; i < 3; i++, j += 450) {
        Button *e = new Button(WHITE, {(float)j, 550}, {50, 50});
        _IAButtons.push_back(e);
    }
    for (int i = 0; i < 4; i++) {
        std::vector<Button*> vec;
        for (int j = 0; j < 5; j++) {
            vec.push_back(new Button(WHITE, {(float)(i * 450 + 280), (float)(265 + j * 50)}, {65, 65}));
            vec.push_back(new Button(WHITE, {(float)(i * 450 + 205), (float)(340 + j * 50)}, {65, 65}));
            vec.push_back(new Button(WHITE, {(float)(i * 450 + 280), (float)(340 + j * 50)}, {65, 65}));
            vec.push_back(new Button(WHITE, {(float)(i * 450 + 355), (float)(340 + j * 50)}, {65, 65}));
            vec.push_back(new Button(WHITE, {(float)(i * 450 + 280), (float)(440 + j * 50)}, {65, 65}));
        }
        _playerKeys.push_back(vec);
    }
}

int Settings::alreadyUse(Core *core, int key)
{
    for (int i = 0; i < 4; i++)
    {
        if (core->getSave()->getUp(i) == key)
            return -1;
        else if (core->getSave()->getDown(i) == key)
            return -1;
        else if (core->getSave()->getLeft(i) == key)
            return -1;
        else if (core->getSave()->getRight(i) == key)
            return -1;
    }
    return 0;
}

void Settings::checkUserSettings(Core *core)
{
    for (size_t i = 0; i < _IAButtons.size(); i++)
    {
        if (core->getSave()->isAI(i+1)) _IAButtons[i]->changeColor(GREEN);
        else _IAButtons[i]->changeColor(RED);
    }
}

void Settings::printSettings()
{
    _backButton->print();
    _showFPSButton->print();
    _upVolumeButton->print();
    _downVolumeButton->print();
    _stopVolumeButton->print();
    for (size_t i = 0; i < _IAButtons.size(); i++) _IAButtons[i]->print();
    for (int id = 0; id < _playerKeys.size(); id++) for (int j = 0; j < 5; j++) _playerKeys[id][j]->print();
    DrawText("<- GO BACK", _backButton->getX(), _backButton->getY(), 50, WHITE);
    DrawText("Show FPS", _showFPSButton->getX() - 75, _showFPSButton->getY() - 50, 50, BLACK);
    DrawText("Player 1", 200, 150, 50, BLACK);
    DrawText("Player 2", 650, 150, 50, BLACK);
    DrawText("Player 3", 1100, 150, 50, BLACK);
    DrawText("Player 4", 1550, 150, 50, BLACK);
    DrawText(">", _upVolumeButton->getX() + 20, _upVolumeButton->getY() - 10, 100, WHITE);
    DrawText("<", _downVolumeButton->getX() + 20, _downVolumeButton->getY() - 10, 100, WHITE);
    DrawText("Music Volume", _upVolumeButton->getX() - 250, _upVolumeButton->getY() - 75, 50, BLACK);
    for (size_t i = 0; i < _IAButtons.size(); i++) DrawText("AI?", _IAButtons[i]->getX(), _IAButtons[i]->getY() + 60, 35, BLACK);
}

void Settings::run(Core *core)
{
    if (core->getSave()->isFPSshown()) _showFPSButton->changeColor(GREEN); else _showFPSButton->changeColor(RED);
    if (_showFPSButton->isClick(GetMousePosition())) core->getSave()->switchFPS();
    if (_backButton->isClick(GetMousePosition())) core->switchScene(0);
    if (_upVolumeButton->isClick(GetMousePosition())) core->getSave()->addVolume();
    if (_downVolumeButton->isClick(GetMousePosition())) core->getSave()->subVolume();
    if (core->getSave()->getVolume() == 0) {if (_stopVolumeButton->isClick(GetMousePosition())) core->getSave()->setVolume(2);}
    else if (_stopVolumeButton->isClick(GetMousePosition())) core->getSave()->setVolume(0);
    for (size_t i = 0; i < _IAButtons.size(); i++) if (_IAButtons[i]->isClick(GetMousePosition())) core->getSave()->switchIA(i+1);

    checkUserSettings(core);

    BeginDrawing();

        ClearBackground(PURPLE);

        printSettings();

        for (int id = 0; id < 4; id++) {
            DrawText(getKey(core->getSave()->getUp(id)), 450 * id + 300, 280, 50, BLACK);
            DrawText(getKey(core->getSave()->getLeft(id)), 450 * id + 225, 350, 50, BLACK);
            DrawText(getKey(core->getSave()->getDown(id)), 450 * id + 300, 350, 50, BLACK);
            DrawText(getKey(core->getSave()->getRight(id)), 450 * id + 375, 350, 50, BLACK);
            DrawText(getKey(core->getSave()->getUse(id)), 450 * id + 300, 450, 50, BLACK);
            if (_playerKeys[id][0]->isClick(GetMousePosition())) {_tmp = 0; _idTmp = id; _playerKeys[_idTmp][0]->changeColor(RED);}
            if (_playerKeys[id][1]->isClick(GetMousePosition())) {_tmp = 1; _idTmp = id; _playerKeys[_idTmp][1]->changeColor(RED);}
            if (_playerKeys[id][2]->isClick(GetMousePosition())) {_tmp = 2; _idTmp = id; _playerKeys[_idTmp][2]->changeColor(RED);}
            if (_playerKeys[id][3]->isClick(GetMousePosition())) {_tmp = 3; _idTmp = id; _playerKeys[_idTmp][3]->changeColor(RED);}
            if (_playerKeys[id][4]->isClick(GetMousePosition())) {_tmp = 4; _idTmp = id; _playerKeys[_idTmp][4]->changeColor(RED);}
        }
        if (_idTmp != -1) {_keyTmp = GetKeyPressed();}
        if (_idTmp != -1 && _keyTmp != 0 && alreadyUse(core, _keyTmp) != -1)
        {
        if (_idTmp != -1 && _keyTmp != 0 && _tmp == 0) {core->getSave()->setUp(_idTmp, _keyTmp); _playerKeys[_idTmp][0]->changeColor(WHITE); _idTmp = -1; _tmp = -1;}
        if (_idTmp != -1 && _keyTmp != 0 && _tmp == 1) {core->getSave()->setRight(_idTmp, _keyTmp); _playerKeys[_idTmp][1]->changeColor(WHITE); _idTmp = -1; _tmp = -1;}
        if (_idTmp != -1 && _keyTmp != 0 && _tmp == 2) {core->getSave()->setDown(_idTmp, _keyTmp); _playerKeys[_idTmp][2]->changeColor(WHITE); _idTmp = -1; _tmp = -1;}
        if (_idTmp != -1 && _keyTmp != 0 && _tmp == 3) {core->getSave()->setLeft(_idTmp, _keyTmp); _playerKeys[_idTmp][3]->changeColor(WHITE); _idTmp = -1; _tmp = -1;}
        if (_idTmp != -1 && _keyTmp != 0 && _tmp == 4) {core->getSave()->setUse(_idTmp, _keyTmp); _playerKeys[_idTmp][4]->changeColor(WHITE); _idTmp = -1; _tmp = -1;}
        }
        std::string vol = std::to_string(core->getSave()->getVolume()).substr(0, 3);
        if (vol.find("-") != std::string::npos) vol = "0.0";
        if (vol == "0.0") DrawText("X", _stopVolumeButton->getX() + 12, _stopVolumeButton->getY(), 75, WHITE);
        DrawText(vol.c_str(), _upVolumeButton->getX() - 133, _upVolumeButton->getY(), 70, BLACK);

        core->getSave()->use();

    EndDrawing();
}

Settings::~Settings()
{
}
