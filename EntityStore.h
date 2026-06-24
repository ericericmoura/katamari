#pragma once

#include <unordered_map>
#include <cstdint>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Entity.h"

using Id = uint32_t;

class EntityStore : public sf::Drawable
{
public:
	EntityStore();

	Id AddEntity(Entity&& entity);
	void RemoveEntity (Id id);
	void EnableEntity (Id id);
	void DisableEntity(Id id);

	void Update();
	void PhysicsUpdate(float delta);	

	// inherited via sf::Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	inline static bool instantiated_ = false;

	std::unordered_map<Id, Entity> active_entities_  ;
	std::unordered_map<Id, Entity> inactive_entities_;

	Id current_id_ = 0;
};
