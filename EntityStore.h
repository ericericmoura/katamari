#pragma once

#include <unordered_map>
#include <cstdint>
#include <string>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Entity.h"
#include "EntityManager.h"

using Id = uint32_t;

class EntityStore : public sf::Drawable, public EntityManager
{
public:
	EntityStore();

	void Update();
	void PhysicsUpdate(float delta);	
	// inherited via sf::Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Inherited via EntityManager
	Id AddEntity(Entity&& entity) override;
	void RemoveEntity(Id id) override;
	void EnableEntity(Id id) override;
	void DisableEntity(Id id) override;

	std::vector<Id> GetIdsByTag(const std::string& tag) override;
	void AddTagForId(const std::string& tag, Id id) override;
	Entity* GetEntityById(Id id) override;

protected:
	std::unordered_map<Id, Entity> active_entities_  ;
	std::unordered_map<Id, Entity> inactive_entities_;

	Entity* GetEntityById(Id id, std::unordered_map<Id, Entity>& map) override;

private:
	inline static bool instantiated_ = false;	
};
