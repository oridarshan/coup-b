#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Captain : public Player
    {
    private:

    public:
        Captain(Game& game, std::string name);
        ~Captain();
        void steal (Player& other);
        void block (Player& other);
        std::string role(){return "Captain";}
    };


}