#include <iostream>
#include <fstream>
#include "RandomCharacterGenerator.h"
#include "dice.h"
RandomCharacterGenerator::RandomCharacterGenerator()
{
    //fill weapon list
    Weapon mace;
    Weapon longsword;
	longsword.wName_ = "Longsword";
    longsword.isOneHanded = true;
	longsword.damageDice_ = 8;
	longsword.numDice_ = 1;
	longsword.useDex_ = false;
	longsword.attackText_ = " swings a longsword... ";
	longsword.criticalHitText_ = " slashes perfectly at their opponent dealing a great blow! ";
	longsword.hitText_ = "'s longsword connects with their opponent. ";
	longsword.missText_ = "'s longsword misses narrowly. ";
	longsword.criticalMissText_ = " overswings and misses completly! ";
	Weapon greatsword;
	greatsword.wName_ = "Greatsword";
    greatsword.isOneHanded = false;
	greatsword.damageDice_ = 6;
	greatsword.numDice_ = 2;
	greatsword.useDex_ = false;
	greatsword.attackText_ = " slashes with a greatsword... ";
	greatsword.criticalHitText_ = " puts all their weight into their attack and cuts a mighty gash into their opponent dealing severe damage! ";
	greatsword.hitText_ = " cuts into their opponent. ";
	greatsword.missText_ = "'s swing comes close to their foe and barely misses. ";
	greatsword.criticalMissText_ = " whirls their greatsword and loses their balance missing completly! ";
	Weapon dagger;
	dagger.wName_ = "Dagger";
    dagger.isOneHanded = true;
	dagger.damageDice_ = 4;
	dagger.numDice_ = 1;
	dagger.useDex_ = true;
	dagger.attackText_ = " stabs with a dagger... ";
	dagger.criticalHitText_ = " expertly thrust their dagger into their opponents weakpoint dealing massive damage! ";
	dagger.hitText_ = " pierces their foe. ";
	dagger.missText_ = "'s dagger glances off their oppenent. ";
	dagger.criticalMissText_ = " stabs into the air making a fool of themself! ";

    this->weaponList_.push_back(mace);
    this->weaponList_.push_back(longsword);
    this->weaponList_.push_back(greatsword);
    this->weaponList_.push_back(dagger);

    //fill armor List
    Armor chainShirt;
    Armor Leather;
    Leather.name_ = "Leather";
    Leather.armorClass_ = 11;
    Leather.useDexMod_ = true;
    Leather.dexModIsCapped_ = false;
    Leather.hasStrReq_ = false;
    Leather.strReq_ = 0;
    Leather.stealthDisadvantage_ = false;
    Armor Hide;
    Hide.name_ = "Hide";
    Hide.armorClass_ = 12;
    Hide.useDexMod_ = true;
    Hide.dexModIsCapped_ = true;
    Hide.hasStrReq_ = false;
    Hide.strReq_ = 0;
    Hide.stealthDisadvantage_ = false;
    Armor scaleMail;
    scaleMail.name_ = "Scale Mail";
    scaleMail.armorClass_ = 14;
    scaleMail.useDexMod_ = true;
    scaleMail.dexModIsCapped_ = true;
    scaleMail.hasStrReq_ = false;
    scaleMail.strReq_ = 0;
    scaleMail.stealthDisadvantage_ = true;
    Armor plate;
    plate.name_ = "Plate";
    plate.armorClass_ = 18;
    plate.useDexMod_ = false;
    plate.dexModIsCapped_ = true;
    plate.hasStrReq_ = true;
    plate.strReq_ = 15;
    plate.stealthDisadvantage_ = true;
    
    this->armorList_.push_back(chainShirt);
    this->armorList_.push_back(Leather);
    this->armorList_.push_back(Hide);
    this->armorList_.push_back(scaleMail);
    this->armorList_.push_back(plate);

    //fill shield List
    Armor noShield;
    noShield.name_ = "None";
    noShield.armorClass_ = 0;
    noShield.useDexMod_ = false;
    noShield.dexModIsCapped_ = true;
    noShield.hasStrReq_ = false;
    noShield.strReq_ = 0;
    noShield.stealthDisadvantage_ = false;
    Armor shield;
    shield.name_ = "Shield";
    shield.armorClass_ = 2;
    shield.useDexMod_ = false;
    shield.dexModIsCapped_ = true;
    shield.hasStrReq_ = false;
    shield.strReq_ = 0;
    shield.stealthDisadvantage_ = false;

    this->shieldList_.push_back(noShield);
    this->shieldList_.push_back(shield);

    //fill appearancefeat list
    std::string ragged = "Ragged, dirty clothes";
    std::string formal = "Formal, clean clothes";
    std::string eye = "Unusual eye color";
    std::string hair = "Braided beard or hair";
    std::string nose = "Distinctive nose";
    std::string posture = "Distinctive posture (crooked or rigid)";
    std::string tattoos = "Tattoos";
    
    this->apperanceFeatureList_.push_back(ragged);
    this->apperanceFeatureList_.push_back(formal);
    this->apperanceFeatureList_.push_back(eye);
    this->apperanceFeatureList_.push_back(hair);
    this->apperanceFeatureList_.push_back(nose);
    this->apperanceFeatureList_.push_back(posture);
    this->apperanceFeatureList_.push_back(tattoos);

    //fill profession list
    std::string innkeeper;
    innkeeper = "Innkeeper";
    //innkeeper.description_ = "Offers up a place to sleep for weary travelers and adventurers.";
    //innkeeper.randomDetail_ = "This establishment is a ";
    //innkeeper.detailList_ = { "Front for criminals", "Rundown flop house", "Simple Inn", "Simple Inn", "Simple Inn", "Fine Inn", "Royal Inn" };
    std::string sailor;
    sailor = "Sailor";
    //sailor.description_ = "Dressed to be out on the open waters, this person is in town for business or on leave.";
    //sailor.randomDetail_ = "Their boat is a ";
    //sailor.detailList_ = { "Pirate Ship", "River Barge", "River Barge", "Merchent Boat", "Fishing Boat", "Fishing Boat", "Warship" };
    std::string farmer;
    farmer = "Farmer";
    //farmer.description_ = "Most farmers are found working their fields or selling crops in town.";
    //farmer.randomDetail_ = "Their current crop is ";
    //farmer.detailList_ = { "Preserves or Pickeled Food", "Preserves or Pickeled Food", "Seasonal Fruit", "Vegetables", "Vegetables", "Fresh Herbs", "Odd Crop" };
    std::string adventurer1;
    adventurer1 = "Adventurer";
    //adventurer1.description_ = "Always headed out on the next quest, this adventurer is an expert is skills and combat.";
    //adventurer1.randomDetail_ = "They are a ";
    //adventurer1.detailList_ = { "Investor", "Alchemist", "Ranger", "Rogue", "Bard", "Investigator", "Investigator" };

    this->professionList_.push_back("innkeeper");
    this->professionList_.push_back("sailor");
    this->professionList_.push_back("farmer");
    this->professionList_.push_back("adventurer1");

    //fill currentactivity list
    CurrentActivity passing;
    passing.currentActivity_ = "Passing Through";
    passing.description_ = "This person is passing through the area, just one stop on a long journey.";
    passing.randomDetail_ = "Their heading on this journey because ";
    passing.detailList_ = { "they are in Exile", "they need to get to a War Front", "they need to meet a friend", "they want to go home", "they want to visit their family", "they want to wander around", "they are in search of their ancestral home" };
    CurrentActivity relaxing;
    relaxing.currentActivity_ = "Relaxing";
    relaxing.description_ = "After a long day of work, this person is just trying to relax, indulging in a simple pleasure.";
    relaxing.randomDetail_ = "They are currently ";
    relaxing.detailList_ = { "daydreaming", "reading a book", "having a drink", "napping", "napping", "daydreaming", "making art" };
    CurrentActivity loitering;
    loitering.currentActivity_ = "Loitering";
    loitering.description_ = "This person is just standing around.";
    loitering.randomDetail_ = "They are ";
    loitering.detailList_ = { "following someone", "casing the nearby building", "trying to avoid the watch", "doing nothing", "looking for someone", "waiting for a secret meeting", "an elaborate illusion casted by a mage" };

    this->currentActivityList_.push_back(passing);
    this->currentActivityList_.push_back(relaxing);
    this->currentActivityList_.push_back(loitering);

    //fill talent list
    std::string t1 = "Plays musical instrument";
    std::string t2 = "Unbelievably lucky";
    std::string t3 = "Great with animals";
    std::string t4 = "Expert juggler";
    std::string t5 = "Drinks everyone under the table";
    std::string t6 = "Great at solving puzzles";

    this->talentList_.push_back(t1);
    this->talentList_.push_back(t2);
    this->talentList_.push_back(t3);
    this->talentList_.push_back(t4);
    this->talentList_.push_back(t5);
    this->talentList_.push_back(t6);

    //fill interaction trait list
    std::string i1 = "Mean";
    std::string i2 = "Clumsy";
    std::string i3 = "Bad Jokes";
    std::string i4 = "Empathetic";
    std::string i5 = "Friendly";
    this->interactionTraitList_.push_back(i1);
    this->interactionTraitList_.push_back(i2);
    this->interactionTraitList_.push_back(i3);
    this->interactionTraitList_.push_back(i4);
    this->interactionTraitList_.push_back(i5);

    

    //fill mannerism list
    std::string m1 = "Prone to singing, whistling, or humming quietly";
    std::string m2 = "Slurs words, lisps, or stutters";
    std::string m3 = "Enunciates overly clearly";
    std::string m4 = "Speaks loudly";
    std::string m5 = "Whispers";
    std::string m6 = "Uses colorful oaths or exclamations";
    std::string m7 = "Fidgets";
    std::string m8 = "Taps fingers";
    std::string m9 = "Squints";

    this->mannerismList_.push_back(m1);
    this->mannerismList_.push_back(m2);
    this->mannerismList_.push_back(m3);
    this->mannerismList_.push_back(m4);
    this->mannerismList_.push_back(m5);
    this->mannerismList_.push_back(m6);
    this->mannerismList_.push_back(m7);
    this->mannerismList_.push_back(m8);
    this->mannerismList_.push_back(m9);

    //fill ideal list
    this->lawfulIdealList_ = { "Honor", "Logic", "Responsibility", "Community", "Fairness" };
    this->neutralIdealList_ = { "Knowledge", "Balance", "Live and let live" };
    this->chaoticIdealList_ = { "Change", "Freedom", "Independence", "No limits" };
    this->goodIdealList_ = { "Beauty", "Greater good", "Life", "Self sacrifice", "Charity" };
    this->otherIdealList_ = { "Discovery", "Glory", "Redemption", "Nation" };
    this->evilIdealList_ = { "Domination", "Greed", "Might", "Pain", "Retribution", "Slaughter" };
    
    //fill bond list
    std::string b1 = "Dedicated to fulfilling a personal life goal";
    std::string b2 = "Protective of close family members";
    std::string b3 = "Protective of colleagues or compatriots";
    std::string b4 = "Loyal to a benefactor, patron, or employer";
    std::string b5 = "Captivated by a romantic interest";
    std::string b6 = "Drawn to a special place";
    std::string b7 = "Protective of a sentimental keepsake";
    std::string b8 = "Protective ofa valuable possession";
    std::string b9 = "Out for revenge";

    this->bondList_.push_back(b1);
    this->bondList_.push_back(b2);
    this->bondList_.push_back(b3);
    this->bondList_.push_back(b4);
    this->bondList_.push_back(b5);
    this->bondList_.push_back(b6);
    this->bondList_.push_back(b7);
    this->bondList_.push_back(b8);
    this->bondList_.push_back(b9);

    //fill flaw list
    std::string f1 = "Forbidden love or susceptibility to romance";
    std::string f2 = "Enjoys decadent pleasures";
    std::string f3 = "Arrogance";
    std::string f4 = "Envies another creature's possessions or station";
    std::string f5 = "Overpowering greed";
    std::string f6 = "Prone to rage";
    std::string f7 = "Has a powerful enemy";
    std::string f8 = "Specific phobia";
    std::string f9 = "Shameful or scandalous history";
    std::string f10 = "Secret crime or misdeed";
    std::string f11 = "Foolhardy bravery";

    this->flawList_.push_back(f1);
    this->flawList_.push_back(f2);
    this->flawList_.push_back(f3);
    this->flawList_.push_back(f4);
    this->flawList_.push_back(f5);
    this->flawList_.push_back(f6);
    this->flawList_.push_back(f7);
    this->flawList_.push_back(f8);
    this->flawList_.push_back(f9);
    this->flawList_.push_back(f10);
    this->flawList_.push_back(f11);

    //fill secret list
    std::string s1 = "This person is dealing with a horrifying family tragedy, and they are not dealing with it well.";
    std::string s2 = "A terrible curse was placed on this person years ago for a personal slight, making them extremely clumsy.";
    std::string s3 = "This person secretly wants to quit their job and become an entertainer.";
    std::string s4 = "This person is secretly gathering information about a specific person.";
    std::string s5 = "This person is selling something and their attitude is there to draw in customers.";
    
    this->secretList_.push_back(s1);
    this->secretList_.push_back(s2);
    this->secretList_.push_back(s3);
    this->secretList_.push_back(s4);
    this->secretList_.push_back(s5);

    //fill interactionTraitSecret Map vectors should line up
    this->interactionTraitSecretMap_[i1] = s1;
    this->interactionTraitSecretMap_[i2] = s2;
    this->interactionTraitSecretMap_[i3] = s3;
    this->interactionTraitSecretMap_[i4] = s4;
    this->interactionTraitSecretMap_[i5] = s5;

}


