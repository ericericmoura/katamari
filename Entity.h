#pragma once

#include <memory>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "GraphicsComponent.h"
#include "UpdateComponent.h"
#include "EntityManager.h"

class Entity : public sf::Transformable, public sf::Drawable
{
public:
	Entity();
	Entity(const sf::Texture* texture, std::unique_ptr<GraphicsComponent> graphics);

	void Update(EntityManager& entity_manager);
	void PhysicsUpdate(float delta);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::unique_ptr<GraphicsComponent> graphics_{};
	std::unique_ptr<UpdateComponent>   update_component_{};
};

