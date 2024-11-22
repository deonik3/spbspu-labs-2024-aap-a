#include "inputString.h"
#include <iostream>
char* kiselev::resizeArr(char* array, size_t newLength, size_t pastLength)
{
  char* arr2 = static_cast< char* >(malloc(newLength * sizeof(char)));
  if (arr2 == nullptr)
  {
    return arr2;
  }
  for (size_t i = 0; i < pastLength; ++i)
  {
    arr2[i] = array[i];
  }
  return arr2;
}
char* kiselev::inputString()
{
  size_t memorySize = 3;
  char* arr = static_cast< char* >(malloc(memorySize * sizeof(char)));
  if (arr == nullptr)
  {
    return arr;
  }
  size_t length = 0;
  std::noskipws(std::cin);
  if (!(std::cin >> arr[length]))
  {
    std::cerr << "Incorrect input\n";
    free(arr);
    return nullptr;
  }
  while (arr[length] != '\n')
  {
    length++;
    if (length == memorySize)
    {
      size_t timeLength = memorySize;
      memorySize += 5;
      char* timeArray = arr;
      arr = kiselev::resizeArr(arr, memorySize, timeLength);
      free(timeArray);
      if (arr == nullptr)
      {
        std::cerr << "Out of memory\n";
        return arr;
      }
    }
    if (!(std::cin >> arr[length]))
    {
      break;
    }
  }
  arr[length] = '\0';
  std::skipws(std::cin);
  return arr;
}