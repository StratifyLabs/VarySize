cmake_minimum_required (VERSION 3.6)

if( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin" )
	set(SOS_TOOLCHAIN_CMAKE_PATH /Applications/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
elseif( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows" )
	set(SOS_TOOLCHAIN_CMAKE_PATH C:/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
else()
	message(FATAL_ERROR "Cross compiling is not yet supportd on: " ${CMAKE_HOST_SYSTEM_NAME})
endif()

include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-variables.cmake)
set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-toolchain.cmake)

# This will set the default RAM used by the application
set(SOS_RAM_SIZE 8192)

#Add sources to the project
set(SOURCES_PREFIX ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)
list(APPEND SOS_SOURCELIST ${SOURCES} ${CMAKE_SOURCE_DIR}/sl_settings.json ${CMAKE_SOURCE_DIR}/README.md)

get_filename_component(SOS_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${SOS_NAME} CXX C)


set(SOS_DEFINITIONS DATA_SIZE=8192)
set(SOS_CONFIG size8k)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

set(SOS_DEFINITIONS DATA_SIZE=16384)
set(SOS_CONFIG size16k)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

set(SOS_DEFINITIONS DATA_SIZE=65536)
set(SOS_CONFIG size64k)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

set(SOS_DEFINITIONS DATA_SIZE=131072)
set(SOS_CONFIG size128k)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

set(SOS_DEFINITIONS DATA_SIZE=262144)
set(SOS_CONFIG size256k)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

set(SOS_DEFINITIONS DATA_SIZE=524288)
set(SOS_CONFIG size512k)
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-app-std.cmake)

