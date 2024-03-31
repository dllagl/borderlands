# Name of the library
set(LIBNAME "game")

# Add the library "game" and its source files
add_library( ${LIBNAME}
    Game.cpp
    Player.cpp
    Bullet.cpp
    Main_menu.cpp
    Button.cpp
    Firearm_smg.cpp
    Firearm_pistol.cpp
    Firearm.cpp
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

# Link options
target_link_libraries( ${LIBNAME} sfml-graphics sfml-window sfml-system )




