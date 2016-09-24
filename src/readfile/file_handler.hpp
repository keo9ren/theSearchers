/* clang-format off */
/*
*
*-------------------------------------------------------------------------------
*       Filename:  file_handler.hpp
*
*    Description:  handles file io
*
*        Version:  0.1
*        Created:  2016-09-18T16:49:46
*       Revision:  none
*
*         Author:  M.Sc. Oliver Kehret, oliver.kehret@hs-offenburg.de
*   Organization:  ivESK, Offenburg University, Germany
*      Copyright:  Copyright (c) 2016, M.Sc. Oliver Kehret
*-------------------------------------------------------------------------------
*
*/
/* clang-format on */
#include <memory>
#include <vector>

#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

namespace searchers {
namespace readfile {
namespace filehandler {
using std::unique_ptr;
using std::vector;

class file_handler {
 public:
  file_handler() = default;
  void read_file(const char* fname);
  virtual ~file_handler() = default;

 private:
  vector<const unique_ptr<const char>*> _mapped_files;
};

}  // filehandler
}  // readfile
}  // searchers

#endif
