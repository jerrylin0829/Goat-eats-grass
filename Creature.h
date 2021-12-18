#ifndef _CREATURE_H
#define _CREATURE_H

#include <bits/stdc++.h>
#include "RandomNum.h"

//x-asis and y-asis
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

using namespace std;

class Creature
{
        public:

                //Constructor
                Creature(char);

                //Destructor
                ~Creature();

                //get creature's age
                const int getAge();

                //get creature's sign for X or I
                const char getSign();

                //creature's age plus one
                void increaseAge();

                //creature breed small creature
                virtual void breed(Creature *[20][35], int, int) = 0;

                //set creature bred or not
                virtual void setIsBred(bool);

                virtual void getIsBred();

                //creature move
                virtual void move(Creature *[20][35], int, int) = 0;

                //creature pass one time
                virtual void act(Creature *[20][35], int, int) = 0;

                //creature is Acted
                void setIsActed(bool);

                //get isActed
                bool getIsActed();

                int getRandomNumber();

        private:

                int age;

                //This creature is goat or grass
                char sign;

                bool is_acted;
                bool is_bred;
                RandomNum rand;

};

#endif
