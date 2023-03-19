#pragma once

#include "Statement.h"
#include "expr/Expression.h"


class IfStat : public Statement,
  public std::enable_shared_from_this<IfStat> {
 public:
  IfStat(std::shared_ptr<Expression> expr, std::shared_ptr<Statement> stmt);

  void Perform() const override;
  void Accept(std::shared_ptr<Visitor> visitor) override;

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> stmt;
};


class IfElseStat : public Statement,
  public std::enable_shared_from_this<IfElseStat> {
 public:
  IfElseStat(std::shared_ptr<Expression> expr,
      std::shared_ptr<Statement> stmt_true, 
      std::shared_ptr<Statement> stmt_false);

  void Perform() const override;
  void Accept(std::shared_ptr<Visitor> visitor) override;

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> stmt_true;
  std::shared_ptr<Statement> stmt_false;
};


class WhileStat : public Statement,
  public std::enable_shared_from_this<WhileStat> {
 public:
  WhileStat(std::shared_ptr<Expression> expr, std::shared_ptr<Statement> stmt);

  void Perform() const override;
  void Accept(std::shared_ptr<Visitor> visitor) override;

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> stmt;
};


