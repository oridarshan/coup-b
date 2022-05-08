#pragma once

#include "Game.hpp"
#include <string>
namespace coup
{
    class Player
    {
    private:
        Game game;
        std::string name;
    public:
        // Player(Game game, std::string name);
    public:
        Player(Game game, std::string name);
        ~Player();
        void income();
        void foreign_aid();
        void coup(Player other);
        virtual std::string role(){return "base Player (Should not print)";}
        int coins();
    };

    
    
} // namespace coup

