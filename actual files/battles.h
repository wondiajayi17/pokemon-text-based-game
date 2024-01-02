#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;


class Battles
{
public:
    //declare moves from Pokemon_moves.h
    Electric electric_Move1;
    Electric electric_Move2;
    Electric electric_Move3;
    Normal normal_Move1;
    Normal normal_Move2;
    Normal normal_Move3;
    Dragon dragon_Move1;
    Dragon dragon_Move2;
    Dragon dragon_Move3;
    Water water_Move1;
    Water water_Move2;
    Water water_Move3;
    Grass grass_Move1;
    Grass grass_Move2;
    Grass grass_Move3;
    Fighting fighting_Move1;
    Fighting fighting_Move2;
    Fighting fighting_Move3;
    Flying flying_Move1;
    Flying flying_Move2;
    Flying flying_Move3;
    Fire fire_Move1;
    Fire fire_Move2;
    Fire fire_Move3;


    bool Win;


    Battles()
    {
    }


    double calculate_effectiveness( string defender_type,  string move_type) {
    double effectiveness = 1.0;
    
    // Water type
    if (move_type == "Water") {
        if (defender_type == "Fire" || defender_type == "Normal") {
            effectiveness = 2.0;
        } else if (defender_type == "Grass" || defender_type == "Fighting" || defender_type == "Water" || defender_type == "Flying") {
            effectiveness = 0.5;
        } else if (defender_type == "Dragon" || defender_type == "Electric") {
            effectiveness = 0.25;
        }
    }
    
    // Grass type
    if (move_type == "Grass") {
        if (defender_type == "Water" || defender_type == "Electric") {
            effectiveness = 2.0;
        } else if ( defender_type == "Grass" || defender_type == "Normal" || defender_type == "Flying" || defender_type == "Dragon") {
            effectiveness = 0.5;
        } else if (defender_type == "Fire" || defender_type == "Fighting") {
            effectiveness = 0.25;
        }
    }
    
    // Normal type
    if (move_type == "Normal") {
        if(defender_type == "Fire" || defender_type == "Water"){
            effectiveness = 2.0;
        }else if (defender_type == "Normal" || defender_type == "Fighting" || defender_type == "Grass" || defender_type == "Electric") {
            effectiveness = 0.5;
        } else if (defender_type == "Flying"|| defender_type == "Dragon") {
            effectiveness = 0.25;
        }
    }
    
    // Fighting type
    if (move_type == "Fighting") {
        if (defender_type == "Normal" || defender_type == "Fire") {
            effectiveness = 2.0;
        } else if (defender_type == "Flying" || defender_type == "Dragon" || defender_type == "Grass" || defender_type == "Fighting" ) {
            effectiveness = 0.5;
        } else if (defender_type == "Water" || defender_type == "Elecric") {
            effectiveness = 0.25;
        }
    }
    
    // Electric type
    if (move_type == "Fighting") {
        if (defender_type == "Dragon" || defender_type == "Flying") {
            effectiveness = 2.0;
        } else if (defender_type == "Electric" || defender_type == "Grass" || defender_type == "Normal"|| defender_type == "Fire") {
            effectiveness = 0.5;
        } else if (defender_type == "Water"|| defender_type == "Fighting") {
            effectiveness = 0.25;
        }
    }
    
    // Dragon type
    if (move_type == "Dragon") {
        if (defender_type == "Water"|| defender_type == "Fighting") {
            effectiveness = 2.0;
        } else if (defender_type == "Dragon"|| defender_type == "Normal"|| defender_type == "Electric"|| defender_type == "Grass") {
            effectiveness = 0.5;
        } else if(defender_type == "Flying"|| defender_type == "Fire"){
            effectiveness = 0.25;
        }
    }
    
    //Flying type
    if (move_type == "Flying") {
        if (defender_type == "Normal"|| defender_type == "Fire") {
            effectiveness = 2.0;
        } else if (defender_type == "Flying"|| defender_type == "Water"|| defender_type == "Electric"|| defender_type == "Grass") {
            effectiveness = 0.5;
        } else if(defender_type == "Dragon"|| defender_type == "Fighting"){
            effectiveness = 0.25;
        }
    }
    
    //Fire type
    if (move_type == "Fire") {
        if (defender_type == "Water"|| defender_type == "Electric") {
            effectiveness = 2.0;
        } else if (defender_type == "Fighting"|| defender_type == "Fire"|| defender_type == "Flying"|| defender_type == "Grass") {
            effectiveness = 0.5;
        } else if(defender_type == "Dragon"|| defender_type == "Normal"){
            effectiveness = 0.25;
        }
    }
    return effectiveness;
    }


    string get_type(string pokemon_name);
    int attack(int pokemon_Hp, int damage_Done)
    {
        //set the new_hp to be 0
        int new_Hp = 0;


        //set newHP to be the differnece  between the original hp an the damage done
        new_Hp = pokemon_Hp - damage_Done;


        //if the hp is below 0 then set it to be 0 as a pokemon cannot have less than 0 hp
        if(new_Hp < 0)
        {
            new_Hp = 0;
        }


        //return the new hp after the attack has been done
        return new_Hp;
    }


