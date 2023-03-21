#pragma once

#include <string>

class BasicList;

class Program;
class MainClass;
class ClassDeclList;

class Statement;
class AssertStat;
class LocalVarDeclStat;
class StatListStat;
class IfStat;
class IfElseStat;
class WhileStat;
class PrintStat;
class AssignmentStat;
class StatList;

class Expression;
class BinOpExpr;
class TrueExpr;
class FalseExpr;
class IntExpr;
class NewExpr;
class NotExpr;
class IdentExpr;

class Decl;
class VarDecl;
class ClassDecl;
class DeclList;

class Lvalue;

struct Type {
  std::string type;
  bool is_array;
} ;
