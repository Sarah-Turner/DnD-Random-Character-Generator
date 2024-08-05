#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <utility>
#include <vector>

struct Weapon
{
	std::string wName_ = "Mace";
	int damageDice_ = 6;
	int numDice_ = 1;
	bool useDex_ = false;
	bool isOneHanded = true;
	std::string attackText_ = " swings a mace... ";
	std::string criticalHitText_ = " deals a devastating blow with their mace! ";
	std::string hitText_ = " lands a solid hit. ";
	std::string missText_ = "'s mace glances off thier opponent. ";
	std::string criticalMissText_ = " stumbles and misses completely! ";
};

struct Armor
{
	std::string name_ = "Chain Shirt";
	int armorClass_ = 13;
	bool useDexMod_ = true; 
	bool dexModIsCapped_ = true;  // Dex mod is capped at 2
	bool hasStrReq_ = false;
	int strReq_ = 0;
	bool stealthDisadvantage_ = false;
};

struct Stats
{
	int maxHealth_;
	int armorClass_;
	int strength_;
	int dexterity_;
	int constitution_;
	int intelligence_;
	int wisdom_;
	int charisma_;
};

struct Equipment
{
	Weapon weapon_;
    Armor armor_;
	Armor shield_;
};

struct CurrentActivity
{
	std::string currentActivity_;              // One word description of what the character is doing
	std::string description_;                  // Describes in more detail what they are doing (sentence)
	std::string randomDetail_;                 // Additional piece of info that is randomized
	std::vector<std::string> detailList_;      // List of 7 details 1 of which is appended to randomDetail_
};

struct Features
{
	std::string race_;
    std::string appearanceFeature_; 
	std::string profession_;   
    CurrentActivity currentActivity_;                 
    std::pair<std::string, std::string> alignment_;  // First is Lawful, Neutral, Chaotic. Second is Good, Neutral, Evil.
    std::string talent_;
    std::string interactionTrait_;
    std::string mannerism_;
    std::string ideal_;
    std::string bond_;
    std::string flaw_;
	std::string secret_;
};

class Character
{
private:
    std::string name_;
    Stats stats_;
	Equipment equipment_;
	Features features_;

public:
	Character();
	Character(std::string name, Stats stats, Equipment equipment, Features features);
	int getAbilityModifier(int abilityScore) const;
	int getModifiedArmorClass();

	void displayCharacterInfo();

	void setName(std::string name);
	void setMaxHealth(int maxHealth);
	void setArmorClass(int armorClass);
	void setStrength(int strength);
	void setDexterity(int dexterity);
	void setConstitution(int constitution);
	void setIntelligence(int intelligence);
	void setWisdom(int wisdom);
	void setCharisma(int charisma);
	void setWeapon(Weapon weapon);
	void setArmor(Armor armor);
	void setShield(Armor shield);
	void setRace(std::string race);
	void setAppearanceFeature(std::string feature);
	void setProfession(std::string profession);
	void setcurrentActivity(CurrentActivity currentActivity);
	void setAlignment(std::pair<std::string, std::string> alignment);
	void setTalent(std::string talent);
	void setInteractionTrait(std::string interactionTrait);
	void setMannerism(std::string mannerism);
	void setIdeal(std::string ideal);
	void setBond(std::string bond);
	void setFlaw(std::string flaw);
	void setSecret(std::string secret);

	std::string getName() const;
	int getMaxHealth() const;
	int getArmorClass() const;
	int getStrength() const;
	int getDexterity() const;
	int getConstitution() const;
	int getIntelligence() const;
	int getWisdom() const;
	int getCharisma() const;
	Weapon getWeapon() const;
	Armor getArmor() const;
	Armor getShield() const;
	std::string getRace() const;
	std::string getAppearanceFeature() const;
	std::string getProfession() const;
	CurrentActivity getcurrentActivity() const;
	std::pair<std::string, std::string> getAlignment() const;
	std::string getTalent() const;
	std::string getInteractionTrait() const;
	std::string getMannerism() const;
	std::string getIdeal() const;
	std::string getBond() const;
	std::string getFlaw() const;
	std::string getSecret() const;
};



#endif
