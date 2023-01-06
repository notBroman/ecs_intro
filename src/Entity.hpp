#pragma once
#include <string>

#include "Components.hpp"

class Entity{

    friend class EntityManager;
    // Constructor
    Entity(const std::string& tag, size_t id);

    const size_t m_id = 0;
    const std::string m_tag = "Default"; // could be switched to enum
    bool m_alive = true;

public:
        // All the component options
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CName> cName;
    std::shared_ptr<CShape> cShape;
    std::shared_ptr<CHealth> cHealth;
    std::shared_ptr<CDamage> cDamage;
    std::shared_ptr<CCollision> cCollision;
    std::shared_ptr<CInput> cInput;
    std::shared_ptr<CLifespan> cLifespan;


    void destroy();

    const std::string& tag();

};
