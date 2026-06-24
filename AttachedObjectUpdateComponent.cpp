#include "AttachedObjectUpdateComponent.h"
#include "EntityManager.h"

AttachedObjectUpdateComponent::AttachedObjectUpdateComponent(EntityTransform target_transform)
	: target_transform_(target_transform)
{}

void AttachedObjectUpdateComponent::Update(EntityManager& entity_manager)
{
}
