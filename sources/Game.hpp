#pragma once

#include <string>
#include <vector>
namespace coup
{
    class Player;
    static const int MIN_PLAYERS = 2;
    static const int MAX_PLAYERS = 6;
    static const int ASSASSIN_COUP_COST = 3;
    static const int COUP_COST = 7;
    static const int MAX_COINS = 10;

    class Game
    {
    private:     
        bool _game_on;
        std::vector <Player*> _players;
        int _turn_id;
    public:
        Game();
        ~Game();
        std::string turn() const;
        std::string winner() const;
        std::vector<std::string> players() const;
        void add_player(Player* p);
        void activate_game();
        void end_turn();

    };
}
#include "Player.hpp"