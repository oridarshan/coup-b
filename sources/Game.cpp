#include "Game.hpp"


namespace coup{
    
    std::string Game::turn()
    {
        return _players[(size_t)_turn_id]->name();
    }
    std::string Game::winner()
    {
        // game ended and only 1 player left
        if (!_game_on && _players.size() == 1)
        {
            return _players[0]->name();
        }
        throw ("Game in progress / not started");
    }
    std::vector<std::string> Game::players()
    {
        std::vector <std::string> res;
        for(Player* p : _players){
            res.push_back((*p).name());
        }
        return res;
    }

    void Game::add_player(Player* p)
    {
        _players.push_back(p);
    }

    Game::Game()
    {
        _game_on = false;
        _turn_id = 0;
    }

    Game::~Game()
    {
    }
}