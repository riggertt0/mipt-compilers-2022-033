#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "scanner.h"
#include "parser.hh"
#include "main/Main.h"
#include "visitor/PrintVisitor.h"
#include "visitor/Interpreter.h"


class Driver {
 public:
  Driver();

  int parse(const std::string& f);
  void scan_begin();
  void scan_end();

  void PrintTree(const std::string& filename) const;
  int Eval() const;

 public:
  friend class Scanner;

  Scanner scanner;
  yy::parser parser;

  std::shared_ptr<Program> program;

  int result;
  bool trace_parsing;
  bool trace_scanning;
  yy::location location;
  std::string file;

 private:
  std::ifstream stream;

};
