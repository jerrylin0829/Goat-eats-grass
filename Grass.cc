#include <bits/stdc++.h>
#include "Grass.h"

const int grassMaxAge = 6;

using namespace std;

//Constructor
Grass::Grass() : Creature('I')
{

}
//Desturctor
Grass::~Grass()
{

}

void
Goat::breed(Creature *cell[20][35], int y, int x)
{
        int num = Creature::getRandomNumber();
        int new_y = y + dy[num];
        int new_x = x + dx[num];
        if(cell[new_y][new_x]->getSign() == NULL){
                cell[new_y][new_x] = new Grass();
        }

}
