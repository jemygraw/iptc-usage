cmake_minimum_required(VERSION 3.8)
project(iptc)

set(CMAKE_C_STANDARD 99)

set(LIBIPTC_HOME /usr/local/Cellar/libiptcdata/1.0.4)

#3rd library
include_directories(${LIBIPTC_HOME}/include)
link_directories(${LIBIPTC_HOME}/lib)
link_libraries(-liptcdata)

set(SOURCE_FILES main.c qn_iptc_help_func.c qn_get_jpeg_iptc_info.c qn_set_jpeg_iptc_info.c qn_set_jpeg_iptc_info2.c)
add_executable(iptc ${SOURCE_FILES})