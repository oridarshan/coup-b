#pragma once

#include "Game.hpp"
#include <string>
namespace coup
{
    
    class Player
    {
    protected:
        Game game;
        std::string _name;
        int _coins;
    public:
        // Player(Game game, std::string name);
    public:
        Player(Game& game, std::string name);
        ~Player();
        std::string name() const {return _name;}
        void income();
        void foreign_aid();
        void coup(Player other);
        virtual std::string role(){return "base Player (Should not print)";}
        int coins() const;

        friend std::ostream& operator<< (std::ostream& output, const Player& p);
    };

    
    
} // namespace coup

