#include "Entity.h"

#include <memory>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "PlayerUpdateComponent.h"
#include "EntityTransform.h"

Entity::Entity() 
	: graphics_(64.f, 32.f)
{	
	update_component_ = std::make_unique<PlayerUpdateComponent>(
		250.0f, 
		sf::Keyboard::Scancode::A,
		sf::Keyboard::Scancode::D,
		sf::Keyboard::Scancode::W,
		sf::Keyboard::Scancode::S);
}

Entity::Entity(const sf::Texture* texture)
	: Entity()
{
	graphics_.GetGraphics().setTexture(texture);
	graphics_.GetGraphics().setOrigin(
		{
			64.f,
			64.f
		});
}

void Entity::Update()
{
	update_component_->Update();
}

void Entity::PhysicsUpdate(float delta)
{
	update_component_->PhysicsUpdate(delta);

	EntityTransform transform = update_component_->GetTransform();
	graphics_.GetGraphics().setPosition(transform.Position);
	graphics_.GetGraphics().setRotation(transform.Rotation);
	graphics_.GetGraphics().setScale   (transform.Scale);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw(graphics_, states);
}
