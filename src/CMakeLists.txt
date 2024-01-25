# Nom de l'executable
set(EXENAME "game.app")

# Add a new executable
add_executable(${EXENAME} main.cpp)

# Compile options
target_compile_options(${EXENAME}
PRIVATE
    # RELEASE BUILD:
    $<$<CONFIG:RELEASE>:-O3> # Optimisations level 3
    # DEBUG BUILD:
    $<$<CONFIG:DEBUG>:-O0> # Disable optimisations
    $<$<CONFIG:DEBUG>:-g> # Enable debug symbols
)                       

# Link options
target_link_libraries(${EXENAME} sfml-graphics sfml-window sfml-system )

# Install executable to the binary directory
install(TARGETS ${EXENAME} DESTINATION ${CMAKE_BINARY_DIR})
