/* clang-format off */
/*
*
*-------------------------------------------------------------------------------
*       Filename:  eval.hpp
*
*    Description:  eval the regex
*
*        Version:  0.1
*        Created:  2016-09-18T12:19:39
*       Revision:  none
*
*         Author:  M.Sc. Oliver Kehret, oliver.kehret@hs-offenburg.de
*   Organization:  ivESK, Offenburg University, Germany
*      Copyright:  Copyright (c) 2016, M.Sc. Oliver Kehret
*-------------------------------------------------------------------------------
*
*/
/* clang-format on */
#include "eval.hpp"
#include <iostream>

namespace searchers {
namespace reg {
namespace eval {
using std::regex;
using std::smatch;
using std::cout;
using std::endl;

eval::eval(const std::string& str) : _reg_ex(str) {
}
void eval::match(const std::string& str) {
  smatch base_match;
  auto mat = regex_match(str, base_match, _reg_ex);
  cout << std::boolalpha << mat << endl; 
  cout << base_match.size() << endl;
}

}  // eval
}  // reg
}  // searchers
