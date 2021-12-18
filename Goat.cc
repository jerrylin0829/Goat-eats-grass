#include <bits/stdc++.h>
#include "Goat.h"
#include "Creature.h"
using namespace std;

const int goatMaxAge = 70;

//Constructor
Goat::Goat() : Creature('X')
{
        foodPoints = 20;
}

//Destructor
Goat::~Goat()
{

}

int
Goat::getFoodPoints()
{
        return foodPoints;
}

/*bool
  Goat::die()
  {
  return Creature::getAge() > goatMaxAge || getFoodPoints() < 0;
  }*/

void
Goat::breed(Creature *cell[20][35], int y, int x)
{
        int num = Creature::getRandomNumber();
        int new_y = y + dy[num];
        int new_x = x + dx[num];
        if(cell[new_y][new_x]->getSign() != 'X'){

                if(cell[new_y][new_x]->getSign() == 'I'){
                        cell[y][x]->foodPoints++;
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

        if(cell[new_y][new_x]->getSign() != 'X'){

                if(cell[new_y][new_x]->getSign() == 'I'){
                        cell[new_y][new_x] == cell[y][x];
                        cell[new_y][new_x]->foodPoints++;
                }
                else if(cell[new_y][new_x] == NULL){
                        cell[new_y][new_x] == cell[y][x];
                        cell[new_y][new_x]->foodPoints--;
                }

                delete cell[y][x];
        }
}
