idf_component_register(  SRC_DIRS "."
                         INCLUDE_DIRS "."
                         REQUIRES Board_Data config driver )

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format" "-Wall" "-Werror")