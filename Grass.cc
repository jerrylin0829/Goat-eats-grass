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
        if((new_y < 0 || new_y >= 20) || (new_x < 0 || new_x >= 35)){
                //cout << " grass exceed bound" << endl;
                return;
        }

        if(cell[new_y][new_x] == NULL){
                //cout << "can breed grass?" << endl;
                cell[new_y][new_x] = new Grass();
                //cout << "Yes" << endl;
        }

}

void
Grass::act(Creature *cell[20][35],int y, int x)
{
        if(cell[y][x]->getIsActed())
                return;

        cell[y][x]->Creature::increaseAge();
        cell[y][x]->setIsActed(true);
        //cout << "grass:"<< age <<endl;
        if(cell[y][x]->getAge() >= 3 && cell[y][x]->getAge() <= 5){
                cell[y][x]->breed(cell, y, x);
        }
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
