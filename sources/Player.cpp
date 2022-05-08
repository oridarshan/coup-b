#include "Player.hpp"
namespace coup{

    Player::Player(Game game, std::string name): game(game), _name(name)
        {
        }

    Player::~Player()
        {
        }

    void Player::income(){}
    void Player::foreign_aid(){}
    void Player::coup(Player other){}
    int Player::coins() const {return _coins;}

    std::ostream& operator<< (std::ostream& output, const Player& p){
        return output << p.name();
    }
}