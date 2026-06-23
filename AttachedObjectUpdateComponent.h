#pragma once

#include "UpdateComponent.h"
#include "EntityTransform.h"

class AttachedObjectUpdateComponent : public UpdateComponent
{
public:
	AttachedObjectUpdateComponent(EntityTransform target_transform);
	
	void Update() override;

private:
	EntityTransform& target_transform_;
};

