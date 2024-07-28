#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>

class MainWindow {
public:
    MainWindow();
    void draw(sf::RenderWindow &window);

private:
    sf::CircleShape shape;
};

#endif //MAINWINDOW_H
