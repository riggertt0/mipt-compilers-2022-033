#pragma once

#include "util/BasicList.h"

class DeclList: public BasicList,
  public std::enable_shared_from_this<DeclList> {};
