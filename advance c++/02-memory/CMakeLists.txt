aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_LIST)
message( "source=${SOURCE_LIST}" )

add_executable( Lesson_02 ${SOURCE_LIST} )
target_link_libraries( Lesson_02 pdcurses framework)
