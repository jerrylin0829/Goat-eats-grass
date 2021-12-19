#include <bits/stdc++.h>
#include "Goat.h"
#include "Creature.h"
using namespace std;

const int goatMaxAge = 70;

//Constructor
Goat::Goat() : Creature('X')
{
        foodPoints = 20;
        is_acted = false;
}

//Destructor
Goat::~Goat()
{

}

void
Goat::breed(Creature *cell[20][35], int y, int x)
{
        int num = Creature::getRandomNumber();
        int new_y = y + dy[num];
        int new_x = x + dx[num];

        if((new_y < 0 || new_y >= 20) || (new_x < 0 || new_x >= 35)){
                cout << "goat's breed exceed bound" << endl;
                return;
        }
        if(cell[new_y][new_x]->getSign() != 'X'){

                if(cell[new_y][new_x]->getSign() == 'I'){
                        foodPoints+=5;
                        delete cell[new_y][new_x];
                }

                cell[new_y][new_x] = new Goat();
        }
}

void
Goat::move(Creature *cell[20][35], int y, int x)
{
        int num = Creature::getRandomNumber();
        int new_y = y + dy[num];
        int new_x = x + dx[num];

        if((new_y < 0 || new_y >= 20) || (new_x < 0 || new_x >= 35)){
                cout << "goat's move exceed bound" << endl;
                return;
        }
        if(cell[new_y][new_x] == NULL){
                cell[new_y][new_x] = cell[y][x];
        }
        else if(cell[new_y][new_x]->getSign() == 'I'){
                cell[new_y][new_x] = cell[y][x];
                foodPoints+=5;
        }

        cell[y][x] = NULL;
}
void
Goat::act(Creature *cell[20][35], int y, int x)
{
        if(cell[y][x]->getIsActed())
                return;

        cell[y][x]->Creature::increaseAge();
        cell[y][x]->setIsActed(true);
        foodPoints--;

        if(cell[y][x]-> Creature::getAge() >= 55 && cell[y][x]-> Creature::getAge() <= 60){
                cell[y][x]->breed(cell, y, x);
        }else{
                cell[y][x]->move(cell, y, x);
                cout << "hi" << endl;
        }
}

void
Goat::setIsActed(bool _is_act)
{
        is_acted = _is_act;
}

bool
Goat::getIsActed()
{
        return is_acted;
}

bool
Goat::die()
{
  return Creature::getAge() > goatMaxAge || foodPoints == 0;
}