//overloaded constructor loads information from text files
RandomCharacterGenerator::RandomCharacterGenerator(std::vector<std::string> files)
{
    for (std::string file : files)
    {
        //load file of names
        if (file == "names.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string name;
                while (infile >> name)
                {
                    this->nameList_.push_back(name);
                }
                infile.close();
            }

        }

        //load file of weapons
        if (file == "weapons.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string name;
                int dmgDice;
                int numDice;
                bool useDex;
                bool isOneHanded;
                std::string attackText;
                std::string critText;
                std::string hitText;
                std::string missText;
                std::string critMissText;
                std::string temp;

                while (getline(infile, name))
                {
                    getline(infile, temp);
                    dmgDice = stoi(temp);
                    getline(infile, temp);
                    numDice = stoi(temp);
                    getline(infile, temp);
                    useDex = stoi(temp);
                    getline(infile, temp);
                    isOneHanded = stoi(temp);
                    getline(infile, attackText);
                    getline(infile, critText);
                    getline(infile, hitText);
                    getline(infile, missText);
                    getline(infile, critMissText);

                    Weapon weapon;
                    weapon.wName_ = name;
                    weapon.damageDice_ = dmgDice;
                    weapon.numDice_ = numDice;
                    weapon.useDex_ = useDex;
                    weapon.isOneHanded = isOneHanded;
                    weapon.attackText_ = attackText;
                    weapon.criticalHitText_ = critText;
                    weapon.hitText_ = hitText;
                    weapon.missText_ = missText;
                    weapon.criticalMissText_ = critMissText;
                    this->weaponList_.push_back(weapon);
                }
                infile.close();
            }
        }

        //load file of armor
        if (file == "armors.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string name;
                int armorClass;
                bool useDexMod;
                bool dexModIsCapped;
                bool hasStrReq;
                int strReq;
                bool stealthDisadvantage;
                std::string temp;

                while (getline(infile, name))
                {
                    getline(infile, temp);
                    armorClass = stoi(temp);
                    getline(infile, temp);
                    useDexMod = stoi(temp);
                    getline(infile, temp);
                    dexModIsCapped = stoi(temp);
                    getline(infile, temp);
                    hasStrReq = stoi(temp);
                    getline(infile, temp);
                    strReq = stoi(temp);
                    getline(infile, temp);
                    stealthDisadvantage = stoi(temp);

                    Armor armor;
                    armor.name_ = name;
                    armor.armorClass_ = armorClass;
                    armor.useDexMod_ = useDexMod;
                    armor.dexModIsCapped_ = dexModIsCapped;
                    armor.hasStrReq_ = hasStrReq;
                    armor.strReq_ = strReq;
                    armor.stealthDisadvantage_ = stealthDisadvantage;
                    this->armorList_.push_back(armor);
                }
                infile.close();
            }
        }

        //load file of shield
        if (file == "shields.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string name;
                int armorClass;
                bool useDexMod;
                bool dexModIsCapped;
                bool hasStrReq;
                int strReq;
                bool stealthDisadvantage;

                while (infile >> name)
                {
                    infile >> armorClass;
                    infile >> useDexMod;
                    infile >> dexModIsCapped;
                    infile >> hasStrReq;
                    infile >> strReq;
                    infile >> stealthDisadvantage;

                    Armor shield;
                    shield.name_ = name;
                    shield.armorClass_ = armorClass;
                    shield.useDexMod_ = useDexMod;
                    shield.dexModIsCapped_ = dexModIsCapped;
                    shield.hasStrReq_ = hasStrReq;
                    shield.strReq_ = strReq;
                    shield.stealthDisadvantage_ = stealthDisadvantage;
                    this->shieldList_.push_back(shield);
                }
                infile.close();
            }
        }

        //load file of races
        if (file == "races.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string race;

                while (infile >> race)
                {
                    this->raceList_.push_back(race);
                }
                infile.close();
            }
        }

        //load file of appearance features
        if (file == "appearanceFeatures.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string feature;
                while (getline(infile, feature))
                {
                    this->apperanceFeatureList_.push_back(feature);
                }
                infile.close();
            }
        }

        //load file of professions
        if (file == "professions.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string profession;
                while (getline(infile, profession))
                {
                    this->professionList_.push_back(profession);
                }
                infile.close();
            }
        }

        //load file of current activities
        if (file == "currentActivities.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string currentActivity;
                std::string description;
                std::string randomDetail;
                std::vector<std::string> detailList;

                while (getline(infile, currentActivity))
                {
                    getline(infile, description);
                    getline(infile, randomDetail);
                    for (int i = 0; i < 7; ++i)
                    {   
                        std::string detailListItem;
                        getline(infile, detailListItem);
                        detailList.push_back(detailListItem);
                    }
                    CurrentActivity activity;
                    activity.currentActivity_ = currentActivity;
                    activity.description_ = description;
                    activity.randomDetail_ = randomDetail;
                    activity.detailList_ = detailList;
                    this->currentActivityList_.push_back(activity);
                }
                infile.close();
            }
        }

        //load file of talents
        if (file == "talents.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string talent;
                while (getline(infile, talent))
                {
                    this->talentList_.push_back(talent);
                }
                infile.close();
            }
        }

        //load file of interaction traits
        if (file == "interactionTraits.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string interactionTrait;

                while (getline(infile, interactionTrait))
                {
                    this->interactionTraitList_.push_back(interactionTrait);
                }
                infile.close();
            }
        }

        //load file of secrets
        if (file == "secrets.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string secret;

                while (getline(infile, secret))
                {
                    this->secretList_.push_back(secret);
                }
                infile.close();
            }
        }

        //load file of mannerism
        if (file == "mannerisms.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string mannerism;

                while (getline(infile, mannerism))
                {
                    this->mannerismList_.push_back(mannerism);
                }
                infile.close();
            }
        }

        //load file of lawful ideals
        if (file == "lawfulIdeals.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string ideal;

                while (getline(infile, ideal))
                {
                    this->lawfulIdealList_.push_back(ideal);
                }
                infile.close();
            }
        }

        //load file of chaotic ideals
        if (file == "chaoticIdeals.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string ideal;

                while (getline(infile, ideal))
                {
                    this->chaoticIdealList_.push_back(ideal);
                }
                infile.close();
            }
        }

        //load file of neutral ideals
        if (file == "neutralIdeals.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string ideal;

                while (getline(infile, ideal))
                {
                    this->neutralIdealList_.push_back(ideal);
                }
                infile.close();
            }
        }

        //load file of good ideals
        if (file == "goodIdeals.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string ideal;

                while (getline(infile, ideal))
                {
                    this->goodIdealList_.push_back(ideal);
                }
                infile.close();
            }
        }

        //load file of evil ideals
        if (file == "evilIdeals.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string ideal;

                while (getline(infile, ideal))
                {
                    this->evilIdealList_.push_back(ideal);
                }
                infile.close();
            }
        }

        //load file of other ideals
        if (file == "otherIdeals.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string ideal;

                while (getline(infile, ideal))
                {
                    this->otherIdealList_.push_back(ideal);
                }
                infile.close();
            }
        }

        //load file of bonds
        if (file == "bonds.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string bond;

                while (getline(infile, bond))
                {
                    this->bondList_.push_back(bond);
                }
                infile.close();
            }
        }

        //load file of flaws
        if (file == "flaws.txt")
        {
            std::ifstream infile{file};
            if (!infile)
            {
                std::cout << "Could not open file: " << file << std::endl;
            }
            else
            {
                std::string flaw;

                while (getline(infile, flaw))
                {
                    this->flawList_.push_back(flaw);
                }
                infile.close();
            }
        }
    }
    
}

