cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 14)
#Naming project
project(hw4)

include_directories(include)

set(BINARYNODE_SOURCES src/BinaryNode.cpp)
set(BINARYNODETREE_SOURCES src/BinaryNodeTree.cpp)
set(BINARYSEARCHTREE_SOURCES src/BinarySearchTree.cpp)
set(NOTFOUNDEXCEPTION_SOURCES src/NotFoundException.cpp)
set(PRECONDVIOLATEDEXCEPT_SOURCES src/PrecondViolatedExcept.cpp)

add_library(BinaryNode ${BINARYNODE_SOURCES})
add_library(BinaryNodeTree ${BINARYNODETREE_SOURCES})
add_library(BinarySearchTree ${BINARYSEARCHTREE_SOURCES})
add_library(NotFoundException ${NOTFOUNDEXCEPTION_SOURCES})
add_library(PrecondViolatedExcept ${PRECONDVIOLATEDEXCEPT_SOURCES})

add_executable(testTree src/test.cpp)
target_link_libraries(testTree BinaryNode BinaryNodeTree BinarySearchTree NotFoundException PrecondViolatedExcept)

install(TARGETS testTree BinaryNode BinaryNodeTree BinarySearchTree NotFoundException PrecondViolatedExcept
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

