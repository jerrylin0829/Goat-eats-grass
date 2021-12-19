#include <bits/stdc++.h>
#include "World.h"

const int Length = 20;
const int Width = 35;
const int startGoats = 5;
const int startGrass = 10;
const int goatMaxAge = 70;
const int grassMaxAge = 6;

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
                        if(cell[i][j]!=NULL)
                                cell[i][j]->setIsActed(false);
                }
        }
}

void
World::pass()
{
        for(int i = 0; i < Length; ++i){
                for(int j = 0; j < Width; ++j){

                        if(cell[i][j]!=NULL){
                                //cell[i][j]->act(cell, i, j);
                                //cout << cell[i][j]->getAge() << endl;

                                if(cell[i][j]->die()){
                                        //cout << "true die" << endl;
                                        delete[] cell[i][j];
                                }
                                else{
                                        //cout << "don't die" << endl;
                                        cell[i][j]->act(cell, i, j);
                                }
                                //cout << "debug" << endl;
                        }
                }
        }
}

void
World::mainLoop(int displayInterval)
{
        for(int i = 0; i < numPasses; ++i)
        {
                startNewPass();

                if(i % displayInterval == 0)
                        print();

                pass();
                //cout << "gg " << i << endl;
                //print();
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
