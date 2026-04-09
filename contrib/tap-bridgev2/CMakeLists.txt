check_include_file_cxx(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
    add_definitions(-DHAVE_STDINT_H)
endif()

set(examples_as_tests_sources)
if(${ENABLE_EXAMPLES})
    set(examples_as_tests_sources
        #test/tap-bridgev2-examples-test-suite.cc
        )
endif()

build_lib(
    LIBNAME tap-bridgev2
    SOURCE_FILES model/tap-bridgev2.cc             
                 model/time-controller.cc
                 model/tap-transmitter.cc
                 model/bucket-scheduler.cc
                 model/balancing-simulator-impl.cc
                 model/balancing-simulator-impl-process.cc
                 model/tap-rw.cc
                 model/super-scheduler.cc
                 model/SEconfig.cc
                 model/util.cc
                 model/time-ruler.cc
                 model/time-waiter.cc
                
    HEADER_FILES model/tap-bridgev2.h
                 model/time-controller.h
                 model/tap-transmitter.h
                 model/bucket-scheduler.h
                 model/balancing-simulator-impl.h
                 model/tap-rw.h
                 model/super-scheduler.h
                 model/SEconfig.h
                 model/util.h
                 model/time-ruler.h
                 model/time-waiter.h

    LIBRARIES_TO_LINK ${libcore} 
                        ${libnetwork} 
                        ${libinternet} 
    TEST_SOURCES test/tap-bridgev2-test-suite.cc
                 ${examples_as_tests_sources}
)
