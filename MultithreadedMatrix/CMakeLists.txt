set(LIBRARY_SOURCES
    "MultithreadedMatrix.cpp")
set(LIBRARY_HEADERS
    "MultithreadedMatrix.h")

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC "./")