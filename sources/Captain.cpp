#include "Captain.hpp"

namespace coup{
    
    void Captain::steal (Player assassin){}
    void Captain::block (Player assassin){}

    Captain::Captain(Game& game, std::string name) : Player(game, name)
    {
    }

    Captain::~Captain()
    {
    }
}