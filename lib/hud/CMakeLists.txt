set(LIBNAME "hud")

# add src files to hud library 
add_library( ${LIBNAME}
    Hud.cpp
    Hud_firearm.cpp
    Hud_shield.cpp
    Hud_health.cpp
)

# Include dir for headers
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include) 

# Compile options
target_compile_options( ${LIBNAME}
PRIVATE
    # RELEASE BUILD:
    $<$<CONFIG:RELEASE>:-O3> # Optimisations level 3
    # DEBUG BUILD:
    $<$<CONFIG:DEBUG>:-O0> # Disable optimisations
    $<$<CONFIG:DEBUG>:-g> # Enable debug symbols
)                       

# Link options
target_link_libraries( ${LIBNAME} sfml-graphics sfml-window sfml-system )