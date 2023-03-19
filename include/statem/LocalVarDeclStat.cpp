#include "LocalVarDeclStat.h"


LocalVarDeclStat::LocalVarDeclStat(std::shared_ptr<VarDecl> var_decl)
  : var_decl{var_decl} {
}

void LocalVarDeclStat::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}

void LocalVarDeclStat::Perform() const {
}
