#include "EntityStore.h"

#include <cassert>
#include <utility>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Entity.h"

EntityStore::EntityStore()
{
	assert(!instantiated_);
	instantiated_ = true;
}

Id EntityStore::AddEntity(Entity&& entity)
{
	active_entities_.emplace(current_id_++, entity);
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
		active_entities_.emplace(std::move(it->second));
		inactive_entities_.erase(it);
	}
}

void EntityStore::DisableEntity(Id id)
{
	auto it = active_entities_.find(id);
	if (it != active_entities_.end())
	{
		inactive_entities_.emplace(std::move(it->second));
		active_entities_.erase(it);
	}
}

void EntityStore::Update()
{
	for (auto& [id, entity] : active_entities_)
	{
		entity.Update();
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
