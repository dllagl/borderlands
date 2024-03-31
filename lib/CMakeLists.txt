# Name of the library
set(LIBNAME "game")

# Add the library "game" and its source files
add_library( ${LIBNAME}
    Game.cpp
    Player.cpp
    Main_menu.cpp
    Button.cpp
)

# Include dir 
target_include_directories( ${LIBNAME} PUBLIC include ) # for the hpp files


# Compile options
target_compile_options( ${LIBNAME}
PRIVATE
# RELEASE BUILD:
$<$<CONFIG:RELEASE>:-O3> # Optimisations level 3
# DEBUG BUILD:
$<$<CONFIG:DEBUG>:-O0> # Disable optimisations
$<$<CONFIG:DEBUG>:-g> # Enable debug symbols
)


# Add the hud library
add_subdirectory(hud)
target_link_libraries(${LIBNAME} hud)

# Add the hud library
add_subdirectory(firearms)
target_link_libraries(${LIBNAME} firearms)

# Link options
target_link_libraries( ${LIBNAME} sfml-graphics sfml-window sfml-system )




