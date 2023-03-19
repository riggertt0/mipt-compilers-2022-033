#pragma once

#include "Statement.h"
#include "StatList.h"


class StatListStat : public Statement,
  public std::enable_shared_from_this<StatListStat> {
 public:
	 StatListStat(std::shared_ptr<StatList> stmt_list);
  void Accept(std::shared_ptr<Visitor> visitor) override;
  void Perform() const override;

  std::shared_ptr<StatList> stmt_list;
};
