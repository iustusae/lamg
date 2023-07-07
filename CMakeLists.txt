cmake_minimum_required(VERSION 3.10)
project(DSA)

# Add the executable target for the test file
add_executable(DSA
        tests/vec_t.cpp
        impls/data_structs/s_vector.cpp
        )

# Include directories
target_include_directories(DSA PRIVATE
        impls/data_structs
        )

# Set C++ standard to C++20
target_compile_features(DSA PRIVATE cxx_std_20)
