#include "Duke.hpp"

namespace coup{
    
    void Duke::block(Player& other){}
    void Duke::tax()
    {
        start_turn();
        _coins += 3;
        _last_action.action = Action::tax;
        _last_action.subject = this;
        _game.end_turn();
    }

    // Duke::Duke(Game game, std::string name) : Player(game, name)
    Duke::Duke(Game& game, std::string name) : Player(game, name)
    {
    }

    Duke::~Duke()
    {
    }
}