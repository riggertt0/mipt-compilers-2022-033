#pragma once

#include <map>

#include "util/elements.h"
#include "Visitor.h"


class Interpreter: public Visitor,
  public std::enable_shared_from_this<Interpreter> {
 public:
  Interpreter();

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

  int GetResult(std::shared_ptr<Program> program);

 private:
  void SetTosValue(int value);
  void UnsetTosValue();

 private:
  struct Variable {
    Variable() = default;
    Variable(Type type, bool is_init, int value) : type{ std::move(type) }, is_init{ is_init }, value{ value } {}
    Type type;
    bool is_init = false;
    int value;
  };

  std::map<std::string, Variable> variables;
  int tos_value_;
  bool is_tos_expression_;

};
