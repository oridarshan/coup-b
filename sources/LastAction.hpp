#pragma once

namespace coup
{
    class Player;

    enum Action{income, forien_aid, coup, block, transfer, tax, steal, assassinate};

    struct LastAction
    {
        Action action;
        Player* subject;
    };
}