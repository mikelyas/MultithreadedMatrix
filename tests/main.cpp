#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "MultithreadedMatrix.h"


TEST_CASE("Multiplication of matrices", "[multiplication]")
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

    matrixA = {{1, 2, 3, 4},
               {2, 3, 4, 5}};
    matrixB = {{1, 2, 3},
               {2, 3, 4},
               {3, 4, 5},
               {6, 7, 8}};
    matrixResult = {{38, 48, 58},
                    {50, 64, 78}};

    REQUIRE(matrixA * matrixB == matrixResult);

    matrixA = {{1, 2},
               {3, 4}};
    matrixB = {{1, 2, 3, 4},
               {2, 3, 4, 5}};
    matrixResult = {{5, 8, 11, 14},
                    {11, 18, 25, 32}};
                
    REQUIRE(matrixA * matrixB == matrixResult);

    matrixA = {{0, 0},
               {0, 0}};
    matrixB = {{0, 0, 0},
               {0, 0, 0}};
    matrixResult = {{0, 0, 0},
                    {0, 0, 0}};

    REQUIRE(matrixA * matrixB == matrixResult);
}

TEST_CASE("Addition of matrices", "[addition]") 
{
    MultithreadedMatrix matrixA({{0, 0},
                                 {0, 0}});
    MultithreadedMatrix matrixB({{0, 0},
                                 {0, 0}});
    MultithreadedMatrix matrixResult({{0, 0},
                                      {0, 0}});
    
    REQUIRE(matrixA + matrixB == matrixResult);

    matrixA = {{1, 2},
               {4, 3}};
    matrixB = {{2, 3},
               {1, 4}};
    matrixResult = {{3, 5},
                    {5, 7}};
    
    REQUIRE(matrixA + matrixB == matrixResult);

    matrixA = {{1, 2, 3},
               {4, 3, 3},
               {1, 1, 1},
               {2, 3, 3}};
    matrixB = {{2, 3, 3},
               {1, 4, 3},
               {1, 2, 3},
               {2, 3, 4}};
    matrixResult = {{3, 5, 6},
                    {5, 7, 6},
                    {2, 3, 4},
                    {4, 6, 7}};

    REQUIRE(matrixA + matrixB == matrixResult);
}

TEST_CASE("Substraction of matrices", "[substraction]") 
{
    MultithreadedMatrix matrixA({{0, 0},
                                 {0, 0}});
    MultithreadedMatrix matrixB({{0, 0},
                                 {0, 0}});
    MultithreadedMatrix matrixResult({{0, 0},
                                      {0, 0}});
    
    REQUIRE(matrixA - matrixB == matrixResult);

    matrixA = {{1, 2},
               {4, 3}};
    matrixB = {{2, 3},
               {1, 4}};
    matrixResult = {{-1, -1},
                    {3, -1}};
    
    REQUIRE(matrixA - matrixB == matrixResult);

    matrixA = {{1, 2, 3},
               {4, 3, 3},
               {1, 1, 1},
               {2, 3, 3}};
    matrixB = {{2, 3, 3},
               {1, 4, 3},
               {1, 2, 3},
               {2, 3, 4}};
    matrixResult = {{-1, -1, 0},
                    {3, -1, 0},
                    {0, -1, -2},
                    {0, 0, -1}};

    REQUIRE(matrixA - matrixB == matrixResult);
}