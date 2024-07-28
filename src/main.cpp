#include <SFML/Graphics.hpp>
#include "gui/mainwindow.h"

int main()
{
    // Initialize SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flight Navigation System");

    MainWindow mainWindow;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mainWindow.draw(window);
        window.display();
    }

    return 0;
}
