#include "StatListStat.h"


StatListStat::StatListStat(std::shared_ptr<StatList> stmt_list)
  : stmt_list{stmt_list} {
}

void StatListStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}

void StatListStat::Perform() const {
  for (auto item : stmt_list->items) {
    std::dynamic_pointer_cast<Statement>(item)->Perform();
  }
}
