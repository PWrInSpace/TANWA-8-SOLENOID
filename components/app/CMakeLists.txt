idf_component_register(
    SRC_DIRS "."
    INCLUDE_DIRS "."
    REQUIRES config can Board_Data cli solenoids
)


target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format" "-Wall" "-Werror")
