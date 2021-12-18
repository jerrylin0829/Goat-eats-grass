#ifndef _WORLD_H
#define _WORLD_H

#include <bits/stdc++.h>
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
#include "RandomNum.h"
using namespace std;

class World{

        public:

                //Constructor
                World(int, int);

                //Destructor
                ~World();

                // a new turn
                void startNewPass();

                //All of creature passed
                void pass();

                //
                virtual void mainLoop(int);

                void print();


        private:

                int numPasses;
                Creature *cell[20][35];
                RandomNum random;
};
#endif
