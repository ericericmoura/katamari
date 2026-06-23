#include "PlayerUpdateComponent.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

PlayerUpdateComponent::PlayerUpdateComponent(
	float speed, 
	sf::Keyboard::Scancode left_key, sf::Keyboard::Scancode right_key, 
	sf::Keyboard::Scancode up_key  , sf::Keyboard::Scancode down_key
)
	: speed_    (speed)
	, left_key_ (left_key)
	, right_key_(right_key)
	, up_key_   (up_key)
	, down_key_ (down_key)
{}

void PlayerUpdateComponent::Update()
{	
	direction_ = GetInputDirection();
}

void PlayerUpdateComponent::PhysicsUpdate(float delta)
{
	transform_.Position += direction_ * speed_ * delta;
	transform_.Rotation += sf::degrees(rotational_speed_ * delta);
}

void PlayerUpdateComponent::SetInputMap(
	sf::Keyboard::Scancode left_key , 
	sf::Keyboard::Scancode right_key, 
	sf::Keyboard::Scancode up_key   , 
	sf::Keyboard::Scancode down_key)
{
	left_key_  = left_key;
	right_key_ = right_key;
	up_key_    = up_key;
	down_key_  = down_key;
}

sf::Vector2f PlayerUpdateComponent::GetInputDirection() const
{
	auto left  = static_cast<int>(sf::Keyboard::isKeyPressed(left_key_ ));
	auto right = static_cast<int>(sf::Keyboard::isKeyPressed(right_key_));
	auto up    = static_cast<int>(sf::Keyboard::isKeyPressed(up_key_   ));
	auto down  = static_cast<int>(sf::Keyboard::isKeyPressed(down_key_ ));
	
	sf::Vector2f dir({ static_cast<float>(right - left), static_cast<float>(down - up) });
	if (dir.x == 0 && dir.y == 0)
	{
		return dir;
	}
	return dir.normalized();
}
