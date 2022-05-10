#include "Game.hpp"


namespace coup{
    
    std::string Game::turn()
    {
        return _players.at((size_t)_turn_id)->name();
    }
    std::string Game::winner()
    {
        // game ended and only 1 player left
        if (players().size() == 1)
        {
            return players().at(0);
        }
        throw ("Game in progress / not started");
    }
    std::vector<std::string> Game::players()
    {
        std::vector <std::string> res;
        for(Player* p : _players){
            if (p->get_status() == Status::alive)
            {
                res.push_back((*p).name());
            }
        }
        return res;
    }

    void Game::add_player(Player* p)
    {
        if(_game_on)
        {
            throw ("you can't join midgame, come early next time");
        }
        _players.push_back(p);
    }

    void Game::activate_game()
    {
        if (!_game_on)
        {
            _game_on = true;
        }
    }

    void Game::end_turn()
    {
        // next alive player
        do {
            _turn_id++;
            _turn_id = _turn_id % (int)_players.size();
        } while (_players.at((size_t)_turn_id)->get_status() != Status::alive);
        // validate last action of the player now playing
        _players.at((size_t)_turn_id)->get_turn();
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