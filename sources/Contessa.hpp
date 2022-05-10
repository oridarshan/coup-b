#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Contessa : public Player
    {
    private:

    public:
        Contessa(Game& game, std::string name);
        ~Contessa();
        void block (Player assassin);
        std::string role(){return "Contessa";}
    };


}
