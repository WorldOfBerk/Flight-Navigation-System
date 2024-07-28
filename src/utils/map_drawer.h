#ifndef MAP_DRAWER_H
#define MAP_DRAWER_H

#include <SFML/Graphics.hpp>
#include <vector>

class MapDrawer {
public:
    MapDrawer();
    void draw(sf::RenderWindow &window);
    void setRoute(const std::vector<sf::Vector2f> &route);

private:
    std::vector<sf::Vector2f> route;
    sf::VertexArray lines;
};

#endif //MAP_DRAWER_H
