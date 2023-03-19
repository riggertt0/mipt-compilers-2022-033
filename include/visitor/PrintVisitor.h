#pragma once

#include <fstream>

#include "util/elements.h"
#include "Visitor.h"


class PrintVisitor: public Visitor,
  public std::enable_shared_from_this<PrintVisitor> {
 public:
  PrintVisitor(const std::string& filename);

  void Visit(std::shared_ptr<Program> program) override;
  void Visit(std::shared_ptr<MainClass> main_class) override;
  void Visit(std::shared_ptr<AssertStat> assert_stmt) override;
  void Visit(std::shared_ptr<LocalVarDeclStat> local_var_decl_stmt) override;
  void Visit(std::shared_ptr<StatListStat> stmt_list_stmt) override;
  void Visit(std::shared_ptr<IfStat> if_stmt) override;
  void Visit(std::shared_ptr<IfElseStat> if_else_stmt) override;
  void Visit(std::shared_ptr<WhileStat> while_stmt) override;
  void Visit(std::shared_ptr<PrintStat> print_stmt) override;
  void Visit(std::shared_ptr<AssignmentStat> assignment_stmt) override;
  void Visit(std::shared_ptr<BinOpExpr> bin_op_expr) override;
  void Visit(std::shared_ptr<TrueExpr> true_expr) override;
  void Visit(std::shared_ptr<FalseExpr> false_expr) override;
  void Visit(std::shared_ptr<IntExpr> int_expr) override;
  void Visit(std::shared_ptr<NewExpr> new_expr) override;
  void Visit(std::shared_ptr<NotExpr> not_expr) override;
  void Visit(std::shared_ptr<IdentExpr> ident_expr) override;
  void Visit(std::shared_ptr<VarDecl> var_decl) override;
  void Visit(std::shared_ptr<Lvalue> lvalue) override;

 ~PrintVisitor();

 private:
  void PrintTabs();
  
 private:
  size_t num_tabs_ = 0;
  std::ofstream stream_;
};
