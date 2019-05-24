cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Modules/")

project(mt32emu-lv2)
set(mt32emu_lv2_VERSION_MAJOR 1)
set(mt32emu_lv2_VERSION_MINOR 2)
set(mt32emu_lv2_VERSION_PATCH 0)

add_definitions(-DPACKAGE_VERSION="${munt_VERSION_MAJOR}.${munt_VERSION_MINOR}.${munt_VERSION_PATCH}")
add_definitions(-DAPP_VERSION="${mt32emu_lv2_VERSION_MAJOR}.${mt32emu_lv2_VERSION_MINOR}.${mt32emu_lv2_VERSION_PATCH}")

include(CheckIncludeFiles)
include(CheckLibraryExists)

set(mt32emu_lv2_SOURCES
  src/mt32emu_lv2.cpp
)

set(mt32emu_lv2_HEADERS
)

find_package(MT32EMU REQUIRED)
set(EXT_LIBS ${EXT_LIBS} ${MT32EMU_LIBRARIES})
include_directories(${MT32EMU_INCLUDE_DIRS})

include_directories(${LV2_INCLUDE_DIRS})
set(EXT_LIBS ${EXT_LIBS} ${LV2_LIBRARIES})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER MATCHES "(^|/)clang\\+\\+$")
  add_definitions(-Wall -Wextra -Wnon-virtual-dtor -ansi -fPIC -fvisibility=hidden -std=c++11)
  set ( CMAKE_SHARED_LINKER_FLAGS "-Wl,--fatal-warnings -Wl,--no-undefined -lc ${CMAKE_SHARED_LINKER_FLAGS}")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(mt32emu-lv2 SHARED
  ${mt32emu_lv2_HEADERS}
  ${mt32emu_lv2_SOURCES}
)
set_target_properties(mt32emu-lv2 PROPERTIES PREFIX "")

target_link_libraries(mt32emu-lv2
  ${EXT_LIBS}
)

# installation
install(TARGETS mt32emu-lv2
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_PREFIX}/${LV2_INSTALL_DIR}/mt32emu.lv2
)
install (FILES mt32emu.lv2/manifest.ttl mt32emu.lv2/mt32emu.ttl
    DESTINATION ${CMAKE_INSTALL_PREFIX}/${LV2_INSTALL_DIR}/mt32emu.lv2
)

