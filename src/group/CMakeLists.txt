cmake_minimum_required(VERSION 2.6)

#
# group operators
#
    
# xgroup
add_executable(xgrp.group
    ${COMMON_SRCS}
    Group.h
    Group.cpp
    GroupApp.h
    GroupApp.cpp
    )
target_link_libraries(xgrp.group
    ${COMMON_LIBS}
    )
    
# xungroup
add_executable(xgrp.ungroup
    ${COMMON_SRCS}
    Ungroup.h
    Ungroup.cpp
    UngroupApp.h
    UngroupApp.cpp
    )
target_link_libraries(xgrp.ungroup
    ${COMMON_LIBS}
    )
    