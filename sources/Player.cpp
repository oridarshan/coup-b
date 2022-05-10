#include "Player.hpp"
#include <iostream>
namespace coup{

    Player::Player(Game& game, std::string name): _game(game), _name(name),
                                                 _coins(0), _status(Status::alive)
        {
            game.add_player(this);
        }

    Player::~Player()
        {
        }

    void Player::kill()
    {
        if (_status == Status::alive){_status = Status::murdered;}
        if (_status == Status::murdered){_status = Status::dead;}
        if (_status == Status::dead){throw ("Already dead");}
    }

    void Player::income()
    {
        start_turn();
        _coins++;
        _last_action.action = Action::income;
        _last_action.subject = this;
        _game.end_turn();
    }
    void Player::foreign_aid()
    {
        start_turn();
        _coins+=2;
        _last_action.action = Action::forien_aid;
        _last_action.subject = this;
        _game.end_turn();
    }
    void Player::coup(Player& other)
    {
        start_turn();
        other.kill();
        _last_action.action = Action::coup;
        _last_action.subject = &other;
        _game.end_turn();
    }
    int Player::coins() const {return _coins;}
    void Player::start_turn(){
        if (_game.players().size() > 6 || _game.players().size() < 2)
        {
            throw ("number of player not right");
        }
        
        if (_game.turn() != _name)
        {
            throw ("Not your turn!");
        }
        _game.activate_game();
        
    }

    std::ostream& operator<< (std::ostream& output, const Player& p){
        return output << p.name();
    }
}