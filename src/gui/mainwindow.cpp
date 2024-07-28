#include "mainwindow.h"

MainWindow::MainWindow() {
    shape = sf::CircleShape(50);
    shape.setFillColor(sf::Color::Green);
}

void MainWindow::draw(sf::RenderWindow &window) {
    window.draw(shape);
}
