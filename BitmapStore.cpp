#include "BitmapStore.h"

#include <SFML/Graphics/Texture.hpp>

#include <iostream>
#include <cassert>
#include <string>
#include <memory>

BitmapStore::BitmapStore()
{
	assert(!instantiated_);
	instantiated_ = true;
}

sf::Texture* BitmapStore::GetTexture(const std::string& key)
{
	auto it = map_.find(key);
	if (it != map_.end())
	{
		return it->second.get();
	}
	map_[key] = std::make_unique<sf::Texture>();
	bool success = map_[key]->loadFromFile(key);
	if (!success)
	{
		std::cout << "ERROR! Failed to load texture by key " << key << "!";
	}
	return map_[key].get();
}
