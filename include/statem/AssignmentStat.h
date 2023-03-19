#pragma once

#include "Statement.h"
#include "util/Lvalue.h"


class AssignmentStat : public Statement,
  public std::enable_shared_from_this<AssignmentStat> {
 public:
  AssignmentStat(std::shared_ptr<Lvalue> lvalue,
      std::shared_ptr<Expression> expr);
  void Accept(std::shared_ptr<Visitor> visitor) override;
  void Perform() const override;

  std::shared_ptr<Lvalue> lvalue;
  std::shared_ptr<Expression> expr;
};
