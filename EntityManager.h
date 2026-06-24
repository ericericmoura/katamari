#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "EntityStore.h"
#include "Entity.h"

class EntityManager : public EntityStore
{
public:
	Id AddEntity(Entity&& entity);
	void RemoveEntity(Id id);
	void EnableEntity(Id id);
	void DisableEntity(Id id);

	std::vector<Id> GetIdsByTag(const std::string& tag);
	void AddTagForId(const std::string& tag, Id id);

	Entity* GetEntityById(Id id);

private:
	Id current_id_ = 0;

	std::unordered_map<std::string, std::vector<Id>> ids_;

	Entity* GetEntityById(Id id, std::unordered_map<Id, Entity>& map);
};

