//
//  Author: Shervin Aflatooni
//

#include "PhysicsManager.h"

#include <glm/gtx/norm.hpp>

#include <algorithm>

PhysicsManager::PhysicsManager(void)
{
}

PhysicsManager::~PhysicsManager(void)
{
}

void PhysicsManager::registerCollider(Sphere *sphere)
{
  m_colliders.push_back(sphere);
}

void PhysicsManager::deregisterCollider(Sphere *sphere)
{
  m_colliders.erase(std::remove(m_colliders.begin(), m_colliders.end(), sphere), m_colliders.end());
}

Entity *PhysicsManager::pick(Ray *ray) const
{
  glm::vec3 intersectionPosition;
  float closest = std::numeric_limits<float>::max();
  Entity *entity = NULL;

  for (unsigned int i = 0; i < m_colliders.size(); i++)
  {
    if (ray->intersects(m_colliders[i], intersectionPosition)) {
      float length = glm::length2(intersectionPosition - ray->getPosition());
      if (length < closest)
        entity = m_colliders[i]->getParent();
    }
  }

  return entity;
}
