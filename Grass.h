#ifndef _GRASS_H
#define _GRASS_H

#include <bits/stdc++.h>
#include "Creature.h"

using namespace std;

class Grass : public Creature
{
        public:

                //constructor
                Grass();

                //destructor
                ~Grass();

                //Grass breed small grass
                void breed(Creature *[20][35], int, int);

                //creature pass one time
                void act(Creature *[20][35], int, int);

                //creature is Acted
                void setIsActed(bool);

                //get isActed
                bool getIsActed();

                //creature death or not
                bool die();

                void move(Creature *[20][35], int, int);

        private:
                bool is_acted;
};

#endif
