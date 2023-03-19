#pragma once

#include "Statement.h"
#include "expr/Expression.h"


class AssertStat : public Statement,
  public std::enable_shared_from_this<AssertStat> {
 public:
  AssertStat(std::shared_ptr<Expression> expr);
  void Accept(std::shared_ptr<Visitor> visitor) override;
  void Perform() const override;

  std::shared_ptr<Expression> expr;
};
