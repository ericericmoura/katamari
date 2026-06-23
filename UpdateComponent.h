#pragma once

#include "EntityTransform.h"

class UpdateComponent
{
public:
	virtual void Update() = 0;
	virtual void PhysicsUpdate(float delta) = 0;

	EntityTransform GetTransform() const
	{
		return transform_;
	}

protected:
	EntityTransform transform_{};
};

