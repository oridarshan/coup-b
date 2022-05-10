#include "Contessa.hpp"

namespace coup{
    
    void Contessa::block(Player& other)
    {
        if (other.last_action().action != Action::assassinate)
        {
            throw ("Contessa can only block 'assassinate'");
        }
        if (other.last_action().subject->get_status() == Status::dead)
        {
            throw ("not a necromancer, can't revive the dead");
        }
        other.last_action().subject->set_status(Status::alive);
        
    }

    Contessa::Contessa(Game& game, std::string name) : Player(game, std::move(name))
    {
    }

    Contessa::~Contessa()
    {
    }
}