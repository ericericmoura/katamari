#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>

using Id = uint32_t;

class Entity;

class EntityManager
{
public:
	virtual Id AddEntity(Entity&& entity) = 0;
	virtual void RemoveEntity(Id id)  = 0;
	virtual void EnableEntity(Id id)  = 0;
	virtual void DisableEntity(Id id) = 0;

	virtual std::vector<Id> GetIdsByTag(const std::string& tag) = 0;
	virtual void AddTagForId(const std::string& tag, Id id) = 0;

	virtual Entity* GetEntityById(Id id) = 0;

protected:
	Id current_id_ = 0;

	std::unordered_map<std::string, std::vector<Id>> ids_;

	virtual Entity* GetEntityById(Id id, std::unordered_map<Id, Entity>& map) = 0;
};

