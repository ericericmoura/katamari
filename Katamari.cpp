#include <string>
#include <utility>
#include <memory>

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>

#include "Entity.h"
#include "BitmapStore.h"
#include "EntityStore.h"
#include "ShapeGraphicsComponent.h"

struct WindowConfiguration
{
	static inline std::string title_ = "katamari";
	static inline sf::State   state_ = sf::State::Fullscreen;
};

int main()
{
	BitmapStore bitmap_store{};
	EntityStore entity_store{};

	Entity player{ 
		bitmap_store.GetTexture("./graphics/scales.jpg"), 
		std::make_unique<ShapeGraphicsComponent<sf::CircleShape>>(64.f, 32.f)
	};
	player.setPosition({ 100.f, 100.f });

	entity_store.AddEntity(std::move(player));

	auto mode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(mode, WindowConfiguration::title_, WindowConfiguration::state_);
	
	sf::Clock frame_clock{};
	while (window.isOpen())
	{		
		while (auto event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		auto delta = frame_clock.restart().asSeconds();

		entity_store.Update();
		entity_store.PhysicsUpdate(delta);

		window.clear(sf::Color::Blue);
		window.draw(entity_store);
		window.display();
	}
}