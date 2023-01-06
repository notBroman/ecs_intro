#include "EntityManager.hpp"

void EntityManager::update() {
    // calle at the beginning of each frame by the game engine
    // entities add will now be available to use this frame
    for(auto e : m_toAdd){
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    m_toAdd.clear();
/*
    // deal with dead entities
    // if e is dead, remove it from m_entities
    // if e is dead, remove if from m_entitymap->tag()
    m_entities.erase(std::remove_if(m_entities.begin(),
            m_entities.end(),
            [](Entity& x){return x->m_alive == false; }), m_entities.end());

    m_entityMap.erase(std::remove_if(m_entities.begin(),
            m_entities.end(),
            [](Entity& x){return x->m_alive == false; }), m_entities.end());
*/
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag){
    /*
     * create new Entiity object
     * store it in the vecotr of all Entities
     * store it in the map of tag->entityvector
     * return the shared pointer to that entity
     */

    // this does not handle some map-related edge cases

    auto e = std::make_shared<Entity>(*(new Entity(tag, ++m_totalEntities)));
    m_toAdd.push_back(e);
    return e;
}

EntityVec& EntityManager::getEntities(){
    return m_entities;
}


EntityVec& EntityManager::getEntities(const std::string& tag){
    return m_entityMap[tag];
}
