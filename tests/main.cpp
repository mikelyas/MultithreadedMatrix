#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "MultithreadedMatrix.h"


TEST_CASE("Multiplication of matrixes", "[multiplication]")
{
    MultithreadedMatrix matrixA({{1, 1},
                                 {1, 1}});
    MultithreadedMatrix matrixB({{1, 1},
                                 {1, 1}});
    MultithreadedMatrix matrixResult({{2, 2},
                                      {2, 2}});

    REQUIRE(matrixA * matrixB == matrixResult);

    matrixA = {{0, 1, 2, 3},
               {1, 2, 3, 4},
               {2, 3, 4, 5},
               {3, 4, 5, 6}};
    matrixB = {{1, 2, 3, 4},
               {2, 3, 4, 5},
               {1, 2, 3, 4},
               {3, 4, 5, 6}};
    matrixResult = {{13, 19, 25, 31},
                    {20, 30, 40, 50},
                    {27, 41, 55, 69},
                    {34, 52, 70, 88}};

    REQUIRE(matrixA * matrixB == matrixResult);

    matrixA =  {{1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6}};
    matrixB =  {{1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6},
                {1, 2, 3, 4, 5, 6}};
    matrixResult = {{21, 42, 63, 84, 105, 126},
                    {21, 42, 63, 84, 105, 126},
                    {21, 42, 63, 84, 105, 126},
                    {21, 42, 63, 84, 105, 126},
                    {21, 42, 63, 84, 105, 126},
                    {21, 42, 63, 84, 105, 126}};                         

    REQUIRE(matrixA * matrixB == matrixResult);
}