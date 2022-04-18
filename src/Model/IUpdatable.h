//
// Created by ivan on 12.04.2022.
//

#ifndef SWTOR_IUPDATABLE_H
#define SWTOR_IUPDATABLE_H

class IUpdatable
{
public:
    virtual void update(float deltaTime) = 0;
};

#endif //SWTOR_IUPDATABLE_H
