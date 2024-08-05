#ifndef RANDOM_CHARACTER_GENERATOR_H
#define RANDOM_CHARACTER_GENERATOR_H

#include "Character.h"
#include <map>
#include <vector>
#include <string>

class RandomCharacterGenerator
{
private:
    std::vector<std::string> nameList_;
    std::vector<Weapon> weaponList_;
    std::vector<Armor> armorList_;
    std::vector<Armor> shieldList_;         //Can have shield or no shield
    std::vector<std::string> raceList_;
    std::vector<std::string> apperanceFeatureList_;
    std::vector<std::string> professionList_;
    std::vector<CurrentActivity> currentActivityList_;
    std::vector<std::string> alignmentList_ = { "Lawful", "Neutral", "Chaotic", "Good", "Neutral", "Evil" };
    std::vector<std::string> talentList_;
    std::vector<std::string> interactionTraitList_;
    std::vector<std::string> mannerismList_;
    std::vector<std::string> lawfulIdealList_;
    std::vector<std::string> chaoticIdealList_;
    std::vector<std::string> neutralIdealList_;
    std::vector<std::string> goodIdealList_;
    std::vector<std::string> evilIdealList_;
    std::vector<std::string> otherIdealList_;
    std::vector<std::string> bondList_;
    std::vector<std::string> flawList_;
    std::vector<std::string> secretList_;
    std::map<std::string, std::string> interactionTraitSecretMap_;


public:
    RandomCharacterGenerator();

    //overloaded constructor should load in text files for weapons, armor, 
    //race, interaction trait secret map, current activity, appearance, mannerism,
    //ideal, and bond
    RandomCharacterGenerator(std::vector<std::string> files);
    
    //void setSecretMapUse(bool flag);
    bool isValidRace(std::string race);

    //generate functions for each part of a character
    std::string generateName();
    std::vector<int> generateAttributes();
    Weapon generateWeapon();
    Armor generateArmor();
    Armor generateShield(Weapon weapon);
    std::string generateRace();
    std::string generateAppearanceFeature();
    //Profession generateProfession();
    std::string generateProfession();
    CurrentActivity generateCurrentActivity();
    std::pair<std::string, std::string> generateAlignment();
    std::string generateTalent();
    std::string generateInteractionTrait();
    std::string generateMannerism();
    std::string generateIdeal(std::pair<std::string, std::string> alignment);
    std::string generateBond();
    std::string generateFlaw();
    std::string generateSecret();
    //std::string generateSecret(std::string interactionTrait);

    //function to generate a character
    Character generateCharacter();

    //function to generate a character with race
    Character generateCharacterWRace(std::string race);

    //function to write characters to a file with given file name and vector of characters
    void writeCharactersToFile(std::vector<Character> characters);
};

#endif