#include "Assassin.hpp"

namespace coup{
    
    void Assassin::steal (Player assassin){}
    void Assassin::block (Player assassin){}

    Assassin::Assassin(Game& game, std::string name) : Player(game, name)
    {
    }

    Assassin::~Assassin()
    {
    }
}