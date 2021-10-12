# Copyright (C) 2021 Matteo Foglieni
#
# This file is part of Bonnor-Ebert.
# 
# Bonnor-Ebert is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# Bonnor-Ebert is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with Bonnor-Ebert.  If not, see <https://www.gnu.org/licenses/>.

# Almost all CMake files should start with this line.
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.

cmake_minimum_required(VERSION 3.12)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)

# Define a "project", providing a description and a programming language
project(Bonnor_Ebert
    VERSION 1.0
    DESCRIPTION "A numerical solver for the Bonnor Ebert equation"
    LANGUAGES CXX
)

# Libraries
add_library(lib1 src/Vettore.cpp)
add_library(lib2 src/VettoreLineare.cpp)
add_library(lib3 src/FunzioneVettoriale.cpp)

# This is needed if we keep .h files in the "include" directory
target_include_directories(lib1 PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	)
target_include_directories(lib2 PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	)
target_include_directories(lib3 PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	)

# Our "project" will be able to build an executable out of a C++ source file
add_executable(Bonnor_Ebert
    src/equazione_Bonnor-Ebert.cpp
)
target_link_libraries(Bonnor_Ebert PUBLIC lib1 lib2 lib3)

# Force the compiler to use the C++17 standard
target_compile_features(Bonnor_Ebert PUBLIC cxx_std_17)
