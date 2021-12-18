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

                //Grass is dead or not
                bool die();

                //Grass breed small grass
                void breed();

        private:

};

#endif
