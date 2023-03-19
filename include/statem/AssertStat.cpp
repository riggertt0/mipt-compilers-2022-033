#include "AssertStat.h"


struct AssertException {};

AssertStat::AssertStat(std::shared_ptr<Expression> expr)
  : expr{expr} {
}

void AssertStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}

void AssertStat::Perform() const {
  if (!expr->Eval()) {
    throw AssertException();
  }
}
