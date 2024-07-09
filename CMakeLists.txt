cmake_minimum_required(VERSION 3.28)
project(FlightNavigationSystem)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(nlohmann_json)

# Load environment variables from .env file
include(${CMAKE_SOURCE_DIR}/cmake/LoadEnv.cmake)
load_env_file(${CMAKE_SOURCE_DIR}/.env)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set CURL paths
set(CURL_INCLUDE_DIR $ENV{CURL_PATH}/include)
set(CURL_LIBRARY $ENV{CURL_PATH}/lib/libcurl.dll.a)

# Include FindSFML module
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

include(FindSFML)

# Find cURL
find_package(CURL REQUIRED)

add_executable(FlightNavigationSystem src/main.cpp
        src/gui/mainwindow.cpp
        src/gui/mainwindow.h
        src/utils/api_handler.cpp
        src/utils/api_handler.h
        src/utils/flight_data.cpp
        src/utils/flight_data.h
        src/utils/map_drawer.cpp
        src/utils/map_drawer.h
        src/utils/engine_data.cpp
        src/utils/engine_data.h
        src/models/mustang_p.cpp
        src/models/mustang_p.h
        src/controllers/flight_controller.cpp
        src/controllers/flight_controller.h)

# Link libraries
target_link_libraries(FlightNavigationSystem
        ${SFML_LIBRARIES}
        ${CURL_LIBRARY}
        nlohmann_json::nlohmann_json
)

include_directories(${SFML_INCLUDE_DIRS} ${CURL_INCLUDE_DIR})