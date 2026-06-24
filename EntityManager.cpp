#include "EntityManager.h"

#include <utility>

#include "Entity.h"
#include "EntityStore.h"

Id EntityManager::AddEntity(Entity&& entity)
{
	active_entities_.emplace(current_id_, std::move(entity));
	return current_id_++;
}

void EntityManager::RemoveEntity(Id id)
{
	active_entities_.erase(id);
}

void EntityManager::EnableEntity(Id id)
{
	auto it = inactive_entities_.find(id);
	if (it != inactive_entities_.end())
	{
		active_entities_.emplace(it->first, std::move(it->second));
		inactive_entities_.erase(it);
	}
}

void EntityManager::DisableEntity(Id id)
{
	auto it = active_entities_.find(id);
	if (it != active_entities_.end())
	{
		inactive_entities_.emplace(it->first, std::move(it->second));
		active_entities_.erase(it);
	}
}
