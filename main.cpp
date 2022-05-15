/**
 * Demo program for Coup exercise
 *
 * @author: Ori Darshan
 * @since: 2022-05
 */

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

/**
 * @brief turn player name to int for switch cases
 * 
 * @param player 
 * @return int 
 */
int playerEncode(string player){
    if (player == "You"){return 1;}
    if (player == "Duke"){return 2;}
    if (player == "Contessa"){return 3;}
    if (player == "Ambassador"){return 4;}
    if (player == "Captain"){return 5;}
    return -1;
}

int main(){
    const int LOGIC_ERROR = 42;
    // lower numbers - harder game
    const int DIFFICULTY_LEVEL = 4;
    cout << "WELCOME!\nCoup Game.\nYou are an assassin, the best in your country, "
"your mission is to eliminate everyone in the castle, and free the country!\n"
"The game will be played in turns, you will start first because"
"you have the surprise element.\n"
"In the castle you will find the evil Duke. This greedy royal can take 3 coins from the bank "
"in one turn, and can even block others from getting foreign financial aid!\n"
"Next is his trusty Contessa, she might be a problem for you.\n"
"She is a great healer (maybe even a witch), so make sure you kill your vectims completly "
"or she may heal them\n"
"Also beware of the sneaky Ambassador, he is the master of currency control. "
"he can take a coin from you and give it to someone else. make sure to avoid him and his traps!\n"
"Another powerful figure in the castle is the Captain. He uses his loyal servents "
"to commit all sort of crimes, they may even take your coins from you!\n\n"
"You have to plan your actions carefully, go over those unworthy royals and their "
"servants and free our country from their burden!\n\n"
"Each turn you can collect a coin from a poor guard nearby (income action).\n"
"if you want to collect coins faster, you can try calling for help from outside and "
"recieve 2 coins! (foreign aid action) However, the Duke may block the transaction if he "
"finds out about this, how lucky do you feel?\n"
"But do not forget the mission! If you posses 3 coins or more you can use your "
"turn to try and kill one of your targets (coup action). The quality of the operation will be "
"determined by your financial status.\n If you have less than 7 coins, you will be able "
"to wound a target fatally. The wounded target will die after a round, unless the Contessa "
"will save him.\n If you posses 7 coins or more - you will execute the perfect operation. "
"It may be costly, at 7 coins, but this time your target is completly dead.\n\n"
"Good luck!" << endl;
    Game game{};
	Assassin assassin{game, "You"};
	Duke duke{game, "Duke"};
	Contessa contessa{game, "Contessa"};
	Ambassador ambassador{game, "Ambassador"};
	Captain captain{game, "Captain"};
    bool game_on = true;
    while(game_on){

        //check if game ended
        try
        {
            // game ended with 1 player left
            string winner = game.winner();
            if (winner == "You")
            {
                cout << "Good job!\nYou won the game!\nGAME OVER" << endl;
                return 0;
            }
            else
            {
                cout << "You died...\nBetter luck next time!\nGAME OVER" << endl;
                return 0;
            }
        }
        catch(...){}
        try
        {
            // game ended with more than 1 player
            vector<string> players = game.players();
            // You died
            if (find(players.begin(), players.end(), "You") == players.end()){
                cout << "You died...\nBetter luck next time!\nGAME OVER" << endl;
                return 0;
            }
        }
        catch(...){}
        
        cout << "Next to play: " << game.turn() << endl;
        this_thread::sleep_for(chrono::seconds(2));
        switch (playerEncode(game.turn()))
        {
        case 1:{
            int curr_action = 0;
            if (assassin.coins() >= 10)
            {
                cout << "You have 10+ coins, you must coup." << endl;
                curr_action = 3;
            }
            else
            {
                cout << "status: " << assassin.coins() << " coins." << endl;
                cout << "Choose action:\n1 - income\n2 - foreign aid\n3 - coup" << endl;
                cin >> curr_action;
            }
            switch (curr_action)
            {
            case 1:{
                assassin.income();
                cout << "You gained 1 coin!" << endl;
                break;}
            case 2:{
                assassin.foreign_aid();
                cout << "You gained 2 coins!" << endl;
                break;}
            case 3:{
                if (assassin.coins() < 3)
                {
                    cout << "Not enough coins." << endl;
                    break;
                }
                
                string target;
                cout << "Choose your target:" << endl;
                // print active players
                for(string name : game.players()){
		            cout << name << endl;
	            }
                cout << "Enter target:" << endl;
                cin >> target;
                switch (playerEncode(target))
                {
                case 1:{
                    cout << "You are an idiot, this game is OVER." << endl;
                    return LOGIC_ERROR;}
                case 2:{
                    assassin.coup(duke);
                    cout << "Performed 'coup' on the Duke" << endl;
                    break;}
                case 3:{
                    assassin.coup(contessa);
                    cout << "Performed 'coup' on the Contessa" << endl;
                    break;}
                case 4:{
                    assassin.coup(ambassador);
                    cout << "Performed 'coup' on the Ambassador" << endl;
                    break;}
                case 5:{
                    assassin.coup(captain);
                    cout << "Performed 'coup' on the Captain" << endl;
                    break;}
                default:{
                    cout << "Make sure you enter the correct player name" << endl;
                    break;}
                }
                break;
            }
            default:{
                cout << "Make sure you enter the correct action number" << endl;
                break;}
            }
            break;
        }
        case 2:{
            if (duke.coins() >= 10)
            {
                duke.coup(assassin);
                cout << " You have been executed." << endl;
                break;
            }
            
            int no_block = rand()%DIFFICULTY_LEVEL;
            // if 0 try
            if (!no_block)
            {
                try
                {
                    duke.block(assassin);
                    cout << "The Duke blocked your foreign aid" << endl;
                }
                catch(...){}
            }
            else
            {
                int no_tax = rand()%DIFFICULTY_LEVEL;
                if (!no_tax)
                {
                    duke.tax();
                    cout << "Duke performed 'tax' and got 3 coins" << endl;
                }
                else
                {
                    int no_coup = rand()%DIFFICULTY_LEVEL;
                    if (!no_coup)
                    {
                        try{duke.coup(assassin);
                            cout << " You have been executed." << endl;}
                        catch(...){
                            duke.income();
                            cout << "Duke performed 'income'" << endl;
                        }
                    }
                    else{
                        duke.income();
                        cout << "Duke performed 'income'" << endl;   
                    }
                }
            }
            break;
        }
        case 3:{
            if (contessa.coins() >= 10)
            {
                contessa.coup(assassin);
                cout << " You have been executed." << endl;
                break;
            }
            int no_block = rand()%DIFFICULTY_LEVEL;
            // if 0 try
            if (!no_block)
            {
                try
                {
                    contessa.block(assassin);
                    cout << "Contessa revived the dead" << endl;
                }
                catch(...){}
            }
            else
            {
                int no_coup = rand()%DIFFICULTY_LEVEL;
                if (!no_coup)
                {
                    try{contessa.coup(assassin);
                        cout << " You have been executed." << endl;}
                    catch(...){
                        contessa.income();
                        cout << "Contessa performed 'income'" << endl;
                    }
                }
                else{
                    contessa.income();
                    cout << "Contessa performed 'income'" << endl;   
                }
            }
            break;
        }
        case 4:{
            if (ambassador.coins() >= 10)
            {
                ambassador.coup(assassin);
                cout << " You have been executed." << endl;
                break;
            }
            int no_transfer = rand()%DIFFICULTY_LEVEL;
            // if 0 try
            if (!no_transfer)
            {
                try
                {
                    ambassador.transfer(assassin, duke);
                    cout << "The Ambassador took your coin and gave it to the Duke!" << endl;
                }
                catch(...){}
            }
            else
            {
                int no_coup = rand()%DIFFICULTY_LEVEL;
                if (!no_coup)
                {
                    try{ambassador.coup(assassin);
                        cout << " You have been executed." << endl;}
                    catch(...){
                        ambassador.income();
                        cout << "Ambassador performed 'income'" << endl;
                    }
                }
                else{
                    ambassador.income();
                    cout << "Ambassador performed 'income'" << endl;   
                }
            }
            break;
        }
        case 5:{
            if (captain.coins() >= 10)
            {
                captain.coup(assassin);
                cout << " You have been executed." << endl;
                break;
            }
            int no_steal = rand()%DIFFICULTY_LEVEL;
            // if 0 try
            if (!no_steal)
            {
                try
                {
                    captain.steal(assassin);
                    cout << "The Captain took some of your coins!" << endl;
                }
                catch(...){}
            }
            else
            {
                int no_coup = rand()%DIFFICULTY_LEVEL;
                if (!no_coup)
                {
                    try{captain.coup(assassin);
                        cout << " You have been executed." << endl;}
                    catch(...){
                        captain.income();
                        cout << "Captain performed 'income'" << endl;
                    }
                }
                else{
                    captain.income();
                    cout << "Captain performed 'income'" << endl;   
                }
            }
            break;
        }
        default:{
            return LOGIC_ERROR;}
        }
    }
    return 0;
}