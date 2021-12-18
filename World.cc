#include <bits/stdc++.h>
#include "World.h"

const int Length = 20;
const int Width = 35;
const int startGoats = 5;
const int startGrass = 10;

using namespace std;

World::World(int n, int seed):random(seed)
{
        numPasses = n;

        for(int i = 0; i < Length; ++i){
                for(int j = 0; j < Width; ++j){
                        cell[i][j] = NULL;
                }
        }

        //Goats
        for(int i = 0; i < startGoats; ){
                int y = random.getRandomNum(0,Length - 1);
                int x = random.getRandomNum(0,Width - 1);
                if(cell[y][x] == NULL){
                        cell[y][x] = new Goat();
                        i++;
                }
        }

        //Grass
        for(int i = 0; i < startGrass; ){
                int y = random.getRandomNum(0,Length - 1);
                int x = random.getRandomNum(0,Width - 1);
                if(cell[y][x] == NULL){
                        cell[y][x] = new Grass();
                        i++;
                }
        }
}

World::~World()
{

}

void
World::startNewPass()
{
        for(int i = 0; i < Length; ++i){
                for(int j = 0; j < Width; ++j){
                        cell[i][j]->setIsActed(false);
                }
        }
}

/*void
World::act()
{
        for(int i = 0; i < Length; ++i){
                for(int j = 0; j < Width; ++j){
                        int new_i = i + random.getRandomNum(0,3);
                        int new_j = j + random.getRandomNum(0,3);
                        if(cell[i][j]->die())
                                delete cell[i][j];
                        else{
                                if(cell[i][j]->getSign() = 'X' && cell[i][j]->breed()){
                                        if(
                                }
                        }
                }
        }

}*/
void
World::pass()
{
        for(int i = 0; i < Length; ++i){
                for(int j = 0; j < Width; ++j){

                }
        }
}

void
World::mainLoop(int displayInterval)
{
        for(int i = 0; i < numPasses; ++i)
        {
                if(i % displayInterval == 0)
                        print();
                startNewPass();

        }
}

void
World::print()
{
        cout << "  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4" << endl;
        for(int i = 0; i < Length; ++i){
                cout << i%10 << " ";
                for(int j = 0; j < Width; ++j){
                        if(cell[i][j] != NULL){
                                cout << cell[i][j]->getSign() << " ";
                        }
                        else
                                cout << "  ";
                }
                cout << endl;
        }
        cout << "------------------------------------------------------------------------" << endl;
}
