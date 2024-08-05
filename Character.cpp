#include <iostream>
#include "Character.h"

//hit die for fighter 10 + const modifier
//AC 10 + dex mod (unarmored)
//ability score choose from 15, 14, 13, 12, 10, 8 (players handbook)

Character::Character()
{
    // Set the stats
    this->name_ = "John Doe";
    this->stats_.maxHealth_ = 10;
    this->equipment_.shield_.armorClass_ = 0;     // Default has no shield
    this->equipment_.shield_.name_ = "None";
    this->stats_.strength_ = 10;
    this->stats_.dexterity_ = 15;
    this->stats_.constitution_ = 13;
    this->stats_.intelligence_ = 14;
    this->stats_.wisdom_ = 12;
    this->stats_.charisma_ = 8;
    this->stats_.armorClass_ = getModifiedArmorClass();     // Chain shirt and no shield

    //Set the features
    this->features_.race_ = "Human";
    this->features_.appearanceFeature_ = "Distinctive Nose";
    this->features_.profession_ = "Trader";
    //this->features_.profession_.description_ = "This person has a cart of wares they carry around.";
    //this->features_.profession_.randomDetail_ = "Wares are spices.";
    this->features_.currentActivity_.currentActivity_ = "Wandering";
    this->features_.currentActivity_.description_ = "This person seems to be lost and are wandering around.";
    this->features_.currentActivity_.randomDetail_ = "This person is lost because their map is missing.";
    this->features_.alignment_.first = "Lawful";
    this->features_.alignment_.second = "Evil";
    this->features_.talent_ = "Unbelievably Lucky";
    this->features_.interactionTrait_ = "Argumentative";
    this->features_.mannerism_ = "Prone to singing, whistling, or humming quietly.";
    this->features_.ideal_ = "Greed";
    this->features_.bond_ = "Protective of a sentimental keepsake.";
    this->features_.flaw_ = "Overpowering Greed";
    this->features_.secret_ = "This character is actually a doppleganger, trying to avoid notice as they hunt for their next victim.";

}

Character::Character(std::string name, Stats stats, Equipment equipment, Features features)
{
    this->name_ = name;
    this->stats_ = stats;
    this->equipment_ = equipment;
    this->features_ = features;
}

int Character::getAbilityModifier(int abilityScore) const
{
	double modifier = (static_cast<double>(abilityScore) - 10) / 2.0;
	modifier = floor(modifier);
	return static_cast<int>(modifier);
}

// Gets armor class taking into account equipment like armor and shield with dex modifiers
int Character::getModifiedArmorClass()
{
    int modifiedArmorClass = this->equipment_.armor_.armorClass_ + this->equipment_.shield_.armorClass_;

    if (this->equipment_.armor_.useDexMod_ == true)
    {
        // Is capped at 2
        if (this->equipment_.armor_.dexModIsCapped_ == true)
        {
            if (getAbilityModifier(this->stats_.dexterity_) > 2)
            {
                modifiedArmorClass += 2;
            }
            else
            {
                modifiedArmorClass += getAbilityModifier(this->stats_.dexterity_);
            }
        }
        // Is uncapped
        else
        {
            modifiedArmorClass += getAbilityModifier(this->stats_.dexterity_);
        }
    }

    return modifiedArmorClass;
}

void Character::displayCharacterInfo()
{
    std::cout << "==========================================================================\n";
    std::cout << "Name: " << this->name_ << std::endl << std::endl;
    std::cout << "Stats:\n";
    std::cout << "Max Health: " << this->stats_.maxHealth_ << std::endl;
    std::cout << "Armor Class: " << this->stats_.armorClass_ << std::endl;
    std::cout << "Strength: " << this->stats_.strength_ << std::endl;
    std::cout << "Dexterity: " << this->stats_.dexterity_ << std::endl;
    std::cout << "Constitution: " << this->stats_.constitution_ << std::endl;
    std::cout << "Intelligence: " << this->stats_.intelligence_ << std::endl;
    std::cout << "Wisdom: " << this->stats_.wisdom_ << std::endl;
    std::cout << "Charisma: " << this->stats_.charisma_ << std::endl;
    std::cout << std::endl;

    std::cout << "Equipment:\n";
    std::cout << "Weapon: " << this->equipment_.weapon_.wName_ << std::endl;
    std::cout << "Armor: " << this->equipment_.armor_.name_ << std::endl;
    std::cout << "Shield: " << this->equipment_.shield_.name_ << std::endl;
    std::cout << std::endl;

    std::cout << "Features:\n";
    std::cout << "Race: " << this->features_.race_ << std::endl;
    std::cout << "Appearance Feature: " << this->features_.appearanceFeature_ << std::endl;
    std::cout << "Profession: " << this->features_.profession_ << std::endl;
    std::cout << "Current Activity: " << this->features_.currentActivity_.currentActivity_ << std::endl;
    std::cout << "\t" << this->features_.currentActivity_.description_ << std::endl;
    std::cout << "\t" << this->features_.currentActivity_.randomDetail_ << std::endl;
    std::cout << "Alignment: " << this->features_.alignment_.first << ", " << this->features_.alignment_.second << std::endl;
    std::cout << "Talent: " << this->features_.talent_ << std::endl;
    std::cout << "Interaction Trait: " << this->features_.interactionTrait_ << std::endl;
    std::cout << "Mannerism: " << this->features_.mannerism_ << std::endl;
    std::cout << "Ideal: " << this->features_.ideal_ << std::endl;
    std::cout << "Bond: " << this->features_.bond_ << std::endl;
    std::cout << "Flaw: " << this->features_.flaw_ << std::endl;
    std::cout << "Secret: " << this->features_.secret_ << std::endl;
    std::cout << "**************************************************************************\n";
}

