/*
** EPITECH PROJECT, 2021
** B-YEP-400-NCE-4-1-indiestudio-florian.freire
** File description:
** MainGame
*/

#include "../../include/Game/MainGame.hpp"
#include <algorithm>

MainGame::MainGame()
{
    BomberMan *bomberMan1 = new BomberMan((Vector3){-12.0f, 1.0f, -12.0f}, (Vector3){1.1f, 2.0f, 1.1f}, "asset/iron.png", 0);
    _bomberMans.push_back(bomberMan1);
    BomberMan *bomberMan2 = new BomberMan((Vector3){12.0f, 1.0f, -12.0f}, (Vector3){1.1f, 2.0f, 1.1f}, "asset/gold.png", 1);
    _bomberMans.push_back(bomberMan2);
    BomberMan *bomberMan3 = new BomberMan((Vector3){-12.0f, 1.0f, 12.0f}, (Vector3){1.1f, 2.0f, 1.1f}, "asset/redstone.png", 2);
    _bomberMans.push_back(bomberMan3);
    BomberMan *bomberMan4 = new BomberMan((Vector3){12.0f, 1.0f, 12.0f}, (Vector3){1.1f, 2.0f, 1.1f}, "asset/diamond.png", 3);
    _bomberMans.push_back(bomberMan4);
    takeMap("map.txt");
    // +++ ajouter le tout dans le vector _allObjects
}

MainGame::~MainGame()
{
    // +++ free les objects
}

void MainGame::takeMap(std::string mapName)
{
    std::ifstream mapFile(mapName);
    std::string line;
    AObjects *newBox;
    int numLine = 0;

    if(mapFile)
    {
        while(getline(mapFile, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == 'b') {
                    newBox = new Box((Vector3){(float)(i*2-14), 1.0f, (float)(numLine*2-14)}, (Vector3){2.0f, 2.0f, 2.0f}, "asset/box.png");
                    _allObjects.push_back(newBox);
                }
                if (line[i] == 'w') {
                    newBox = new Wall((Vector3){(float)(i*2-14), 1.0f, (float)(numLine*2-14)}, (Vector3){2.0f, 2.0f, 2.0f}, "asset/wall.png");
                    _allObjects.push_back(newBox);
                }
                if (line[i] == 'p') {
                    int rd = rand() % 2;
                    if (rd == 0) {
                        newBox = new PowerUp((Vector3){(float)(i*2-14), 1.0f, (float)(numLine*2-14)}, (Vector3){1.6f, 1.6f, 1.6f}, "asset/speed_boost.png", 1);
                        _allObjects.push_back(newBox);
                    } else if (rd == 1) {
                        newBox = new PowerUp((Vector3){(float)(i*2-14), 1.0f, (float)(numLine*2-14)}, (Vector3){1.6f, 1.6f, 1.6f}, "asset/double_bombe.png", 2);
                        _allObjects.push_back(newBox);
                    // } else {
                    //     newBox = new PowerUp((Vector3){(float)(i*2-14), 1.0f, (float)(numLine*2-14)}, (Vector3){1.6f, 1.6f, 1.6f}, "asset/bigger_bombe.png", 3);
                    //     _allObjects.push_back(newBox);
                    }
                }
            }
            numLine++;
        }
    }
    else std::cout << "error opening map file." << std::endl;
}

const std::vector<AObjects*> MainGame::getAllObjects() { return _allObjects; }
const std::vector<BomberMan*> MainGame::getAllBomberMans() { return _bomberMans; }

