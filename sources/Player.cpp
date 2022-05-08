#include "Player.hpp"
namespace coup{

    Player::Player(Game game, std::string name): game(game),name(name)
        {
        }

    Player::~Player()
        {
        }

    void Player::income(){}
    void Player::foreign_aid(){}
    void Player::coup(Player other){}
    int Player::coins(){return 0;}
}