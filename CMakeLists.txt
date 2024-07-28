cmake_minimum_required(VERSION 3.28)
project(FlightNavigationSystem)

set(CMAKE_CXX_STANDARD 17)

# Include FetchContent module
include(FetchContent)

# Fetch the nlohmann_json library
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(nlohmann_json)

# Load environment variables from .env file
include(${CMAKE_SOURCE_DIR}/cmake/LoadEnv.cmake)
load_env_file(${CMAKE_SOURCE_DIR}/.env)

# Set CURL paths
set(CURL_INCLUDE_DIR $ENV{CURL_PATH}/include)
set(CURL_LIBRARY $ENV{CURL_PATH}/lib/libcurl.dll.a)

# Set SFML paths
set(SFML_ROOT $ENV{SFML_PATH})
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

# Find packages
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(CURL REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include ${SFML_INCLUDE_DIR} ${CURL_INCLUDE_DIR})

# Add the executable
add_executable(FlightNavigationSystem
        src/main.cpp
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
        src/controllers/flight_controller.h
)

# Link libraries
target_link_libraries(FlightNavigationSystem
        sfml-graphics
        sfml-window
        sfml-system
        ${CURL_LIBRARY}
        nlohmann_json::nlohmann_json
)
