
include_directories("framework")

aux_source_directory(./framework FRAMEWORK_SOURCE_LIST)
add_library(framework STATIC ${FRAMEWORK_SOURCE_LIST})

add_subdirectory( "01-types" ${BINARY_OUTPUT}/01 )
add_subdirectory( "02-memory" ${BINARY_OUTPUT}/02 )

