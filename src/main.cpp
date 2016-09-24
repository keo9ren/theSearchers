/* clang-format off */
/*
*
*-------------------------------------------------------------------------------
*       Filename:  main.cpp
*
*    Description:  theSearchers a simple, platform-agnostic
*                  search tool written in modern cpp.
*
*        Version:  0.1
*        Created:  2016-09-06T11:25:05
*       Revision:  none
*
*         Author:  keo9ren
*   Organization:  keo9ren
*      Copyright:  Copyright (c) 2016, keo9ren
*-------------------------------------------------------------------------------
*
*/
/* clang-format on */
#include <exception>
#include <iostream>
#include <regex>
#include "inputHandler.hpp"
#include "eval.hpp"

int main(int argc, char *argv[]) {
  using std::cout;
  using std::endl;
  using std::cerr;
  using std::exception;
  using std::regex;
  namespace ih = searchers::input::inputHandler;
  namespace ev = searchers::reg::eval;

  try {
    cout << "theSearchers" << endl;
    ih::inHandler hi{argc, argv};
    hi.handle();
    ev::eval myeval{"Hallo"};
    myeval.match("Hallo");

    cout << "End of Search" << endl;
  } catch (const exception &e) {
    cout << e.what() << endl;
  }

  return 0;
}
