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

int main(int argc, char *argv[]) {
  using std::cout;
  using std::endl;
  using std::exception;

  try {
    cout << "theSearchers" << endl;
  } catch (exception &e) {
    cout << e.what() << endl;
  }

  return 0;
}
