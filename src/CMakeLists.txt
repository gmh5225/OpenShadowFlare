cmake_minimum_required(VERSION 3.25)
project(OpenShadowFlare C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_link_options(-static -static-libgcc -static-libstdc++ -Wno-pointer-arith -s -Os)

add_library(RK_FUNCTION SHARED RK_FUNCTION/src/core.cpp "RK_FUNCTION/dll.def")
add_library(RKC_DBFCONTROL SHARED RKC_DBFCONTROL/src/core.cpp "RKC_DBFCONTROL/dll.def")
add_library(RKC_DIB SHARED RKC_DIB/src/core.cpp "RKC_DIB/dll.def")
add_library(RKC_DSOUND SHARED RKC_DSOUND/src/core.cpp "RKC_DSOUND/dll.def")
add_library(RKC_FILE SHARED RKC_FILE/src/core.cpp "RKC_FILE/dll.def")
add_library(RKC_FONTMAKER SHARED RKC_FONTMAKER/src/core.cpp "RKC_FONTMAKER/dll.def")
add_library(RKC_MEMORY SHARED RKC_MEMORY/src/core.cpp "RKC_MEMORY/dll.def")
add_library(RKC_NETWORK SHARED RKC_NETWORK/src/core.cpp "RKC_NETWORK/dll.def")
add_library(RKC_RPG_AICONTROL SHARED RKC_RPG_AICONTROL/src/core.cpp "RKC_RPG_AICONTROL/dll.def")
add_library(RKC_RPG_SCRIPT SHARED RKC_RPG_SCRIPT/src/core.cpp "RKC_RPG_SCRIPT/dll.def")
add_library(RKC_RPG_TABLE SHARED RKC_RPG_TABLE/src/core.cpp "RKC_RPG_TABLE/dll.def")
add_library(RKC_RPGSCRN SHARED RKC_RPGSCRN/src/core.cpp "RKC_RPGSCRN/dll.def")
add_library(RKC_UPDIB SHARED RKC_UPDIB/src/core.cpp "RKC_UPDIB/dll.def")
add_library(RKC_WINDOW SHARED RKC_WINDOW/src/core.cpp "RKC_WINDOW/dll.def")