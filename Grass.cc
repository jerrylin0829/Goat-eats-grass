#include <bits/stdc++.h>
#include "Grass.h"

const int grassMaxAge = 6;

using namespace std;

//Constructor
Grass::Grass() : Creature('I')
{
        is_acted = false;
}
//Desturctor
Grass::~Grass()
{

}

void
Grass::breed(Creature *cell[20][35], int y, int x)
{
        int num = Creature::getRandomNumber();
        int new_y = y + dy[num];
        int new_x = x + dx[num];
        if(cell[new_y][new_x]->getSign() == NULL){
                cell[new_y][new_x] = new Grass();
        }

}

void
Grass::act(Creature *cell[20][35],int y, int x)
{
        if(cell[y][x]->getIsActed())
                return;

        cell[y][x]->Creature::increaseAge();
        if(cell[y][x]->getAge() >= 3 && cell[y][x]->getAge() <= 5){
                cell[y][x]->breed(cell, y, x);
        }

        cell[y][x]->setIsActed(true);
}

void
Grass::setIsActed(bool _is_act)
{
        is_acted = _is_act;
}

bool
Grass::getIsActed()
{
        return is_acted;
}

bool
Grass::die()
{
        return Creature::getAge() > grassMaxAge;
}

//Grass can't move, but this is virtual function, so I have to do it.
void
Grass::move(Creature *cell[20][35], int y, int x)
{
        //return;
}
