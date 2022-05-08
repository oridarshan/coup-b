#include "Game.hpp"

namespace coup{
    
    std::string Game::turn(){return "";}
    std::string Game::winner(){return "";}
    std::vector<std::string> Game::players(){
        std::vector<std::string> p{"","","","","",""};
        return p;
    }

    Game::Game()
    {
    }

    Game::~Game()
    {
    }
}