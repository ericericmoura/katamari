#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>

class GraphicsComponent : public sf::Drawable, public sf::Transformable
{
public:
	virtual void SetTexture(const sf::Texture* texture) = 0;
};

