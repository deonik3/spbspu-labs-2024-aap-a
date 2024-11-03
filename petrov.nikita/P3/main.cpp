#include <iostream>
#include <fstream>
#include "process_the_matrix.hpp"

int main(int argc, char ** argv)
{ 
  if (petrov::check_arguments(argc, argv) == 1)
  {
    return 1;
  }
  std::ifstream input(argv[2]);
  if (argv[1][0] == '1')
  {
    size_t number_of_rows = 0, rows = 0;
    input >> number_of_rows;
    input >> rows;
    int matrix[10000] = {0};
    int * ptr_matrix = matrix;
    petrov::input_matrix_static(input, ptr_matrix, number_of_rows, rows);
    for (size_t i = 0; i < number_of_rows; i++)
    {
      std::cout << matrix[i];
    }
  }
}