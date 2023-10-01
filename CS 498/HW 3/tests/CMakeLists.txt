add_executable(my_tests test_main.cpp my_test_file.cpp)  # Add your test files here

# Link against Catch2
target_link_libraries(my_tests PRIVATE Catch2::Catch2)
