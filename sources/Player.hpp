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

        void start_turn(Action action);
    public:
        Player(Game& game, std::string name);
        ~Player();

        Status get_status(){return _status;}
        std::string name() const {return _name;}
        void income();
        void foreign_aid();
        const LastAction& last_action(){return _last_action;}
        virtual void coup(Player& other);
        virtual void block(Player& other) =0;
        virtual std::string role(){return "base Player (Should not print)";}
        int coins() const;
        /**
         * @brief steal n coin, or less if not possible
         * 
         * @param n 
         * @return int 
         */
        int steal_coins(int n);
        /**
         * @brief update status parameter 
         * 
         */
        void set_status(Status st);
        void add_coins(int n);
        void get_turn();

        friend std::ostream& operator<< (std::ostream& output, const Player& p);
    };
} // namespace coup
