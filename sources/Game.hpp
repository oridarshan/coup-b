#pragma once

#include <string>
#include <vector>
namespace coup
{
    class Player;
    static const int MAX_PLAYERS = 7;
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
        std::string turn();
        std::string winner();
        std::vector<std::string> players();
        void add_player(Player* p);
        void activate_game();
        void end_turn();

    };
}
#include "Player.hpp"