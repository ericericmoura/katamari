#pragma once

#include <string>
#include <memory>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "StandardGraphicsComponent.h"

class Entity : public sf::Transformable, public sf::Drawable
{
public:
	Entity();
	Entity(const sf::Texture* texture);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	StandardGraphicsComponent<sf::CircleShape> graphics_{};	
};

