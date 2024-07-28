#include "gui/mainwindow.h"
#include <iostream>

MainWindow::MainWindow() {
    shape = sf::CircleShape(50);
    shape.setFillColor(sf::Color::Green);

    std::vector<sf::Vector2f> route = {
        {100, 100}, {200, 200}, {300, 100}, {400, 200}
    };
    mapDrawer.setRoute(route);

    // Simulate initial engine data update
    engineData.update(0.0f, 300.0f, 10000.0f);
    std::cout << engineData.getStatus() << std::endl;

    // Get weather data for Berlin
    std::string weatherData = ApiHandler::getWeatherData(52.52, 13.41, "1949-12-28", "1949-12-31");
    std::cout << weatherData << std::endl;
}

void MainWindow::draw(sf::RenderWindow &window) {
    window.draw(shape);
    mapDrawer.draw(window);
}
