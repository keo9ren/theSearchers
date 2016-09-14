/* clang-format off */
/*
*
*-------------------------------------------------------------------------------
*       Filename:  inputHandler.hpp
*
*    Description:  Insert Description here.
*
*        Version:  0.1
*        Created:  2016-09-11T19:46:05
*       Revision:  none
*
*         Author:  M.Sc. Oliver Kehret, oliver.kehret@hs-offenburg.de
*   Organization:  ivESK, Offenburg University, Germany
*      Copyright:  Copyright (c) 2016, M.Sc. Oliver Kehret
*-------------------------------------------------------------------------------
*
*/
/* clang-format on */
#include <boost/program_options.hpp>

#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

namespace searchers {
namespace input {
namespace inputHandler {
namespace po = boost::program_options;

class inHandler {
 public:
  inHandler(int ac, char *av[]);
  void handle() const;

  ~inHandler() = default;

 private:
  po::variables_map vm;
  po::options_description desc{"Options"};
};
}  // inputHandler
}  // input
}  // searchers

#endif
