#include "gui/mainwindow.h"

MainWindow::MainWindow() {
    shape = sf::CircleShape(50);
    shape.setFillColor(sf::Color::Green);

    std::vector<sf::Vector2f> route = {
        {100, 100}, {200, 200}, {300, 100}, {400, 200}
    };
    mapDrawer.setRoute(route);
}

void MainWindow::draw(sf::RenderWindow &window) {
    window.draw(shape);
    mapDrawer.draw(window);
}