bool RandomCharacterGenerator::isValidRace(std::string race)
{
    for(std::string currentRace : this->raceList_)
    {
        if (currentRace == race)
        {
            return true;
        }
    }
    return false;
}

std::string RandomCharacterGenerator::generateName()
{
    return this->nameList_[randomBetween(0, this->nameList_.size() - 1)];
}

// Generates a vector of random attributes
std::vector<int> RandomCharacterGenerator::generateAttributes()
{
    std::vector<int> vStats;
	for (int i = 0; i < 6; i++)
	{
		int value = rollStat();
		vStats.push_back(value);
	}
	return vStats;
}

Weapon RandomCharacterGenerator::generateWeapon()
{
    return this->weaponList_[randomBetween(0, this->weaponList_.size() - 1)];
}

Armor RandomCharacterGenerator::generateArmor()
{
    return this->armorList_[randomBetween(0, this->armorList_.size() - 1)];
}

Armor RandomCharacterGenerator::generateShield(Weapon weapon)
{
    if (weapon.isOneHanded)
    {
        return this->shieldList_[randomBetween(0, this->shieldList_.size() - 1)];
    }
    else
    {
        return this->shieldList_[0];  // No shield
    }
}

std::string RandomCharacterGenerator::generateRace()
{
    return this->raceList_[randomBetween(0, this->raceList_.size() - 1)];
}

