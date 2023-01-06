#include "Entity.hpp"

Entity::Entity(const std::string& tag, size_t id) : m_tag(tag), m_id(id) {
    m_alive = true;
}

void Entity::destroy(){
    m_alive = false;
}

const std::string& Entity::tag() const {
    return m_tag;
}

bool Entity::isAlive() const {
    return m_alive;
}

const size_t Entity::id() const {
    return m_id;
}
