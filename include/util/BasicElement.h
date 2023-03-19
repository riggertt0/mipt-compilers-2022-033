#pragma once

#include <memory>

#include "visitor/Visitor.h"


class BasicElement{
 public:
  virtual void Accept(std::shared_ptr<Visitor> visitor) = 0;

  virtual ~BasicElement() = default;
};