    bool FightScence(int Pokemon_Hp,string pokemon_name,int ai_hp, string  ai_name,int pokemon_Remaining)
    {
        int choice;
        
    
        int randomInt;
        int randomInt2;
        mt19937 rng(time(0)); // https://stackoverflow.com/questions/57135552/how-can-i-set-range-to-the-random-library
        uniform_int_distribution <int> d(0, 21); // The range of the length of pokemon file (hardcoded must be updated if more pokemon are added)
        


        //defines random number 
        randomInt = d(rng);
        randomInt2 = d(rng);
        //create  pokemon object for player
        NPC PlayerPokemon;
        PlayerPokemon.pick_Random_Pokemon(randomInt);
            


        //create pokemon object for AI
        NPC AiPokemon;
        AiPokemon.pick_Random_Pokemon(randomInt2);


        
        //calls new pokemon name showing that the pokemon has been changed
        cout<< "Summoning new pokemon: "<< pokemon_name << endl;
        cout<< pokemon_name <<" is ready for battle.... what move do you want to use:"<<endl;
        
        
        
        //  loop for checking if pokemon HP has reached 0 and the continuous use of moves
        while (pokemon_Remaining != 0)
        {
            //false when player hasnt won
            Win = false;
            
            
            if (Pokemon_Hp <= 0){
                //change pokemon
                cout<< pokemon_name << " has been defeated"<<endl;
                pokemon_Remaining -= 1;
                //use of recursion to summon new pokemon 
                FightScence(PlayerPokemon.get_Hp(), PlayerPokemon.get_Name(), AiPokemon.get_Hp(), AiPokemon.get_Name(), pokemon_Remaining);
            
            //ai pokemon conditionals
            }else if (ai_hp <= 0){ 
                // use of recursion to summon new pokemon(for now player will will if he defeats one(1) pokemon)
                break;


                //FightScence(PlayerPokemon.get_Hp(), PlayerPokemon.get_Name(), AiPokemon.get_Hp(), AiPokemon.get_Name(),pokemon_Remaining);
            }


            // choice of move - try make it a random move name
            cout<< "1.Light attack: (15 DMG), 2.Normal attack: (35 DMG), 3.Heavy attack: (50 DMG): ";
            cin >> choice;
            cout << pokemon_name << " is using: " << "movename" << endl; 
            


            cout<< ai_name << " used: " << "movename"<< endl;
            
            //calculate damage (random for now)
            Pokemon_Hp -= 30; // fixed damage recieved
            if (choice == 1){
                ai_hp -= 15;
            }else if(choice == 2){
                ai_hp -= 35;
            }else{
                ai_hp -= 50;
            }
            cout<<"your pokemon  "<<Pokemon_Hp<<" HP remaining"<<endl;
            cout<<ai_name<< " has "<<ai_hp<<" HP remaining"<<endl;


            //aim to add delay here


        }
        
        //message to display if you've won return bool if they win 
        if (pokemon_Remaining> 0){
            cout << "That was a close one .... you win "<<endl;
            Win = true;
            return Win;
            // exit(0); (use this is if the function wont end when you get the return value)
        }else{
            cout << "That was rough ...."<<endl;
            return Win;
        };
        


        return Win;
    }


    void catchPokemon(int num_poke_balls, bool is_wild_pokemon, string enemy_type, vector<NPC>& pokemon_names) {
        if (is_wild_pokemon == 0){
            if (num_poke_balls <= 0) {
                cout << "ERROR: There are no pokeballs left" << endl;
                return;
            }
            bool is_caught = (rand() % 2 == 0);//Its a boolean expression that generates a random integer between 0 and 1 and checks if it is equal to 0.
            if (is_caught==0) {
                cout << "Oh no! The wild Pokemon got away." << endl;
                return;
            }
            // To reduce the number of Pokeballs
            num_poke_balls--;
            // Catch the Pokemon
            cout << "You caught a wild Pokemon!" << endl;
            cout<<"Do you want to keep this pokemon ? "<<endl;
            cout<< "Enter Y for yes, N for no"<<endl;
            string choice;
            cin>> choice;
            if(choice == "Y" || choice == "y"){
                cout<<"These are the pokemons you have: "<<endl;// For loop to print out the pokemons they have
                for(int name = 0; name < pokemon_names.size(); name++){
                    cout << name+1 << ". " << pokemon_names[name].get_Name() << endl;
                }
                while(true){
                    cout<<"Enter the number of the pokemon you want to replace"<<endl;
                    int replaced_pokemon;
                    cin>>replaced_pokemon;
                    if(replaced_pokemon < 1 || replaced_pokemon > 3){
                        pokemon_names.erase(pokemon_names.begin() + replaced_pokemon - 1);
                    }
                    else{
                        cout<<"ERRORR: Invalid input enter a number between 1 and 3"<<endl;
                        cin>>replaced_pokemon;
                        break;
                    }
                }
                string wildpokemon_name;
                NPC wildpokemon;
                cout<<"What would you like to name this wild pokemon you just caught.";
                cin>>wildpokemon_name;
                wildpokemon.set_Name(wildpokemon_name);
                pokemon_names.push_back(wildpokemon);
                cout<<"Added" << wildpokemon_name << "to your collection"<<endl; 
            }
            else if(choice == "n" || choice == "N"){
                cout<<"You've let the wild pokemon go. "<<endl;
            }
            else{
                cout<<"Invalid answer"<<endl;
            }


        } else{
            // Pokemon being fought is a trainer's Pokemon
            if (enemy_type == "trainer") {
                cout << "ERROR: You cannot catch a trainer's Pokemon" << endl;
            } else if (enemy_type == "pokemon") {
                cout << "ERROR: You cannot catch another Pokemon that's not wild" << endl;
            } else {
                cout << "ERROR: Invalid enemy type" << endl;
            }
        }
    }


