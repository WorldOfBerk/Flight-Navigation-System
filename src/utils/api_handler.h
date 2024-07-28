#ifndef API_HANDLER_H
#define API_HANDLER_H

#include <string>

class ApiHandler {
public:
    static std::string getWeatherData(double latitude, double longitude, const std::string &startDate, const std::string &endDate);
};

#endif //API_HANDLER_H
