
option(BUILD_CLI "Build command line interfaces" ON)

include(GenerateExportHeader)

# Core
add_subdirectory(giste-core)

# Engine
add_subdirectory(giste-engine)


