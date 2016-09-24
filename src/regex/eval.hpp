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
#include <string>
#include <regex>

#ifndef EVAL_HPP
#define EVAL_HPP
namespace searchers {
namespace reg {
namespace eval {

class eval {
public:
  eval(const std::string& str);
  void match(const std::string& str);
  ~eval() = default;
private:
std::regex _reg_ex;
};

}  // eval
}  // reg
}  // searchers
#endif
