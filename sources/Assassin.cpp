#include "Assassin.hpp"

namespace coup{

    void Assassin::coup(Player &other)
    {
        start_turn(Action::coup);
        if (_coins < ASSASSIN_COUP_COST)
        {
            throw ("Not enough coins");
        }
        if (_coins < COUP_COST)
        {
            other.set_status(Status::assassinated);
            _last_action.action = Action::assassinate;
            _last_action.subject = &other;
            _coins-=ASSASSIN_COUP_COST;
            _game.end_turn();
        }
        else
        {
            other.set_status(Status::dead);
            _last_action.action = Action::coup;
            _last_action.subject = &other;
            _coins-=COUP_COST;
            _game.end_turn();
        }
    }

    Assassin::Assassin(Game& game, std::string name) : Player(game, std::move(name))
    {
    }

    Assassin::~Assassin()
    {
    }
}