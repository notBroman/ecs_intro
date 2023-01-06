#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "EntityManager.hpp"

class Game{

    std::string name;

public:
    Game(std::string n);
    void run();
};
