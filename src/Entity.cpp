#include "Entity.hpp"

Entity::Entity(const std::string& tag, size_t id) : m_tag(tag), m_id(id) {
    m_alive = true;
}

void Entity::destroy(){
    m_alive = false;
}

const std::string& Entity::tag(){
    return m_tag;
}