std::string RandomCharacterGenerator::generateAppearanceFeature()
{
    return this->apperanceFeatureList_[randomBetween(0, this->apperanceFeatureList_.size() - 1)];
}

std::string RandomCharacterGenerator::generateProfession()
{
    std::string profession = this->professionList_[randomBetween(0, this->professionList_.size() - 1)];
    return profession;
}

CurrentActivity RandomCharacterGenerator::generateCurrentActivity()
{
    CurrentActivity activity = this->currentActivityList_[randomBetween(0, this->currentActivityList_.size() - 1)];
    activity.randomDetail_ += activity.detailList_[randomBetween(0, activity.detailList_.size() - 1)];
    return activity;
}

std::pair<std::string, std::string> RandomCharacterGenerator::generateAlignment()
{
    std::string first = this->alignmentList_[randomBetween(0, 2)];
    std::string second = this->alignmentList_[randomBetween(3, 5)];
    std::pair<std::string, std::string> alignment(first, second);
    return alignment;
}

std::string RandomCharacterGenerator::generateTalent()
{
    return this->talentList_[randomBetween(0, this->talentList_.size() - 1)];
}

std::string RandomCharacterGenerator::generateInteractionTrait()
{
    return this->interactionTraitList_[randomBetween(0, this->interactionTraitList_.size() - 1)];
}

