cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 11)
#Naming project
project(hw2)



include_directories(include)

set(LISTSTACK_SOURCES src/StackLinked.cpp)
set(ARRAYSTACK_SOURCES src/StackArray.cpp)

add_library(List ${LISTSTACK_SOURCES})
add_library(Array ${ARRAYSTACK_SOURCES})

add_executable(hw2 src/test6.cpp)
target_link_libraries(hw2 List Array)

add_executable(delimiters src/delimiters.cpp)
target_link_libraries(delimiters List Array)

add_executable(postfix src/postfix.cpp)
target_link_libraries(postfix List Array)

install(TARGETS hw2 delimiters postfix List Array
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
