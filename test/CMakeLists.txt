include(CTest)
#add_test(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME})
#set(CTEST_MEMORYCHECK_TYPE "AddressSanitizer")
INCLUDE_DIRECTORIES(
GSL/gsl/
../src/input/
regex/
readfile
)

message(STATUS "Building Tests")
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
message(STATUS "CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_SOURCE_DIR:${CMAKE_SOURCE_DIR}")
message(STATUS "TEST_SRCS:${TEST_SRCS}")
foreach(testSrc ${TEST_SRCS})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)

        #Add compile target
        add_executable(${testName} ${testSrc})

        #link to Boost libraries AND your targets and dependencies linkmylibrary${}
        target_link_libraries(${testName} ${Boost_LIBRARIES} ${lib_search})

        #I like to move testing binaries into a testBin directory
        set_target_properties(${testName} PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/testBin)

        #Finally add it to test execution - 
        #Notice the WORKING_DIRECTORY and COMMAND
        message(STATUS "CMAKE_SOURCE_DIR/testBin:${CMAKE_SOURCE_DIR}/testBin")
        message(STATUS "CMAKE_SOURCE_DIR/testBin/testName:${CMAKE_SOURCE_DIR}/testBin/${testName}")
        message(STATUS "testName:${testName}")
        add_test(NAME ${testName} 
                 WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/testBin 
                 COMMAND ${CMAKE_SOURCE_DIR}/testBin/${testName})
endforeach(testSrc)
