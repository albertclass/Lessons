
include_directories("framework")

aux_source_directory(./framework FRAMEWORK_SOURCE_LIST)
add_library(framework STATIC ${FRAMEWORK_SOURCE_LIST})

message("${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("${LIBRARY_OUTPUT_DIRECTORY}")

add_subdirectory( "01-types" ${RUNTIME_OUTPUT_DIRECTORY}/01 )
add_subdirectory( "02-memory" ${RUNTIME_OUTPUT_DIRECTORY}/02 )

