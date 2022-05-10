#include "Ambassador.hpp"

namespace coup{
    
    
    void Ambassador::transfer(Player& from, Player& to)
    {
        start_turn();
        int stolen_coins = from.steal_coins(1);
        to.add_coins(stolen_coins);
        _last_action.action = Action::transfer;
        _last_action.subject = this;
        _game.end_turn();
    }

    void Ambassador::block (Player& other)
    {
        if (other.last_action().action != Action::steal)
        {
            throw ("Ambassador can only block 'steal'");
        }
        int stolen_coins = other.steal_coins(2);
        other.last_action().subject->add_coins(stolen_coins);
        
    }

    Ambassador::Ambassador(Game& game, std::string name) : Player(game, name)
    {
    }

    Ambassador::~Ambassador()
    {
    }
}