#pragma once

#include <memory>

#include "visitor/Visitor.h"


class MainClass: public std::enable_shared_from_this<MainClass> {
 public:
  MainClass(std::shared_ptr<StatList> stmt_list);

  void Accept(std::shared_ptr<Visitor> visitor);

  std::shared_ptr<StatList> stmt_list;
};
