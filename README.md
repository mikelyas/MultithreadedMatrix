# MultithreadedMatrix

This project implements matrix operations using multithreading. Currently, these operations are implemented:
- Multiplication
- Addition
- Substruction

## Matrix Multiplication Implementation

The matrix multiplication is implemented in the following way:

- Each thread takes a specific number of rows from the first matrix.
- It multiplies these rows with all the columns from the second matrix.

## Matrix Addition and Substraction Implementations

Each thread is responsible for a number of rows to add or substract.

## Getting Started

To test the project, follow these steps:

1. Create a build directory in the project root.

```shell
mkdir build
```

2. Navigate to the build directory.

```shell
cd build
```

3. Generate the build files using CMake.

```shell
cmake ..
```

4. Build the project.

```shell
cmake --build .
```

This process generates both the application executable with one use case and an executable for running unit tests.

## Running the Application

After building the project, you can run the application executable from the build directory. The application demonstrates matrix multiplication using multithreading.

## Running Unit Tests

You can run the unit tests executable from the build directory. These tests validate the correctness of the matrix multiplication implementation.