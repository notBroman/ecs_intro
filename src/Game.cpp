#include "Game.hpp"

Game::Game(const std::string& config){
    init(config);
}

void Game::init(const std::string& config){
    // TO DO read config file
    //      save parameters in the structs
    std::ifstream fin(config);

    // create window for game to draw to
    m_window.create(sf::VideoMode(1280, 720), "Game 2");
    m_window.setFramerateLimit(60);
    spawnPlayer();
}

void Game::run(){
    // TODO: add pause

    while(m_running){
        m_entities.update();


        if(!m_paused){
            sEnemySpawner();
            sMovement();
            sCollision();
            sUserInput();
        }
        sRender();

        m_currentFrame++;
    }
}

void Game::setPaused(bool paused){
    m_paused = paused;
}

void Game::spawnPlayer(){
    // create player entity with entity manager
    auto entity = m_entities.addEntity("player");
    // attach components
    entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f),
            Vec2(2.0f, 2.0f) ,0.0f);
    entity->cShape = std::make_shared<CShape>(32.0f, 8 , sf::Color(10,10,10),
            sf::Color(255,0,0), 4.0f);
    entity->cInput = std::make_shared<CInput>();

}

void Game::spawnEnemy(){
    auto entity = m_entities.addEntity("enemy");
    // random spawn location
    float ex = rand() % m_window.getSize().x;
    float ey = rand() % m_window.getSize().y;
    // attach components
    entity->cTransform = std::make_shared<CTransform>(Vec2(ex, ey),
            Vec2(1.0f, 1.0f) ,0.0f);
    entity->cShape = std::make_shared<CShape>(32.0f, 3, sf::Color(10,10,10),
            sf::Color(0,0,255), 4.0f);

    m_lastEnemySpawn = m_currentFrame;
}

void Game::sEnemySpawner(){
    if(m_currentFrame == 0){ spawnEnemy(); };
}

void Game::sUserInput(){
    // TODO
    sf::Event event;
    while (m_window.pollEvent(event)){
        // if closing is requested, the window is closed
        if (event.type == sf::Event::Closed)
            m_running = false;

        auto p = m_entities.getEntities("player")[0];
        if(event.type == sf::Event::KeyPressed){
            switch(event.key.code){
                case sf::Keyboard::W:
                    p->cInput->up = true;
                    break;

                case sf::Keyboard::A:
                    p->cInput->left = true;
                    break;

                case sf::Keyboard::S:
                    p->cInput->down = true;
                    break;

                case sf::Keyboard::D:
                    p->cInput->right = true;
                    break;

                default:
                    break;
            }
        }

        if(event.type == sf::Event::KeyReleased){
            switch(event.key.code){
                case sf::Keyboard::W:
                    p->cInput->up = false;
                    break;

                case sf::Keyboard::A:
                    p->cInput->left = false;
                    break;

                case sf::Keyboard::S:
                    p->cInput->down = false;
                    break;

                case sf::Keyboard::D:
                    p->cInput->right = false;
                    break;

                default:
                    break;
            }
        }
    }
}

void Game::sMovement(){
    // TODO
    auto p = m_entities.getEntities("player")[0];
    if(p->cInput->up){
        p->cTransform->pos.y -= p->cTransform->velocity.y;
    }
    if(p->cInput->left){
        p->cTransform->pos.x -= p->cTransform->velocity.x;
    }
    if(p->cInput->down){
        p->cTransform->pos.y += p->cTransform->velocity.y;
    }
    if(p->cInput->right){
        p->cTransform->pos.x += p->cTransform->velocity.x;
    }
}

void Game::sCollision(){
    // TODO
}

void Game::sLifespan(){
    // TODO
}

void Game::sRender(){
    m_window.clear();

    for(auto& e : m_entities.getEntities()){

        // move entities
        e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);

        // rotate entities
        e->cTransform->angle += 1.0f;
        e->cShape->circle.setRotation(e->cTransform->angle);

        // draw all entities
        m_window.draw(e->cShape->circle);
    }
    // display drawn stuff in window
    m_window.display();
}
