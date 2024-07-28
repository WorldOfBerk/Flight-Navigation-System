#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include "utils/map_drawer.h"

class MainWindow {
public:
    MainWindow();
    void draw(sf::RenderWindow &window);

private:
    MapDrawer mapDrawer;
    sf::CircleShape shape;
};

#endif //MAINWINDOW_H
