#ifndef PUNCH_H
#define PUNCH_H
#include "Ability.h"
#include "Character.h"


class Punch : public Ability
{
    public:
        Punch(int value);
        void useAbility(Character* user, Character* other) override;
        virtual ~Punch();

    protected:

    private:
};

#endif // PUNCH_H