    //procedure to simulate the battle happening. (The variables we have not used yet look like errors but theyre not. Code still runs)
    bool pokemonBattle(string name,int hp, string name2,int hp2, string name3, int hp3, string ai_Name, int ai_Hp, string ai_Name2, int ai_Hp2, string player_Name, int poke_Balls)
    {

        
        //declare local variables
        int answer;
        int pokemon_choice = 0;
        bool choice_is_true = true;
        bool switch_is_true = true;

        cout << player_Name << ": " << name << " I choose you!"<< endl;
        cout << name << " has been summoned..." << endl << endl;
        
        //While loop used to make sure the player chooses in between 1 and 3
        while (choice_is_true == true)
        {
        cout << "Would you like to "<< endl << "1. ATTACK "<< endl << "2. SWITCH POKEMON" << endl << "3. CATCH POKEMON" << endl;
        cout << "Choice: ";
        cin >>  answer;
        
            if (answer == 1 || answer == 2 || answer == 3)
            {
                //make is_true false so that when the while loops checks, it doesnt loop again.
                choice_is_true = false;
            }
            else
            {
                cout<<"invalid input, please choose one between the options which are 1, 2 and 3"<<endl;
            }
        }


        //if statement for option 1
        if (answer == 1)
        {
            
          Win = FightScence(hp,name,ai_Hp,ai_Name,3);
           return (Win);
        }


    //if statement for option 2 (swap pokemon) 
        else if (answer == 2)
        {
            while (switch_is_true == true)
            {
                cout << "These are the pokemons you have:" << endl;
                cout << "1. " << name << endl;
                cout << "2. " << name2 << endl;
                cout << "3. " << name3 << endl;
                cout << "Which one would you like to use?" << endl;
                cin >>  pokemon_choice;
                //While loop to make sure player chooses in between 1 and 3
                
                    if (pokemon_choice == 1 || pokemon_choice == 2 || pokemon_choice == 3)
                    {
                        switch_is_true = false;
                    }

                    else
                    {
                        cout<<"invalid input, please choose one between the options which are 1, 2 and 3"<<endl;
                    }
                    
                    
            }
        //If statements for pokemon choice
            if (pokemon_choice == 3)
            {
            cout << player_Name << ": " << name3 << " I choose you!"<< endl;
            cout << name3 << " has been summoned..." << endl << endl;
            pokemonBattle( name, hp,  name2, hp2,  name3,  hp3,  ai_Name,  ai_Hp,  ai_Name2,  ai_Hp2,  player_Name,  poke_Balls);

            }
            
            else if (pokemon_choice == 2)
            {
            cout << player_Name << ": " << name2 << " I choose you!"<< endl;
            cout << name2 << " has been summoned..." << endl << endl;
            pokemonBattle( name, hp,  name2, hp2,  name3,  hp3,  ai_Name,  ai_Hp,  ai_Name2,  ai_Hp2,  player_Name,  poke_Balls);
            }

            else if (pokemon_choice == 1)
            {
                cout<<"This pokemon is already being used"<<endl;
                pokemonBattle( name, hp,  name2, hp2,  name3,  hp3,  ai_Name,  ai_Hp,  ai_Name2,  ai_Hp2,  player_Name,  poke_Balls);
            }


            

             
        }


        //if statement for option 3
        else if (answer == 3)
        {
            //This part here is what made it compile and I had to reasearch to understand what the ? does in c++
            bool isWildPokemon = rand() % 2; // generates a random value of either 0 or 1
            int numPokeballs = rand() % 21; // generates a random value between 0 and 20 I don't think we're storing pokeballs anywhere that's why it's randomized
            string enemyType = (rand() % 2) ? "pokemon" : "trainer"; // generates either "wild" or "trainer"
            vector<NPC> pokemon_names;
            catchPokemon(numPokeballs, isWildPokemon, enemyType, pokemon_names);
        }
    };
};



