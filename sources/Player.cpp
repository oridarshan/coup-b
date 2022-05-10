#include "Player.hpp"
#include <iostream>
namespace coup{

    Player::Player(Game& game, std::string name): _game(game), _name(name),
                                                 _coins(0), _status(Status::alive)
    {
    if (_game.players().size() >= 6)
    {
        throw ("max player count is 6");
    }
        game.add_player(this);
    }

    Player::~Player()
        {
        }

    void Player::set_status(Status st)
    {
        if (_status != Status::alive)
        {
            throw ("can't kill the dead");
        }
        
        _status = st;
    }

    void Player::income()
    {
        start_turn(Action::income);
        _coins++;
        _last_action.action = Action::income;
        _last_action.subject = this;
        _game.end_turn();
    }
    void Player::foreign_aid()
    {
        start_turn(Action::forien_aid);
        _coins+=2;
        _last_action.action = Action::forien_aid;
        _last_action.subject = this;
        _game.end_turn();
    }
    void Player::coup(Player& other)
    {
        start_turn(Action::coup);
        if (_coins < 7)
        {
            throw ("Not enough coins");
        }
        
        other.set_status(Status::dead);
        _last_action.action = Action::coup;
        _last_action.subject = &other;
        _game.end_turn();
    }

    int Player::coins() const {return _coins;}
    
    int Player::steal_coins(int n)
    {
        int stolen_coins = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (_coins != 0)
            {
                stolen_coins++;
                _coins--;
            }
            
        }
        return stolen_coins;
    }

    void Player::add_coins(int n){_coins += n;}

    void Player::start_turn(Action action){
        if (_game.players().size() > 6 || _game.players().size() < 2)
        {
            throw ("number of player not right");
        }

        if (_game.turn() != _name)
        {
            throw ("Not your turn!");
        }
        if (_coins >= 10 && action != Action::coup)
        {
            throw ("you posses 10 coins, kill someone already");
        }
        
        _game.activate_game();
        
    }

    std::ostream& operator<< (std::ostream& output, const Player& p){
        return output << p.name();
    }
}