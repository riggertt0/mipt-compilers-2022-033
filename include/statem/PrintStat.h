#pragma once

#include <iostream>

#include "expr/Expression.h"
#include "Statement.h"


class PrintStat : public Statement,
  public std::enable_shared_from_this<PrintStat> {
 public:
  PrintStat(std::shared_ptr<Expression> expr);

  void Perform() const override;
  void Accept(std::shared_ptr<Visitor> visitor) override;

  std::shared_ptr<Expression> expr;

};
