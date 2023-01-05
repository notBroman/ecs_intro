#pragma once
#include <string>

#include "Components/CTransform.hpp"
#include "Components/CName.hpp"
#include "Components/CShape.hpp"
#include "Components/CBBox.hpp"

class Entity{
    private:
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
        std::shared_ptr<CBBox> cBBox;


        void destroy();

        const std::string& tag();

        friend class EntityManager;
};
