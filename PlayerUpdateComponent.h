#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "UpdateComponent.h"
#include "EntityManager.h"

class PlayerUpdateComponent : public UpdateComponent
{
public:
	PlayerUpdateComponent(
		float speed,
		sf::Keyboard::Scancode left_key ,
		sf::Keyboard::Scancode right_key,
		sf::Keyboard::Scancode up_key   ,
		sf::Keyboard::Scancode down_key
	);	

	void Update(EntityManager& entity_manager) override;
	void PhysicsUpdate(float delta) override;

	void SetInputMap(
		sf::Keyboard::Scancode left_key ,
		sf::Keyboard::Scancode right_key,
		sf::Keyboard::Scancode up_key   ,
		sf::Keyboard::Scancode down_key
	);

private:
	float speed_ = 30.f;
	float rotational_speed_ = 45.f;
	
	sf::Keyboard::Scancode left_key_ {};
	sf::Keyboard::Scancode right_key_{};
	sf::Keyboard::Scancode up_key_   {};
	sf::Keyboard::Scancode down_key_ {};

	sf::Vector2f direction_{};

	sf::Vector2f GetInputDirection() const;
};
