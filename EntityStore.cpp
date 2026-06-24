#include "EntityStore.h"

#include <cassert>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Entity.h"

EntityStore::EntityStore()
{
	assert(!instantiated_);
	instantiated_ = true;
}

void EntityStore::Update()
{
	for (auto& [id, entity] : active_entities_)
	{
		entity.Update(*this);
	}
}

void EntityStore::PhysicsUpdate(float delta)
{
	for (auto& [id, entity] : active_entities_)
	{
		entity.PhysicsUpdate(delta);
	}
}

void EntityStore::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& [id, entity] : active_entities_)
	{
		target.draw(entity);
	}
	for (auto& [id, entity] : inactive_entities_)
	{
		target.draw(entity);
	}
}

// ENTITY MANAGER INTERFACE

Id EntityStore::AddEntity(Entity&& entity)
{
	active_entities_.emplace(current_id_, std::move(entity));
	return current_id_++;
}

void EntityStore::RemoveEntity(Id id)
{
	active_entities_.erase(id);
}

void EntityStore::EnableEntity(Id id)
{
	auto it = inactive_entities_.find(id);
	if (it != inactive_entities_.end())
	{
		active_entities_.emplace(it->first, std::move(it->second));
		inactive_entities_.erase(it);
	}
}

void EntityStore::DisableEntity(Id id)
{
	auto it = active_entities_.find(id);
	if (it != active_entities_.end())
	{
		inactive_entities_.emplace(it->first, std::move(it->second));
		active_entities_.erase(it);
	}
}

std::vector<Id> EntityStore::GetIdsByTag(const std::string& tag)
{
	auto it = ids_.find(tag);
	if (it != ids_.end())
	{
		return it->second;
	}
	return std::vector<Id>();
}

void EntityStore::AddTagForId(const std::string& tag, Id id)
{
	ids_[tag].push_back(id);
}

Entity* EntityStore::GetEntityById(Id id)
{
	auto entity = GetEntityById(id, active_entities_);
	if (entity == nullptr)
	{
		entity = GetEntityById(id, inactive_entities_);
	}
	return entity;
}

Entity* EntityStore::GetEntityById(Id id, std::unordered_map<Id, Entity>& map)
{
	auto it = map.find(id);
	if (it == map.end())
	{
		return nullptr;
	}
	return &it->second;
}
