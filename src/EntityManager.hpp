#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include "Entity.hpp"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap; // could be done with enum instead

class EntityManager{
    // factory for entities
    private:
        EntityVec m_entities;
        EntityVec m_toAdd;
        EntityMap m_entityMap;
        size_t m_totalEntities = 0;


    public:
        // constructor
        EntityManager();

        void update();
        std::shared_ptr<Entity> addEntity(const std::string& tag);

        // getters
        EntityVec& getEntities();
        EntityVec& getEntities(const std::string& tag);

};
