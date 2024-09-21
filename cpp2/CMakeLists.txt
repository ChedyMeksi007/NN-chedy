cmake_minimum_required(VERSION 3.7)
project(cpp2)

enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -pthread -std=c++14")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(
	testy
	test/main_test.cpp
	test/neuron_test.cpp
	test/layer_test.cpp
	test/matrix_test.cpp
	src/neuron.cpp
	src/layer.cpp
	src/matrix.cpp
)

add_executable(
	train
	src/train.cpp
	src/neuron.cpp
	src/matrix.cpp
	src/numberimage.cpp
	src/dataset.cpp
	src/nn/nn.cpp
	src/nn/backprop.cpp
	src/nn/feedforward.cpp
	src/nn/seterrors.cpp
	src/nn/train.cpp
	src/layer.cpp
	src/utils/math.cpp
	src/utils/misc.cpp
)

add_executable(
	classify
	src/classify.cpp
	src/neuron.cpp
	src/matrix.cpp
	src/numberimage.cpp
	src/dataset.cpp
	src/nn/nn.cpp
	src/nn/backprop.cpp
	src/nn/feedforward.cpp
	src/nn/seterrors.cpp
	src/nn/train.cpp
	src/layer.cpp
	src/utils/math.cpp
	src/utils/misc.cpp
)

target_link_libraries( testy ${GTEST_LIBRARIES} pthread)

add_test( NAME testy COMMAND testy)
