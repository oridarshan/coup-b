#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Duke : public Player
    {
    private:

    public:
        Duke(Game& game, std::string name);
        ~Duke();
        void block(Player& other);
        void tax();
        std::string role(){return "Duke";}
    };


}