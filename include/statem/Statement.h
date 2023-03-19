#pragma once

#include "util/BasicElement.h"


class Statement: virtual public BasicElement {
 public:
  virtual void Perform() const = 0;
};
