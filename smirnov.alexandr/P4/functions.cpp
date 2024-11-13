#include "functions.hpp"
#include <cstddef>
#include <cstring>

char * smirnov::getLine(std::istream & in, char stop)
{
  constexpr size_t max = 10;
  char * str = nullptr;
  try
  {
    str = new char [max + 1];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] str;
    throw std::logic_error("Out of memory\n");
  }
  size_t size = 0;
  char c = '\0';
  size_t capacity = max;
  in >> std::noskipws;
  while (in >> c && c != stop)
  {
    if (size == capacity)
    {
      capacity *= 2;
      char * new_str = nullptr;
      try
      {
        new_str = new char[capacity + 1];
      }
      catch (const std::bad_alloc & e)
      {
        delete[] new_str;
        delete[] str;
        throw std::logic_error("Out of memory\n");
      }
      for (size_t i = 0; i < capacity; ++i)
      {
        new_str[i] = str[i];
      }
      delete[] str;
      str = new_str;
    }
    str[size++] = c;
  }
  str[size] = '\0';
  in >> std::skipws;
  return str;
}

char * smirnov::uniString(const char * str1, const char * str2)
{
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);
  size_t resultLen = len1 + len2;
  char * result = new char[resultLen + 1];
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  while (i < len1 && j < len2)
  {
    result[k++] = str1[i++];
    result[k++] = str2[j++];
  }
  while (i < len1)
  {
    result[k++] = str1[i++];
  }
  while (j < len2)
  {
    result[k++] = str2[j++];
  }
  result[k] = '0';
  return result;
}
