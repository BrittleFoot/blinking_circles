#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <map>





class Kruzho4ek: public sf::CircleShape
{
public:

    Kruzho4ek(unsigned int radius): sf::CircleShape(radius) {
        m_age = sf::Time();
        show_time = sf::Time();
        hide_time = sf::Time();
        m_hidden_color = sf::Color(0, 0, 0, 0);
        m_actual_color = sf::Color(255, 255, 255, 255);
    }

    void update(sf::Time dt) {
        m_age += dt;

        if (is_hidden && m_age > hide_time) {
            m_age -= hide_time;
            is_hidden = false;
        }

        if (!is_hidden && m_age > show_time) {
            m_age -= show_time;
            is_hidden = true;
        }

        setFillColor(is_hidden ? m_hidden_color : m_actual_color);
    }


    void setColor(sf::Color color) {
        m_actual_color = sf::Color(color);
    }

    sf::Time show_time;
    sf::Time hide_time; 

private:

    sf::Color m_hidden_color;
    sf::Color m_actual_color;

    sf::Time m_age;
    bool     is_hidden;
};




int main(void) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    Kruzho4ek k(100);
    k.setPosition(sf::Vector2f(100, 100));
    k.setColor(sf::Color(255, 0, 0));
    k.show_time = sf::milliseconds(1000);
    k.hide_time = sf::milliseconds(1000);

    sf::Clock clock;
    clock.restart();

    while (window.isOpen()) {
        sf::Time dt = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        k.update(dt);

        window.clear();
        window.draw(k);

        window.display();

    }

    return 0;
}