std::string RandomCharacterGenerator::generateMannerism()
{
    return this->mannerismList_[randomBetween(0, this->mannerismList_.size() - 1)];
}

std::string RandomCharacterGenerator::generateIdeal(std::pair<std::string, std::string> alignment)
{
    std::string ideal;
    int choice = randomBetween(0, 2);
    std::string idealModifier;
    if (choice == 0)
    {
        idealModifier = alignment.first;
    }
    else if (choice == 1)
    {
        idealModifier = alignment.second;
    }
    else if (choice == 2)
    {
        idealModifier = "Other";
    }

    if (idealModifier == "Lawful")
    {
        ideal = this->lawfulIdealList_[randomBetween(0, this->lawfulIdealList_.size() - 1)];
    }
    else if (idealModifier == "Neutral")
    {
        ideal = this->neutralIdealList_[randomBetween(0, this->neutralIdealList_.size() - 1)];
    }
    else if (idealModifier == "Chaotic")
    {
        ideal = this->chaoticIdealList_[randomBetween(0, this->chaoticIdealList_.size() - 1)];
    }
    else if (idealModifier == "Good")
    {
        ideal = this->goodIdealList_[randomBetween(0, this->goodIdealList_.size() - 1)];
    }
    else if (idealModifier == "Evil")
    {
        ideal = this->evilIdealList_[randomBetween(0, this->evilIdealList_.size() - 1)];
    }
    else if (idealModifier == "Other")
    {
        ideal = this->otherIdealList_[randomBetween(0, this->otherIdealList_.size() - 1)];
    }

    return ideal;
}

