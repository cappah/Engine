//
//  Author: Shervin Aflatooni
//

#ifndef FREE_MOVE_H
#define FREE_MOVE_H

#include "../EntityComponent.h"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class FreeMove : public EntityComponent
{
public:
  FreeMove(bool moveForwards = true, float speed = 0.01f);
  ~FreeMove(void);

  virtual void updateInput(Input *input, int delta);

  inline virtual const char *getType(void) { return "FREE_MOVE"; }

private:
  void Move(const glm::vec3& direction, float amount);

  float m_speed;
  bool m_moveForwards;
};

#endif
