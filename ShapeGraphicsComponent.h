#pragma once

#include <utility>
#include <concepts>

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

template <typename T>
concept Drawable = std::derived_from<T, sf::Shape>;

template <Drawable T>
class ShapeGraphicsComponent : public GraphicsComponent
{
public:
	ShapeGraphicsComponent() = default;	

	template <typename ... Args>
	ShapeGraphicsComponent(Args&& ... args) 
		: graphics_(std::forward<Args>(args)...)
	{
	}

	T& GetGraphics()
	{
		return graphics_;
	}

	virtual void SetTexture(const sf::Texture* texture) override
	{
		graphics_.setTexture(texture);
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{		
		states.transform *= getTransform();

		target.draw(graphics_, states);
	};

private:
	T graphics_;
};