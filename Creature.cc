#include <bits/stdc++.h>
#include "Creature.h"
#include "RandomNum.h"

using namespace std;

Creature::Creature(char s)
{
        age = 0;
        sign = s;
        is_acted = false;
}

Creature::~Creature()
{

}

const int
Creature::getAge()
{
        return age;
}

const char
Creature::getSign()
{
        return sign;
}

void
Creature::increaseAge()
{
        ++age;
}

int
Creature::getRandomNumber()
{
        return rand.getRandomNum(0,3);
}
