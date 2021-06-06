#pragma once
#ifndef IRGEN_HPP
#define IRGEN_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ast.hpp"
#include "global.hpp"
#include "parser_hyb.tab.hpp"
using namespace std;

void treatMain(BaseAST* );
void traverseAST(BaseAST* );

#endif