#ifndef UPPTRI_HPP
#define UPPTRI_HPP
#include <istream>
#include <cstddef>
namespace gavrilova
{
  int checkNumOfArguments(int argc);
  int checkFirstArgument(unsigned long int num, const char * end);
  std::istream & input_matrix(std::istream & in, int * mtx, size_t m, size_t n, size_t & read);
  bool isUpperTriangMtx(const int * mtx, size_t m, size_t n);
}
#endif
