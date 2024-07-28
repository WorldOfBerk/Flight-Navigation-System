#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include "utils/map_drawer.h"
#include "utils/engine_data.h"
#include "utils/api_handler.h"

class MainWindow {
public:
    MainWindow();
    void draw(sf::RenderWindow &window);

private:
    MapDrawer mapDrawer;
    sf::CircleShape shape;
    EngineData engineData;
};

#endif //MAINWINDOW_H
