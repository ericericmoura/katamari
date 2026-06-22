#pragma once

#include <unordered_map>
#include <string>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

class BitmapStore
{
public:
	BitmapStore();
	sf::Texture* GetTexture(const std::string& key);

private:
	inline static bool instantiated_ = false;

	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> map_;
};

