#include "Entity.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Entity::Entity() 
	: graphics_(120, 32)
{	
}

Entity::Entity(const sf::Texture* texture)
	: Entity()
{
	graphics_.GetGraphics().setTexture(texture);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw(graphics_, states);
}
