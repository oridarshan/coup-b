#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Assassin : public Player
    {
    private:

    public:
        Assassin(Game& game, std::string name);
        ~Assassin();
        void coup(Player &other);
        void block(Player& other){throw ("Assassin can't block");}
        std::string role(){return "Assassin";}
    };


}