#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "RandomCharacterGenerator.h"
#include "Character.h"

int main()
{   
    std::cout << std::boolalpha;
    std::vector<std::string> files = { "names.txt", "weapons.txt", "armors.txt", "shields.txt", "races.txt", "appearanceFeatures.txt", "professions.txt", "currentActivities.txt", "talents.txt", "interactionTraits.txt", "secrets.txt", "mannerisms.txt", "lawfulIdeals.txt", "chaoticIdeals.txt", "neutralIdeals.txt", "goodIdeals.txt", "evilIdeals.txt", "otherIdeals.txt", "bonds.txt", "flaws.txt" };
    RandomCharacterGenerator generator(files);
    std::vector<Character> characterList;
    bool askForRace = false;
    char input = ' ';


    while (std::toupper(input) != 'Q')
    {
        while (true)
        {
            std::cout << "Select an Option: " << std::endl;
            std::cout << "1. Create Random Character" << std::endl;
            std::cout << "2. Display all Characters" << std::endl;
            std::cout << "3. Save Characters to text file" << std::endl; // Not implemented
            std::cout << "4. Toggle Ask for Race option (is set to: " << askForRace << ")" << std::endl;              // Not implemented
            std::cout << "Q: Exit Program" << std::endl;
            
            std::cin >> input;
            // Check for fail
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extraneous input
                // Check if in range
                if (input == '1' || input == '2' || input == '3' || input == '4' || input == 'Q' || input == 'q')
                {
                    break; // Get out of input loop
                }
            }
        }

        switch(std::toupper(input))
        {
            // Create random character
            case '1':
            {
                int numOfCharacters;
                while(true)
                {
                    std::cout << "How many Characters do you want to make: ";
                    std::cin >> numOfCharacters;
                    // Check for fail
                    if (!std::cin)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else
                    {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove extraneous input
                        // Check if in range
                        if (numOfCharacters > 0)
                        {
                            break; // Get out of input loop
                        }
                    }
                }

                for (int i = 0; i < numOfCharacters; ++i)
                {
                    Character character;
                    if (askForRace == false)
                    {
                        character = generator.generateCharacter();
                        characterList.push_back(character);
                    }
                    else if (askForRace == true)
                    {
                        std::string race;
                        while(true)
                        {
                            std::cout << "Enter Race: ";
                            std::cin >> race;
                            // Check for fail
                            if (!std::cin)
                            {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            // Check if valid race
                            else
                            {
                                if (!generator.isValidRace(race))
                                {
                                    std::cout << "That is not a valid race! Try again." << std::endl;
                                    std::cout << "Valid races are: Human, Dwarf, Orc, Elf, Drow, Halfling, Gnome, Dragonborn, Half-Orc, Half-Elf" << std::endl;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }

                        character = generator.generateCharacterWRace(race);
                        characterList.push_back(character);
                    }
                    
                }
                
                std::cout << std::endl;
                break;
            }

            // Display all characters
            case '2':
            {
                for (int i = 0; i < static_cast<int>(characterList.size()); ++i)
                {
                    std::cout << "Character #" << i + 1 << ":" << std::endl;
                    characterList[i].displayCharacterInfo();
                    std::cout << std::endl << std::endl << std::endl;
                }
                std::cout << std::endl;
                break;
            }

            // Save all characters to a text file
            case '3':
            {
                std::cout << "Writing to text file Saved Characters" << std::endl;
                generator.writeCharactersToFile(characterList);
                std::cout << std::endl;
                break;
            }

            // Change setting to ask for race
            case '4':
            {
                if (askForRace == true)
                {
                    askForRace = false;
                }
                else
                {
                    askForRace = true;
                }
                std::cout << "Race prompt is currently set to: " << askForRace << std::endl;
                std::cout << std::endl;
                break;
            }
        }

    }

    std::cout << "Thank you for using the program!" << std::endl;
    return 0;
}