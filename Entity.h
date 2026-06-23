#pragma once

#include <memory>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "StandardGraphicsComponent.h"
#include "UpdateComponent.h"

class Entity : public sf::Transformable, public sf::Drawable
{
public:
	Entity();
	Entity(const sf::Texture* texture);

	void Update();
	void PhysicsUpdate(float delta);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	StandardGraphicsComponent<sf::CircleShape> graphics_{};
	std::unique_ptr<UpdateComponent> update_component_{};
};

