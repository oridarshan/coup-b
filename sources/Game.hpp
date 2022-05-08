#pragma once
#include <string>
#include <vector>
namespace coup
{
    class Game
    {
    private:
        std::vector<std::string> _players;
    public:
        Game();
        ~Game();
        std::string turn();
        std::string winner();
        std::vector<std::string> players();
        
    };
}