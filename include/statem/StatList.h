#pragma once

#include "util/BasicList.h"

class StatList: public BasicList,
  public std::enable_shared_from_this<StatList> {};
