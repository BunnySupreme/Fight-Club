#ifndef RISKYPUNCH_H
#define RISKYPUNCH_H

#include "Ability.h"
#include "Character.h"

class RiskyPunch : public Ability
{
    public:
        RiskyPunch(int value);
        void useAbility(Character* user, Character* other) override;
        virtual ~RiskyPunch();

    protected:

    private:
};

#endif // RISKYPUNCH_H
