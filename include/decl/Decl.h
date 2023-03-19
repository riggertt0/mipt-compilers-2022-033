#pragma once

#include <string>
#include "util/BasicElement.h"
#include "VarScope.h"


class Decl: virtual public BasicElement {
 public:
  Type type;
  std::string name;
};
