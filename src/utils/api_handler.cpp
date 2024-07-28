#include "utils/api_handler.h"
#include <curl/curl.h>
#include <iostream>
#include <sstream>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string ApiHandler::getWeatherData(double latitude, double longitude, const std::string &startDate, const std::string &endDate) {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    if (curl) {
        std::ostringstream urlStream;
        urlStream << "https://archive-api.open-meteo.com/v1/archive?latitude=" << latitude
                  << "&longitude=" << longitude
                  << "&start_date=" << startDate
                  << "&end_date=" << endDate
                  << "&hourly=temperature_2m&timezone=Europe%2FBerlin";
        std::string url = urlStream.str();

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}
