#include "Entity.h"

#include <memory>
#include <utility>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "PlayerUpdateComponent.h"
#include "EntityTransform.h"
#include "GraphicsComponent.h"
#include "EntityManager.h"

Entity::Entity()
{	
	update_component_ = std::make_unique<PlayerUpdateComponent>(
		250.0f, 
		sf::Keyboard::Scancode::A,
		sf::Keyboard::Scancode::D,
		sf::Keyboard::Scancode::W,
		sf::Keyboard::Scancode::S);
}

Entity::Entity(const sf::Texture* texture, std::unique_ptr<GraphicsComponent> graphics)
	: Entity()
{
	graphics_ = std::move(graphics);

	graphics_->SetTexture(texture);
	graphics_->setOrigin(
		{
			64.f,
			64.f
		});
}

void Entity::Update(EntityManager& entity_manager)
{
	update_component_->Update(entity_manager);
}

void Entity::PhysicsUpdate(float delta)
{
	update_component_->PhysicsUpdate(delta);

	EntityTransform transform = update_component_->GetTransform();
	graphics_->setPosition(transform.Position);
	graphics_->setRotation(transform.Rotation);
	graphics_->setScale   (transform.Scale);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw(*graphics_, states);
}
