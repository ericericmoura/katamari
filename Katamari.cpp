#include <string>

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Entity.h"
#include "BitmapStore.h"
#include <SFML/System/Clock.hpp>

struct WindowConfiguration
{
	static inline std::string title_ = "katamari";
	static inline sf::State   state_ = sf::State::Fullscreen;
};

int main()
{
	BitmapStore store{};

	Entity player{ store.GetTexture("./graphics/scales.jpg") };
	player.setPosition({ 100.f, 100.f });

	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
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

		float delta = frame_clock.restart().asSeconds();

		player.Update();
		player.PhysicsUpdate(delta);

		window.clear(sf::Color::Blue);
		window.draw(player);
		window.display();
	}
}