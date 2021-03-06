find_path(POCO_INCLUDE_DIR Poco/Poco.h
    /include
    /usr/include
    /usr/local/include
    /opt/include
    /opt/local/include
    )
    
find_path(POCO_LIBRARY_DIR libPoco*
    /lib
    /usr/lib
    /usr/local/lib
    /opt/lib
    /opt/local/lib
    )    
    
if(POCO_INCLUDE_DIR)
    message(STATUS "Poco header files are found at ${POCO_INCLUDE_DIR}")
else(POCO_INCLUDE_DIR)
    message(FATAL_ERROR "Cannot find Poco header files.")
endif(POCO_INCLUDE_DIR)

if(POCO_LIBRARY_DIR)
    message(STATUS "Poco library files are found at ${POCO_LIBRARY_DIR}")
else(POCO_LIBRARY_DIR)
    message(FATAL_ERROR "Cannot find Poco library files.")
endif(POCO_LIBRARY_DIR)

include_directories(${POCO_INCLUDE_DIR})
link_directories(${POCO_LIBRARY_DIR})
