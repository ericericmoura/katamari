#include "EntityManager.h"

#include <utility>
#include <string>
#include <vector>

#include "Entity.h"
#include "EntityStore.h"
#include <unordered_map>

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

std::vector<Id> EntityManager::GetIdsByTag(const std::string& tag)
{
	auto it = ids_.find(tag);
	if (it != ids_.end())
	{
		return it->second;
	}
	return std::vector<Id>();
}

void EntityManager::AddTagForId(const std::string& tag, Id id)
{
	ids_[tag].push_back(id);
}

Entity* EntityManager::GetEntityById(Id id)
{	
	auto entity = GetEntityById(id, active_entities_);
	if (entity == nullptr)
	{
		entity = GetEntityById(id, inactive_entities_);
	}
	return entity;
}

Entity* EntityManager::GetEntityById(Id id, std::unordered_map<Id, Entity>& map)
{
	auto it = map.find(id);
	if (it == map.end())
	{
		return nullptr;
	}
	return &it->second;
}
