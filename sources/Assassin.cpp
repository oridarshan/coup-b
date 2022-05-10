#include "Assassin.hpp"

namespace coup{

    void Assassin::coup(Player &other)
    {
        start_turn(Action::coup);
        if (_coins < 3)
        {
            throw ("Not enough coins");
        }
        if (_coins < 7)
        {
            other.set_status(Status::assassinated);
            _last_action.action = Action::assassinate;
            _last_action.subject = &other;
            _coins-=3;
            _game.end_turn();
        }
        else
        {
            other.set_status(Status::dead);
            _last_action.action = Action::coup;
            _last_action.subject = &other;
            _coins-=7;
            _game.end_turn();
        }
    }

    Assassin::Assassin(Game& game, std::string name) : Player(game, name)
    {
    }

    Assassin::~Assassin()
    {
    }
}