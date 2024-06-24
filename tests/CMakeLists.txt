include_directories(${CMAKE_SOURCE_DIR}/include)

# Test sources
set(TEST_SOURCES
	test_main.cpp
	test_token.cpp
	# test_lexer.cpp
)

add_executable(runTests
    ${TEST_SOURCES}
    ${CMAKE_SOURCE_DIR}/src/token.cpp
    # ${CMAKE_SOURCE_DIR}/src/lexer.cpp
)

