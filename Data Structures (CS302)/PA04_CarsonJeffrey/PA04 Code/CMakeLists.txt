cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 14)
#Naming project
project(hw5)

include_directories(include)

set(LLBT_SOURCES src/LeftLeaningRedBlack.cpp)
add_library(LLBT ${LLBT_SOURCES})

add_executable(proj4 src/main.cpp)
target_link_libraries(proj4 LLBT)

install(TARGETS proj4 LLBT
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
