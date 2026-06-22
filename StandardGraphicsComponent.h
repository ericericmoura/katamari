#pragma once

#include <utility>
#include <concepts>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

template <typename T>
concept Drawable = std::derived_from<T, sf::Drawable>;

template <Drawable T>
class StandardGraphicsComponent : public sf::Drawable
{
public:
	StandardGraphicsComponent() = default;

	template <typename ... Args>
	StandardGraphicsComponent(Args&& ... args)
		: graphics_(std::forward<Args>(args)...)
	{
	}

	T& GetGraphics()
	{
		return graphics_;
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{		
		target.draw(graphics_, states);
	};

private:
	T graphics_;
};

