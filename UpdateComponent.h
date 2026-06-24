#pragma once

#include "EntityTransform.h"
#include "EntityManager.h"

class UpdateComponent
{
public:	
	virtual void Update(EntityManager& entity_manager) = 0;
	virtual void PhysicsUpdate(float delta) = 0;

	EntityTransform GetTransform() const
	{
		return transform_;
	}	

protected:
	EntityTransform transform_{};
};

