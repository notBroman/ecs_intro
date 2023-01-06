#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "EntityManager.hpp"

// structs for config
// to be done

struct BossConfig {
    int HP;
};


struct PlayerConfig {
    int HP;
};

struct BulletConfig {
    int DMG;

};

class Game{

    std::string name;
    sf::RenderWindow m_window;  // window to draw to
    EntityManager m_entities;   // manager for all entities
    sf::Font m_font;            // used font
    sf::Text m_text;

    PlayerConfig m_playerConf;  // save config for player
    BossConfig m_bossConf;      // save config for boss
    BulletConfig m_bulletConf;  // save config for bullets

    int m_currentFrame = 0;     // current frame
    bool m_paused = false;      // is game paused
    bool m_running = true;      // is game running

    void init(const std::string& config);   // init from  config file
    void setPaused(bool paused);            // pause the game

    // systems
    void sMovement();   // System: Movement
    void sUserInput();  // System: User input
    void sLifespan();   // System: Lifespan
    void sRender();     // System: Renderer / drawing to window
    void sEnemySpawner();   // System: Spawn Enemies
    void sCollision();  // System: collisions

    // spawners
    void spawnPlayer(); // spawn player at beginning or after death
    void spawnEnemy();  // spawn Enemies
    // void spawnSmallEnemies(std::shared_ptr<Entity> entity);
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos); // spawn bullets
    //void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

public:
    Game(const std::string& config);
    void run();
};
