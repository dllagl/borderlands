set(LIBNAME "firearms")

# add src files to firearms library 
add_library( ${LIBNAME}
    Bullet.cpp  
    Firearm.cpp
    Pistol.cpp
    Smg.cpp
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