void MainGame::movements(Core *core)
{
    for (int p = 0; p < _bomberMans.size(); p++)
    {
    int colision = 0;
    BoundingBox bomberMan1 =
    (BoundingBox){  (Vector3){  _bomberMans[p]->getPos().x - _bomberMans[p]->getSize().x/2,
                                _bomberMans[p]->getPos().y - _bomberMans[p]->getSize().y/2,
                                _bomberMans[p]->getPos().z - _bomberMans[p]->getSize().z/2 },
                    (Vector3){  _bomberMans[p]->getPos().x + _bomberMans[p]->getSize().x/2,
                                _bomberMans[p]->getPos().y + _bomberMans[p]->getSize().y/2,
                                _bomberMans[p]->getPos().z + _bomberMans[p]->getSize().z/2 }};
    
    if (IsKeyDown(core->getSave()->getRight(_bomberMans[p]->getId())) && _bomberMans[p]->getAlive() == 1) {
        colision = 0;
        bomberMan1.max.x += 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.x += 0.2f * _bomberMans[p]->getPowerSpeed();
        for (int i = 0; i < _allObjects.size(); i++) {
            if (CheckCollisionBoxes(bomberMan1,
            (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2},
                            (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) {
                bomberMan1.max.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
                if (!CheckCollisionBoxes(bomberMan1,
                (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2},
                                (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) colision += _allObjects[i]->getSolide();
                bomberMan1.max.x += 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.x += 0.2f * _bomberMans[p]->getPowerSpeed();
            }
        }
        if (!colision) {
            _bomberMans[p]->setPosX(_bomberMans[p]->getPosX() + 0.2f * _bomberMans[p]->getPowerSpeed());
            bomberMan1.max.x += 0.2f * _bomberMans[p]->getPowerSpeed();
            bomberMan1.min.x += 0.2f * _bomberMans[p]->getPowerSpeed();
            if (IsKeyDown(core->getSave()->getUp(_bomberMans[p]->getId())) || IsKeyDown(core->getSave()->getDown(_bomberMans[p]->getId()))) {
                _bomberMans[p]->setPosX(_bomberMans[p]->getPosX() - 0.06f * _bomberMans[p]->getPowerSpeed());
                bomberMan1.max.x -= 0.06f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.x -= 0.06f * _bomberMans[p]->getPowerSpeed();
            }
        }
        bomberMan1.max.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
    }

    if (IsKeyDown(core->getSave()->getLeft(_bomberMans[p]->getId())) && _bomberMans[p]->getAlive() == 1) {
        colision = 0;
        bomberMan1.max.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
        for (int i = 0; i < _allObjects.size(); i++) {
            if (CheckCollisionBoxes(bomberMan1,
            (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2 },
                            (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) {
                bomberMan1.max.x += 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.x += 0.2f * _bomberMans[p]->getPowerSpeed();
                if (!CheckCollisionBoxes(bomberMan1,
                (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2},
                                (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) colision += _allObjects[i]->getSolide();
                bomberMan1.max.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
            }
        }
        if (!colision) {_bomberMans[p]->setPosX(_bomberMans[p]->getPosX() - 0.2f * _bomberMans[p]->getPowerSpeed());
            bomberMan1.max.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
            bomberMan1.min.x -= 0.2f * _bomberMans[p]->getPowerSpeed();
            if (IsKeyDown(core->getSave()->getUp(_bomberMans[p]->getId())) || IsKeyDown(core->getSave()->getDown(_bomberMans[p]->getId()))) {
                bomberMan1.max.x += 0.06f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.x += 0.06f * _bomberMans[p]->getPowerSpeed();
                _bomberMans[p]->setPosX(_bomberMans[p]->getPosX() + 0.06f * _bomberMans[p]->getPowerSpeed());
            }
        }
        bomberMan1.max.x += 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.x += 0.2f * _bomberMans[p]->getPowerSpeed();
    }

    if (IsKeyDown(core->getSave()->getDown(_bomberMans[p]->getId())) && _bomberMans[p]->getAlive() == 1) {
        colision = 0;
        bomberMan1.max.z += 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.z += 0.2f * _bomberMans[p]->getPowerSpeed();
        for (int i = 0; i < _allObjects.size(); i++) {
            if (CheckCollisionBoxes(bomberMan1,
            (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2 },
                            (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) {
                bomberMan1.max.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
                if (!CheckCollisionBoxes(bomberMan1,
                (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2},
                                (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) colision += _allObjects[i]->getSolide();
                bomberMan1.max.z += 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.z += 0.2f * _bomberMans[p]->getPowerSpeed();
            }
        }
        if (!colision) {_bomberMans[p]->setPosY(_bomberMans[p]->getPosY() + 0.2f * _bomberMans[p]->getPowerSpeed());
            bomberMan1.max.z += 0.2f * _bomberMans[p]->getPowerSpeed();
            bomberMan1.min.z += 0.2f * _bomberMans[p]->getPowerSpeed();
            if (IsKeyDown(core->getSave()->getLeft(_bomberMans[p]->getId())) || IsKeyDown(core->getSave()->getRight(_bomberMans[p]->getId()))) {
                bomberMan1.max.z -= 0.06f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.z -= 0.06f * _bomberMans[p]->getPowerSpeed();
                _bomberMans[p]->setPosY(_bomberMans[p]->getPosY() - 0.06f * _bomberMans[p]->getPowerSpeed());
            }
        }
        bomberMan1.max.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
    }

    if (IsKeyDown(core->getSave()->getUp(_bomberMans[p]->getId())) && _bomberMans[p]->getAlive() == 1) {
        colision = 0;
        bomberMan1.max.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
        for (int i = 0; i < _allObjects.size(); i++) {
            if (CheckCollisionBoxes(bomberMan1,
            (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2 },
                            (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                        _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                        _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) {
                bomberMan1.max.z += 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.z += 0.2f * _bomberMans[p]->getPowerSpeed();
                if (!CheckCollisionBoxes(bomberMan1,
                (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2},
                                (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                            _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                            _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) colision += _allObjects[i]->getSolide();
                bomberMan1.max.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
            }
        }
        if (!colision) {_bomberMans[p]->setPosY(_bomberMans[p]->getPosY() - 0.2f * _bomberMans[p]->getPowerSpeed());
            bomberMan1.max.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
            bomberMan1.min.z -= 0.2f * _bomberMans[p]->getPowerSpeed();
            if (IsKeyDown(core->getSave()->getLeft(_bomberMans[p]->getId())) || IsKeyDown(core->getSave()->getRight(_bomberMans[p]->getId()))) {
                bomberMan1.max.z += 0.06f * _bomberMans[p]->getPowerSpeed();
                bomberMan1.min.z += 0.06f * _bomberMans[p]->getPowerSpeed();
                _bomberMans[p]->setPosY(_bomberMans[p]->getPosY() + 0.06f * _bomberMans[p]->getPowerSpeed());
            }
        }
        bomberMan1.max.z += 0.2f * _bomberMans[p]->getPowerSpeed();
        bomberMan1.min.z += 0.2f * _bomberMans[p]->getPowerSpeed();
    }
    if (IsKeyPressed(core->getSave()->getUse(_bomberMans[p]->getId())) && _bomberMans[p]->getAlive() == 1) {
        int count = 0;
        int bombePosX = (int)(_bomberMans[p]->getPos().x);
        if (bombePosX < 0) bombePosX--;
        else bombePosX++;
        int bombePosY = (int)(_bomberMans[p]->getPos().z);
        if (bombePosY < 0) bombePosY--;
        else bombePosY++;
        bombePosX = bombePosX / 2;
        bombePosY = bombePosY / 2;

        for (int i = 0; i < _allObjects.size(); i++) {
            if (_allObjects[i]->getId() == _bomberMans[p]->getId()) count++;
        }

        if (count < _bomberMans[p]->getPowerBomb()) {
            AObjects *newBombe = new Bombes((Vector3){(float)(bombePosX * 2), 1.0f, (float)(bombePosY * 2)}, (Vector3){2.0f,2.0f,2.0f}, "asset/tnt.png", _bomberMans[p]->getId());
            _allObjects.push_back(newBombe);
        }
    }
    }
}

void MainGame::colision()
{
    for (int p = 0; p < _bomberMans.size(); p++)
    {
    BoundingBox bomberMan1 =
    (BoundingBox){  (Vector3){  _bomberMans[p]->getPos().x - _bomberMans[p]->getSize().x/2,
                                _bomberMans[p]->getPos().y - _bomberMans[p]->getSize().y/2,
                                _bomberMans[p]->getPos().z - _bomberMans[p]->getSize().z/2 },
                    (Vector3){  _bomberMans[p]->getPos().x + _bomberMans[p]->getSize().x/2,
                                _bomberMans[p]->getPos().y + _bomberMans[p]->getSize().y/2,
                                _bomberMans[p]->getPos().z + _bomberMans[p]->getSize().z/2 }};

    for (int i = 0; i < _allObjects.size(); i++) {
        if (!_allObjects[i]->getSolide() && CheckCollisionBoxes(bomberMan1,
        (BoundingBox){  (Vector3){  _allObjects[i]->getPos().x - _allObjects[i]->getSize().x/2,
                                    _allObjects[i]->getPos().y - _allObjects[i]->getSize().y/2,
                                    _allObjects[i]->getPos().z - _allObjects[i]->getSize().z/2 },
                        (Vector3){  _allObjects[i]->getPos().x + _allObjects[i]->getSize().x/2,
                                    _allObjects[i]->getPos().y + _allObjects[i]->getSize().y/2,
                                    _allObjects[i]->getPos().z + _allObjects[i]->getSize().z/2 }})) {
                                        _bomberMans[p]->takePowerUp((PowerUp*)_allObjects[i]);
                                        _allObjects.erase(std::begin(_allObjects) + i);
                                    }
    }
    }
}

void MainGame::explode()
{
    std::vector<int> suppr;
    std::vector<int> trigger;
    std::vector<int> supprP;
    for (int i = 0; i < _allObjects.size(); i++)
    {
        if (_allObjects[i]->run() == 1)
        {
            suppr.push_back(i);
            for (int j = 0; j < _allObjects.size(); j++)
            {
                if (_allObjects[j]->getDestructible())
                {
                    if (_allObjects[j]->getPosX() == _allObjects[i]->getPosX() &&
                        _allObjects[j]->getPosY() < _allObjects[i]->getPosY() &&
                        _allObjects[j]->getPosY() > _allObjects[i]->getPosY() - (_bomberMans[_allObjects[i]->getId()]->getPowerRange()))
                        {
                            if (_allObjects[j]->isExplose() == 0)
                                suppr.push_back(j);
                            else
                                trigger.push_back(j);
                        }
                    if (_allObjects[j]->getPosX() == _allObjects[i]->getPosX() &&
                        _allObjects[j]->getPosY() > _allObjects[i]->getPosY() &&
                        _allObjects[j]->getPosY() < _allObjects[i]->getPosY() + (_bomberMans[_allObjects[i]->getId()]->getPowerRange()))
                        {
                            if (_allObjects[j]->isExplose() == 0)
                                suppr.push_back(j);
                            else
                                trigger.push_back(j);
                        }
                    if (_allObjects[j]->getPosY() == _allObjects[i]->getPosY() &&
                         _allObjects[j]->getPosX() > _allObjects[i]->getPosX() &&
                         _allObjects[j]->getPosX() < _allObjects[i]->getPosX() + (_bomberMans[_allObjects[i]->getId()]->getPowerRange()))
                        {
                            if (_allObjects[j]->isExplose() == 0)
                                suppr.push_back(j);
                            else
                                trigger.push_back(j);
                        }
                    if (_allObjects[j]->getPosY() == _allObjects[i]->getPosY() &&
                         _allObjects[j]->getPosX() < _allObjects[i]->getPosX() &&
                         _allObjects[j]->getPosX() > _allObjects[i]->getPosX() - (_bomberMans[_allObjects[i]->getId()]->getPowerRange()))
                        {
                            if (_allObjects[j]->isExplose() == 0)
                                suppr.push_back(j);
                            else
                                trigger.push_back(j);
                        }
                }
            }
            for (int j = 0; j < _bomberMans.size(); j++)
            {
                if (_bomberMans[j]->getPosX() < _allObjects[i]->getPosX() + (_bomberMans[_allObjects[i]->getId()]->getPowerRange()) &&
                    _bomberMans[j]->getPosX() > _allObjects[i]->getPosX() - (_bomberMans[_allObjects[i]->getId()]->getPowerRange()) && 
                    _bomberMans[j]->getPosY() < _allObjects[i]->getPosY() &&
                    _bomberMans[j]->getPosY() > _allObjects[i]->getPosY() - (_bomberMans[_allObjects[i]->getId()]->getPowerRange()))
                    {
                        supprP.push_back(_bomberMans[j]->getId());
                    }
                if (_bomberMans[j]->getPosX() < _allObjects[i]->getPosX() + (_bomberMans[_allObjects[i]->getId()]->getPowerRange()) &&
                    _bomberMans[j]->getPosX() > _allObjects[i]->getPosX() - (_bomberMans[_allObjects[i]->getId()]->getPowerRange()) && 
                    _bomberMans[j]->getPosY() < _allObjects[i]->getPosY() &&
                    _bomberMans[j]->getPosY() > _allObjects[i]->getPosY() + (_bomberMans[_allObjects[i]->getId()]->getPowerRange()))
                    {
                        supprP.push_back(_bomberMans[j]->getId());
                    }
                if (_bomberMans[j]->getPosX() < _allObjects[i]->getPosX() + (_bomberMans[_allObjects[i]->getId()]->getPowerRange()) &&
                    _bomberMans[j]->getPosX() > _allObjects[i]->getPosX() - (_bomberMans[_allObjects[i]->getId()]->getPowerRange()) && 
                    _bomberMans[j]->getPosY() < _allObjects[i]->getPosY() + (_bomberMans[_allObjects[i]->getId()]->getPowerRange()) &&
                    _bomberMans[j]->getPosY() > _allObjects[i]->getPosY() - (_bomberMans[_allObjects[i]->getId()]->getPowerRange()))
                    {
                        supprP.push_back(_bomberMans[j]->getId());
                    }
            }
            std::sort(suppr.begin(), suppr.end(), std::greater<int>());
            for (int f = 0; f < suppr.size(); f++)
            {
                _allObjects.erase(std::begin(_allObjects) + suppr[f]);
            }
        }
    }
    for(int g = 0; g < trigger.size(); g++)
    {
        _allObjects[trigger[g]]->explosion();
    }
    for (int h = 0; h < supprP.size(); h++)
    {
        _bomberMans[supprP[h]]->setPosX(-500);
        _bomberMans[supprP[h]]->setPosY(-500);
        _bomberMans[supprP[h]]->setAlive(0);
    }
}

int MainGame::run(Core *core)
{
    movements(core);
    colision();
    routine();
    explode();
    for (int i = 0; i < _bomberMans.size(); i++)
    {
        if (_bomberMans[i]->getAlive() == 0)
        {
            core->getSave()->addWinner(_bomberMans[i]->getId());
        }
    }
    if (core->getSave()->getWinner().size() == 3)
    {
        for (int i = 0; i < _bomberMans.size(); i++)
        {
            if (_bomberMans[i]->getAlive() == 1)
            {
                core->getSave()->addWinner(_bomberMans[i]->getId());
            }
        }
        core->getSave()->prepareWinner();
        core->switchScene(3);
    }
    return 0;
}

int MainGame::routine()
{
    
    // +++ boucle qui run tout les objects
    return 0;
}