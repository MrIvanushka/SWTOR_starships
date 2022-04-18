//
// Created by ivan on 17.04.22.
//

#ifndef SWTOR_SHOOTINGHANDLER_H
#define SWTOR_SHOOTINGHANDLER_H

#include <queue>

#include "../Engine/GameObject.h"
#include "../Model/Observer.h"
#include "../Model/Bullet.h"
#include "Presenter.h"

class ShootingHandler : public Component, public ArgObserver<Bullet*>
{
private:
    std::queue<BulletPresenter*> bulletPool;
public:
    ShootingHandler(GameObject* object) : Component(object)
    {}

    void initialize(std::queue<BulletPresenter*> bulletPool)
    {
        this->bulletPool = bulletPool;
    }

    void handle(ArgObservable<Bullet*>& observable, Bullet* arg) override
    {
        BulletPresenter* bullet = bulletPool.front();
        bulletPool.pop();
        bullet->activate(arg);
        bullet->enabled = true;
        bulletPool.push(bullet);
    }
};

#endif //SWTOR_SHOOTINGHANDLER_H
