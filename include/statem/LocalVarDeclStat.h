#pragma once

#include "Statement.h"
#include "decl/VarDecl.h"


class LocalVarDeclStat : public Statement,
  public std::enable_shared_from_this<LocalVarDeclStat> {
 public:
  LocalVarDeclStat(std::shared_ptr<VarDecl> expr);
  void Accept(std::shared_ptr<Visitor> visitor) override;
  void Perform() const override;

  std::shared_ptr<VarDecl> var_decl;
};
