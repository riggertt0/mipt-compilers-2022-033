#include "AssignmentStat.h"


AssignmentStat::AssignmentStat(std::shared_ptr<Lvalue> lvalue,
    std::shared_ptr<Expression> expr)
  : lvalue{lvalue}, expr{expr} {
}

void AssignmentStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}

void AssignmentStat::Perform() const {
}
