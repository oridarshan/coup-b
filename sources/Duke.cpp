#include "Duke.hpp"

namespace coup{
    
    void Duke::steal (Player assassin){}
    void Duke::block (Player assassin){}
    void Duke::tax(){}

    // Duke::Duke(Game game, std::string name) : Player(game, name)
    Duke::Duke(Game& game, std::string name) : Player(game, name)
    {
    }

    Duke::~Duke()
    {
    }
}