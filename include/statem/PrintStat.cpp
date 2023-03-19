#include "PrintStat.h"


PrintStat::PrintStat(std::shared_ptr<Expression> expr) : expr{expr} {
}

void PrintStat::Perform() const {
  std::cout << "Print: " << expr->Eval();
}

void PrintStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}
