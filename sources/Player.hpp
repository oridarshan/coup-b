#pragma once

#include "Status.hpp"
#include "LastAction.hpp"
#include "Game.hpp"

#include <string>
namespace coup
{
    class Player
    {
    protected:
        Game& _game;
        std::string _name;
        int _coins;
        Status _status;
        LastAction _last_action;

        void start_turn();
    public:
        // Player(Game game, std::string name);
    public:
        Player(Game& game, std::string name);
        ~Player();

        Status get_status(){return _status;}
        std::string name() const {return _name;}
        void income();
        void foreign_aid();
        virtual void coup(Player& other);
        virtual std::string role(){return "base Player (Should not print)";}
        int coins() const;
        void kill();

        friend std::ostream& operator<< (std::ostream& output, const Player& p);
    };
} // namespace coup
