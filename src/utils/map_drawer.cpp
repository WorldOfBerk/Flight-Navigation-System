#include "utils/map_drawer.h"

MapDrawer::MapDrawer() : lines(sf::LinesStrip) {}

void MapDrawer::setRoute(const std::vector<sf::Vector2f> &route) {
    this->route = route;
    lines.clear();
    for (const auto& point : route) {
        lines.append(sf::Vertex(point, sf::Color::Red));
    }
}

void MapDrawer::draw(sf::RenderWindow &window) {
    window.draw(lines);
}
