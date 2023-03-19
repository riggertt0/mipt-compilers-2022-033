#include "ConditionalStat.h"

IfStat::IfStat(std::shared_ptr<Expression> expr,
    std::shared_ptr<Statement> stmt) : expr{expr}, stmt{stmt} {
}

void IfStat::Perform() const {
  if (expr->Eval()) { stmt->Perform(); }
}

void IfStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}


IfElseStat::IfElseStat(std::shared_ptr<Expression> expr,
    std::shared_ptr<Statement> stmt_true, 
    std::shared_ptr<Statement> stmt_false)
  : expr{expr}, stmt_true{stmt_true}, stmt_false{stmt_false} {
}

void IfElseStat::Perform() const {
  if (expr->Eval()) { stmt_true->Perform(); } else { stmt_false->Perform(); }
}

void IfElseStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}


WhileStat::WhileStat(std::shared_ptr<Expression> expr,
    std::shared_ptr<Statement> stmt) : expr{expr}, stmt{stmt} {
}

void WhileStat::Perform() const {
  while (expr->Eval()) { stmt->Perform(); }
}

void WhileStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}
