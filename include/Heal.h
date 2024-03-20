#ifndef HEAL_H
#define HEAL_H

#include "Ability.h"
#include "Character.h"

class Heal : public Ability
{
    public:
        Heal(int value);
        void useAbility(Character* user, Character* other) override;
        virtual ~Heal();

    protected:

    private:
};

#endif // HEAL_H
