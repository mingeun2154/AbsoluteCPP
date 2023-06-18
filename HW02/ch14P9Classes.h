/**
 * @file p9Classes.h
 * @brief CHAPTER14 project9
 * @author 2018203023 박민근
 * @date 2023-06-17
 */

#ifndef _P9_CLASSES_
#define _P9_CLASSES_

#include <string>

using namespace std;

namespace hw02 {

    namespace ch14 {

        class Creature {
            private:
                int strength;
                int hitpoints;
                string species;
            protected:
                bool triggeredByProbability(double p) const;
                // int randomNumber(int limit);
            public:
                int randomNumber(int limit) const;
                Creature(  )
                    : strength(0), hitpoints(0), species("none") {  }
                Creature(int str, int hit, string s)
                    : strength(str), hitpoints(hit), species(s) {  }
                void setStr(int s) { strength = s; }
                void setHit(int h) { hitpoints = h; }
                void setSpecies(string s) { species = s; }
                int getStr() const { return strength; }
                int getHit() const { return hitpoints; }
                string getSpecies() const { return species; }
                int getDamage() const;

        }; // Creature


        class Elf: public Creature {
            public:
                Elf(  ): Creature(0, 0, "Elf") {  }
                Elf(int str, int h): Creature(str, h, "Elf") {  }
                int getDamage() const;
        }; // Elf


        class Demon: public Creature {
            public:
                Demon(  ): Creature(0, 0, "Demon") {  }
                Demon(int str, int h): Creature(str, h, "Demon") {  }
                int getDamage() const;
        }; // Demon


        class Human: public Creature {
            public:
                Human(  ): Creature(0, 0, "Human") {  }
                Human(int str, int h): Creature(str, h, "Human") {  }
                int getDamage() const;
        }; // Human


        class CyberDemon: public Demon {
            public:
                CyberDemon(  ): Demon() { setSpecies("CyberDemon"); }
                CyberDemon(int str, int h): Demon(str, h) { setSpecies("CyberDemon"); }
                int getDamage() const;
        }; // CyberDemon


        class Balrog: public Demon {
            public:
                Balrog(  ): Demon() { setSpecies("Balrog"); }
                Balrog(int str, int h): Demon(str, h) { setSpecies("Balrog"); }
                int getDamage() const;
        }; // CyberDemon
    } // ch14

} // hw02


#endif