std::string RandomCharacterGenerator::generateBond()
{
    return this->bondList_[randomBetween(0, this->bondList_.size() - 1)];
}

std::string RandomCharacterGenerator::generateFlaw()
{
    return this->flawList_[randomBetween(0, this->flawList_.size() - 1)];
}

std::string RandomCharacterGenerator::generateSecret()
{
    return this->secretList_[randomBetween(0, this->secretList_.size() - 1)];
}

//std::string RandomCharacterGenerator::generateSecret(std::string interactionTrait)
//{
//    return interactionTraitSecretMap_[interactionTrait];
//}

Character RandomCharacterGenerator::generateCharacter()
{
    Character randomCharacter;
    // Generate Name, Stats, and Equipment
    randomCharacter.setName(generateName());
    std::vector<int> attributes = generateAttributes();
    randomCharacter.setStrength(attributes[0]);
    randomCharacter.setDexterity(attributes[1]);
    randomCharacter.setConstitution(attributes[2]);
    randomCharacter.setIntelligence(attributes[3]);
    randomCharacter.setWisdom(attributes[4]);
    randomCharacter.setCharisma(attributes[5]);
    randomCharacter.setWeapon(generateWeapon());

    Armor armor = generateArmor();
    bool requirementNotMet = true;
    while (requirementNotMet)
    {
        if (armor.hasStrReq_)
        {
            if (armor.strReq_ > randomCharacter.getStrength())
            {
                requirementNotMet = true;
                armor = generateArmor();
            }
            else
            {
                requirementNotMet = false;
            }
        }
        else
        {
            requirementNotMet = false;
        }
    }
    randomCharacter.setArmor(armor);
    randomCharacter.setShield(generateShield(randomCharacter.getWeapon()));
    randomCharacter.setArmorClass(randomCharacter.getModifiedArmorClass());
    randomCharacter.setMaxHealth(10 + randomCharacter.getAbilityModifier(randomCharacter.getConstitution()));

    // Generate Features
    randomCharacter.setRace(generateRace());
    randomCharacter.setAppearanceFeature(generateAppearanceFeature());
    randomCharacter.setProfession(generateProfession());
    randomCharacter.setcurrentActivity(generateCurrentActivity());
    randomCharacter.setAlignment(generateAlignment());
    randomCharacter.setTalent(generateTalent());
    randomCharacter.setInteractionTrait(generateInteractionTrait());
    randomCharacter.setMannerism(generateMannerism());
    randomCharacter.setIdeal(generateIdeal(randomCharacter.getAlignment()));
    randomCharacter.setBond(generateBond());
    randomCharacter.setFlaw(generateFlaw());
    randomCharacter.setSecret(generateSecret());

    return randomCharacter;
}

