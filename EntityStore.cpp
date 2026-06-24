#include "EntityStore.h"

#include <cassert>

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
