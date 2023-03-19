#pragma once

#include "util/BasicList.h"

class ClassDeclList: public BasicList,
  public std::enable_shared_from_this<ClassDeclList> {};
