cmake_minimum_required(VERSION 3.10)
project(Project)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(
    HEADERS
    ${Project_SOURCE_DIR}/driver.hh
    ${Project_SOURCE_DIR}/parser.hh
    )

BISON_TARGET(
    MyParser
    parser.y
    ${Project_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${Project_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    MyScanner
    scanner.l
    ${Project_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(
    SOURCES
    driver.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
    include/main/Main.cpp
    include/main/MainClass.cpp

    include/statem/PrintStat.cpp
    include/statem/AssertStat.cpp
    include/statem/LocalVarDeclStat.cpp
    include/statem/StatListStat.cpp
    include/statem/ConditionalStat.cpp
    include/statem/PrintStat.cpp
    include/statem/AssignmentStat.cpp
    include/statem/LocalVarDeclStat.cpp

    include/expr/BinOpExpr.cpp
    include/expr/BoolConstExpr.cpp
    include/expr/IntExpr.cpp
    include/expr/NewExpr.cpp
    include/expr/NotExpr.cpp
    include/expr/IdentExpr.cpp

    include/util/BasicList.cpp

    include/decl/VarDecl.cpp
    include/decl/CDecl.cpp

    include/util/Lvalue.cpp

    include/visitor/PrintVisitor.cpp
    include/visitor/Interpreter.cpp
)

add_executable(
    Project
    ${Project_SOURCE_DIR}/main.cpp
    ${SOURCES}
)

target_include_directories(Project PRIVATE ${Project_SOURCE_DIR})
target_include_directories(Project PRIVATE 
  ${Project_SOURCE_DIR}/include
)
