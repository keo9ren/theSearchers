/* clang-format off */
/*
*
*-------------------------------------------------------------------------------
*       Filename:  inputHandler.cpp
*
*    Description:  Insert Description here.
*
*        Version:  0.1
*        Created:  2016-09-11T19:48:21
*       Revision:  none
*
*         Author:  M.Sc. Oliver Kehret, oliver.kehret@hs-offenburg.de
*   Organization:  ivESK, Offenburg University, Germany
*      Copyright:  Copyright (c) 2016, M.Sc. Oliver Kehret
*-------------------------------------------------------------------------------
*
*/
/* clang-format on */
#include "inputHandler.hpp"
#include <iostream>

namespace searchers {
namespace input {
namespace inputHandler {
namespace inha = searchers::input::inputHandler;
using std::cout;
using std::endl;
namespace po = boost::program_options;

inHandler::inHandler(int ac, char *av[]) {
  desc.add_options()("help", "produce help message")(
      "version", po::value<int>(), "shows program version");
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);
}
void inHandler::handle() const {
  if (vm.count("help")) {
    cout << desc << "\n";
  }
}

}  // inputHandler
}  // input
}  // searchers
