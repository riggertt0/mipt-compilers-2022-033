#pragma once

#include "util/BasicElement.h"


class Expression: virtual public BasicElement {
 public:
  virtual int Eval() const = 0;
};
