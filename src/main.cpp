#include <SFML/Graphics.hpp>

// game's window's dimensions
#define WIDTH 1200
#define HEIGHT 800 


int main ()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "SFML works!");
    const sf::Color backgroundColor = sf::Color(100,100,100); 


    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::KeyPressed:
                if (ev.key.code ==sf::Keyboard::Escape)
                {
                    window.close();
                }
                break;
            
            default:
                break;
            }
        }

        window.clear(backgroundColor);
        window.display();
    }

    return 0;
}