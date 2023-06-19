
/**
 * @file ch15P4Classes.h
 * @brief CHAPTER15 project4
 * @author 2018203023 박민근
 * @date 2023-06-19
 */

#ifndef _CH15_P4_CLASSES_
#define _CH15_P4_CLASSES_

#include <string>

using namespace std;

namespace hw02 {

    namespace ch15 {

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
                virtual int getDamage() const = 0;

        }; // Creature


        class Elf: public Creature {
            public:
                Elf(  ): Creature(0, 0, "Elf") {  }
                Elf(int str, int h): Creature(str, h, "Elf") {  }
                int getDamage() const override;
        }; // Elf


        class Demon: public Creature {
            public:
                Demon(  ): Creature(0, 0, "Demon") {  }
                Demon(int str, int h): Creature(str, h, "Demon") {  }
                int getDamage() const override;
        }; // Demon


        class Human: public Creature {
            public:
                Human(  ): Creature(0, 0, "Human") {  }
                Human(int str, int h): Creature(str, h, "Human") {  }
                int getDamage() const override;
        }; // Human


        class CyberDemon: public Demon {
            public:
                CyberDemon(  ): Demon() { setSpecies("CyberDemon"); }
                CyberDemon(int str, int h): Demon(str, h) { setSpecies("CyberDemon"); }
                int getDamage() const override;
        }; // CyberDemon


        class Balrog: public Demon {
            public:
                Balrog(  ): Demon() { setSpecies("Balrog"); }
                Balrog(int str, int h): Demon(str, h) { setSpecies("Balrog"); }
                int getDamage() const override;
        }; // CyberDemon
    } // ch15

} // hw02


#endif
