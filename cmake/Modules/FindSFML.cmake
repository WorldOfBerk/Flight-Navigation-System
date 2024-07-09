# Find the SFML library
find_path(SFML_INCLUDE_DIR SFML/Graphics.hpp
        PATH_SUFFIXES SFML
        PATHS $ENV{SFML_PATH}/include)

find_library(SFML_GRAPHICS_LIBRARY
        NAMES sfml-graphics
        PATH_SUFFIXES lib
        PATHS $ENV{SFML_PATH}/lib)

find_library(SFML_WINDOW_LIBRARY
        NAMES sfml-window
        PATH_SUFFIXES lib
        PATHS $ENV{SFML_PATH}/lib)

find_library(SFML_SYSTEM_LIBRARY
        NAMES sfml-system
        PATH_SUFFIXES lib
        PATHS $ENV{SFML_PATH}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SFML DEFAULT_MSG
        SFML_INCLUDE_DIR
        SFML_GRAPHICS_LIBRARY
        SFML_WINDOW_LIBRARY
        SFML_SYSTEM_LIBRARY)

if(SFML_FOUND)
    set(SFML_LIBRARIES ${SFML_GRAPHICS_LIBRARY} ${SFML_WINDOW_LIBRARY} ${SFML_SYSTEM_LIBRARY})
    set(SFML_INCLUDE_DIRS ${SFML_INCLUDE_DIR})
endif()
