#ifndef CREATECOMMAND_HPP
#define CREATECOMMAND_HPP
#include <cstddef>
#include <istream>
#include "shape.hpp"

namespace duhanina
{
  void createScale(std::istream& in, size_t shapeCount, double& scalingFactor, point_t& point);
  void createShape(std::istream& in, const std::string& shapeType, Shape** shapes, size_t& shapeCount);
  void inputShapes(std::istream& in, std::ostream& out, Shape** shapes, size_t& shapeCount);
}

#endif
