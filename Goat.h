#ifndef _GOAT_H
#define _GOAT_H
#include <bits/stdc++.h>
#include "Creature.h"

using namespace std;

class Goat : public Creature
{
        public:

                        //Constructor
                        Goat();

                        //Destructor
                        ~Goat();

                        //get Goat's food points;
                        int getFoodPoints();

                        //Goat breed small goat
                        void breed(Creature *[20][35], int, int);

                        //Goat move
                        void move(Creature *[20][35], int, int);

        private:

                        int foodPoints;

};

#endif
