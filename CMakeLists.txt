#SET(CMAKE_BUILD_TYPE "RELEASE")
SET(CMAKE_BUILD_TYPE "DEBUG")
IF(DEFINED CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of
build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug
Release RelWithDebInfo MinSizeRel.")
ELSE()
   SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build,
options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release
RelWithDebInfo MinSizeRel.")
ENDIF()

SET(CMAKE_EXPORT_COMPILE_COMMANDS "ON")
IF(DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
   SET(CMAKE_EXPORT_COMPILE_COMMANDS ${CMAKE_EXPORT_COMPILE_COMMANDS} CACHE STRING "Export
compile_commands.json.")
ELSE()
   SET(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE STRING "Export compile_commands.json.")
ENDIF()

# needs special crafted libc++
#SET(SAN "-fsanitize=memory,undefined -fsanitize-memory-track-origins -fno-optimize-sibling-calls")
#requires llvm-symbolizer sym link
IF(DEFINED SAN)
   SET(SAN ${SAN} CACHE STRING "Sanitizer to use in DEBUG mode.")
ELSE()
   SET(SAN "-fsanitize=address,undefined" CACHE STRING "Sanitizer to use in DEBUG mode.")
ENDIF()

IF(DEFINED CMAKE_C_COMPILER)
  SET(CMAKE_C_COMPILER ${CMAKE_C_COMPILER} CACHE STRING "C Compiler")
ELSE()
  SET(CMAKE_C_COMPILER "clang")
ENDIF()

IF(DEFINED CMAKE_CXX_COMPILER)
  SET(CMAKE_CXX_COMPILER ${CMAKE_CXX_COMPILER} CACHE STRING "C Compiler")
ELSE()
  SET(CMAKE_CXX_COMPILER "clang++")
ENDIF()


#----
PROJECT(theSearchers)
#----
CMAKE_MINIMUM_REQUIRED(VERSION 3.3)


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(STATUS "clang")
    set(CMAKE_COMPILER_IS_CLANGCXX TRUE)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "GNU")
    set(CMAKE_COMPILER_IS_GNUCXX TRUE)
endif ()

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --std=c11 -Wall -Wextra")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14  -Wall -Wextra")

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
if ("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g3 ${SAN}-fno-omit-frame-pointer")
message(STATUS "CMAKE_C_FLAGS_DEBUG: ${CMAKE_C_FLAGS_DEBUG}")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g3 ${SAN} -fno-omit-frame-pointer")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
endif ()

if ("${CMAKE_BUILD_TYPE}" STREQUAL "RELEASE")
if (CMAKE_COMPILER_IS_CLANGCXX)
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -Ofast")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -Ofast")
elseif (CMAKE_COMPILER_IS_GNUCXX)
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3")
endif ()
message(STATUS "CMAKE_C_FLAGS_RELEASE: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
endif ()

#for ninja
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdiagnostics-color=always")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")

find_package(
Boost
1.61.0
REQUIRED
)

INCLUDE_DIRECTORIES(
)

find_program(iwyu_path NAMES include_what-you-use iwyu)
if(NOT iwyu_path)
message(FATAL_ERROR "no iwyu")
endif()


file(GLOB_RECURSE PROJECT_SOURCES_CXX src/*.cpp)
file(GLOB_RECURSE PROJECT_SOURCES_C src/*.c)


ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES_C} ${PROJECT_SOURCES_CXX})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path})
target_link_libraries (${CMAKE_PROJECT_NAME})

#include(CTest)
#add_test(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME})
#set(CTEST_MEMORYCHECK_TYPE "AddressSanitizer")

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND size --format=berkeley ${CMAKE_PROJECT_NAME})