void Character::setName(std::string name)
{
    this->name_ = name;
}

void Character::setMaxHealth(int maxHealth)
{
    this->stats_.maxHealth_ = maxHealth;
}

void Character::setArmorClass(int armorClass)
{
    this->stats_.armorClass_ = armorClass;
}

void Character::setStrength(int strength)
{
    this->stats_.strength_ = strength;
}

void Character::setDexterity(int dexterity)
{
    this->stats_.dexterity_ = dexterity;
}

void Character::setConstitution(int constitution)
{
    this->stats_.constitution_ = constitution;
}

void Character::setIntelligence(int intelligence)
{
    this->stats_.intelligence_ = intelligence;
}

void Character::setWisdom(int wisdom)
{
    this->stats_.wisdom_ = wisdom;
}

void Character::setCharisma(int charisma)
{
    this->stats_.charisma_ = charisma;
}

void Character::setWeapon(Weapon weapon)
{
    this->equipment_.weapon_ = weapon;
}

void Character::setArmor(Armor armor)
{
    this->equipment_.armor_ = armor;
}

void Character::setShield(Armor shield)
{
    this->equipment_.shield_ = shield;
}

void Character::setRace(std::string race)
{
    this->features_.race_ = race;
}

void Character::setAppearanceFeature(std::string feature)
{
    this->features_.appearanceFeature_ = feature;
}

void Character::setProfession(std::string profession)
{
    this->features_.profession_ = profession;
}

void Character::setcurrentActivity(CurrentActivity currentActivity)
{
    this->features_.currentActivity_ = currentActivity;
}

//First can be Lawful, Neutral, Chaotic. Second can be Good, Neutral, Evil
void Character::setAlignment(std::pair<std::string, std::string> alignment)
{
    this->features_.alignment_ = alignment;
}

void Character::setTalent(std::string talent)
{
    this->features_.talent_ = talent;
}

void Character::setInteractionTrait(std::string interactionTrait)
{
    this->features_.interactionTrait_ = interactionTrait;
}

void Character::setMannerism(std::string mannerism)
{
    this->features_.mannerism_ = mannerism;
}

void Character::setIdeal(std::string ideal)
{
    this->features_.ideal_ = ideal;
}

void Character::setBond(std::string bond)
{
    this->features_.bond_ = bond;
}

void Character::setFlaw(std::string flaw)
{
    this->features_.flaw_ = flaw;
}

void Character::setSecret(std::string secret)
{
    this->features_.secret_ = secret;
}

std::string Character::getName() const
{
    return this->name_;
}

int Character::getMaxHealth() const
{
    return this->stats_.maxHealth_;
}

int Character::getArmorClass() const
{
    return this->stats_.armorClass_;
}

int Character::getStrength() const
{
    return this->stats_.strength_;
}

int Character::getDexterity() const
{
    return this->stats_.dexterity_;
}

int Character::getConstitution() const
{
    return this->stats_.constitution_;
}

int Character::getIntelligence() const
{
    return this->stats_.intelligence_;
}

int Character::getWisdom() const
{
    return this->stats_.wisdom_;
}

int Character::getCharisma() const
{
    return this->stats_.charisma_;
}

Weapon Character::getWeapon() const
{
    return this->equipment_.weapon_;
}

Armor Character::getArmor() const
{
    return this->equipment_.armor_;
}

Armor Character::getShield() const
{
    return this->equipment_.shield_;
}

std::string Character::getRace() const
{
    return this->features_.race_;
}

std::string Character::getAppearanceFeature() const
{
    return this->features_.appearanceFeature_;
}

std::string Character::getProfession() const
{
    return this->features_.profession_;
}

CurrentActivity Character::getcurrentActivity() const
{
    return this->features_.currentActivity_;
}

std::pair<std::string, std::string> Character::getAlignment() const
{
    return this->features_.alignment_;
}

std::string Character::getTalent() const
{
    return this->features_.talent_;
}

std::string Character::getInteractionTrait() const
{
    return this->features_.interactionTrait_;
}

std::string Character::getMannerism() const
{
    return this->features_.mannerism_;
}

std::string Character::getIdeal() const
{
    return this->features_.ideal_;
}

std::string Character::getBond() const
{
    return this->features_.bond_;
}

std::string Character::getFlaw() const
{
    return this->features_.flaw_;
}

std::string Character::getSecret() const
{
    return this->features_.secret_;
}