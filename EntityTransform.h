#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Angle.hpp>

struct EntityTransform
{
	sf::Vector2f Position{};
	sf::Vector2f Scale{1.0f, 1.0f};
	sf::Angle    Rotation{};
};