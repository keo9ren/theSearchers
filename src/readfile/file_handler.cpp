/* clang-format off */
/*
*
*-------------------------------------------------------------------------------
*       Filename:  file_handler.cpp
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
#include "file_handler.hpp"
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

namespace searchers {
namespace readfile {
namespace filehandler {
namespace bip = boost::interprocess;

void file_handler::read_file(const char* fname) {
  constexpr auto mode = bip::read_only;
  bip::file_mapping fm(fname, mode);
  bip::mapped_region region(fm, mode, 0, 0);
  const auto fp = static_cast<unique_ptr<const char>*>((region.get_address()));
  _mapped_files.emplace_back(fp);
}

}  // filehandler
}  // readfile
}  // searchers
