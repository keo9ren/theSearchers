macro (add_sources)
    file (RELATIVE_PATH _relPath "${CMAKE_SOURCE_DIR}/src" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SRCS "${_relPath}/${_src}")
        else()
            list (APPEND SRCS "${_src}")
        endif()
    endforeach()
    if (_relPath)
        # propagate SRCS to parent directory
        set (SRCS ${SRCS} PARENT_SCOPE)
    endif()
endmacro()

INCLUDE_DIRECTORIES(
GSL/gsl/
input/
regex/
readfile
)


add_sources(main.cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/input)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/regex)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/readfile)

find_program(iwyu_path NAMES include_what-you-use iwyu)
if(NOT iwyu_path)
message(FATAL_ERROR "no iwyu")
endif()

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
add_library(lib_search STATIC ${SRCS})
set_target_properties(lib_search PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ../testBin)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path})
target_link_libraries (${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND size --format=berkeley ${CMAKE_PROJECT_NAME})
