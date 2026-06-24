#pragma once

#include "EntityStore.h"
#include "Entity.h"

class EntityManager : public EntityStore
{
public:
	Id AddEntity(Entity&& entity);
	void RemoveEntity(Id id);
	void EnableEntity(Id id);
	void DisableEntity(Id id);

private:
	Id current_id_ = 0;
};

