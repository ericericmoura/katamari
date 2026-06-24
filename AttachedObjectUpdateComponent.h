#pragma once

#include "UpdateComponent.h"
#include "EntityTransform.h"

#include "EntityManager.h"

class AttachedObjectUpdateComponent : public UpdateComponent
{
public:
	AttachedObjectUpdateComponent() = default;
	
	void Update(EntityManager& entity_manager) override;

private:
	EntityTransform target_transform_;
};

