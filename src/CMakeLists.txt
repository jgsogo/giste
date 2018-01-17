
include(GenerateExportHeader)

configure_file(version.h.template ${CMAKE_CURRENT_LIST_DIR}/protozoo-version.h)

# Default configuration file
set(CONFIG_YAML_DEFAULT ${CMAKE_INSTALL_PREFIX}/bin/config.yaml)
message("Create default config.yaml file at '${CONFIG_YAML_DEFAULT}'")
configure_file(config.yaml.template ${CONFIG_YAML_DEFAULT})

# Core
add_subdirectory(protozoo-utils)
add_subdirectory(protozoo-core)

# Engine
add_subdirectory(protozoo-engine)

# Plugins
add_subdirectory(protozoo-plugin-pln)

