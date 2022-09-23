cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)

project(HW03)

include_directories(include)

set(QUICKSORT_SOURCES src/QuickSort.cpp)
add_library(QuickSort ${QUICKSORT_SOURCES})

set(INSERTIONSORT_SOURCES src/InsertionSort.cpp)
add_library(InsertionSort ${INSERTIONSORT_SOURCES})

add_executable(hw3 src/hw3.cpp)
target_link_libraries(hw3 QuickSort InsertionSort)

install(TARGETS hw3 QuickSort InsertionSort
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