Character RandomCharacterGenerator::generateCharacterWRace(std::string race)
{
    Character randomCharacter = generateCharacter();
    randomCharacter.setRace(race);
    return randomCharacter;
}

void RandomCharacterGenerator::writeCharactersToFile(std::vector<Character> characters)
{
    std::ofstream outFile{"Saved Characters.txt"};
    for (int i = 0; i < static_cast<int>(characters.size()); ++i)
    {
        Character character = characters[i];
        outFile << "Character #" << i + 1 << ":" << std::endl;
        outFile << "==========================================================================\n";
        outFile << "Name: " << character.getName() << std::endl << std::endl;
        outFile << "Stats:\n";
        outFile << "Max Health: " << character.getMaxHealth() << std::endl;
        outFile << "Armor Class: " << character.getArmorClass() << std::endl;
        outFile << "Strength: " << character.getStrength() << std::endl;
        outFile << "Dexterity: " << character.getDexterity() << std::endl;
        outFile << "Constitution: " << character.getConstitution() << std::endl;
        outFile << "Intelligence: " << character.getIntelligence() << std::endl;
        outFile << "Wisdom: " << character.getWisdom() << std::endl;
        outFile << "Charisma: " << character.getCharisma() << std::endl;
        outFile << std::endl;

        outFile << "Equipment:\n";
        outFile << "Weapon: " << character.getWeapon().wName_ << std::endl;
        outFile << "Armor: " << character.getArmor().name_ << std::endl;
        outFile << "Shield: " << character.getShield().name_ << std::endl;
        outFile << std::endl;

        outFile << "Features:\n";
        outFile << "Race: " << character.getRace() << std::endl;
        outFile << "Appearance Feature: " << character.getAppearanceFeature() << std::endl;
        outFile << "Profession: " << character.getProfession() << std::endl;
        outFile << "Current Activity: " << character.getcurrentActivity().currentActivity_ << std::endl;
        outFile << "\t" << character.getcurrentActivity().description_ << std::endl;
        outFile << "\t" << character.getcurrentActivity().randomDetail_ << std::endl;
        outFile << "Alignment: " << character.getAlignment().first << ", " << character.getAlignment().second << std::endl;
        outFile << "Talent: " << character.getTalent() << std::endl;
        outFile << "Interaction Trait: " << character.getInteractionTrait() << std::endl;
        outFile << "Mannerism: " << character.getMannerism() << std::endl;
        outFile << "Ideal: " << character.getIdeal() << std::endl;
        outFile << "Bond: " << character.getBond() << std::endl;
        outFile << "Flaw: " << character.getFlaw() << std::endl;
        outFile << "Secret: " << character.getSecret() << std::endl;
        outFile << "**************************************************************************\n";  
        outFile << std::endl << std::endl << std::endl;
    }
    outFile.close();
}