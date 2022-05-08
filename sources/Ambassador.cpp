#include "Ambassador.hpp"

namespace coup{
    
    void Ambassador::steal (Player assassin){}
    void Ambassador::block (Player assassin){}

    Ambassador::Ambassador(Game game, std::string name) : Player(game, name)
    {
    }

    Ambassador::~Ambassador()
    {
    }
}