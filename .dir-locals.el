;;; package --- Summary:
;;; Commentary:
;;; Directory Local Variables
;;; For more information see (info "(Emacs) Directory Variables")

;;; Code:
((nil . ((cmake-ide-build-dir . "build")
         (cmake-ide-flags-c . (
         ; compiler -v -xc /dev/null -fsyntax-only
         ;arch g++                        
         ;"-I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/include"
         ;"-I/usr/local/include"
         ;"-I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/include-fixed"
         ;"-I/usr/include"
         "-I/usr/local/include"
         "-I/usr/bin/../lib/clang/3.8.1/include"
         "-I/usr/include"
         ))
         (cmake-ide-flags-c++ . (
         ; compiler -v -xc++ /dev/null -fsyntax-only
         ;arch g++                        
         ;"-I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/../../../../include/c++/6.1.1"
         ;"-I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/../../../../include/c++/6.1.1/x86_64-pc-linux-gnu"
         ;"-I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/../../../../include/c++/6.1.1/backward"
         ;"-I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/include"
         ;"-I/usr/local/include"
         ;"-I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/include-fixed"
         ;"-I/usr/include"
         ;arch clang
         "-I/usr/bin/../lib64/gcc/x86_64-pc-linux-gnu/6.1.1/../../../../include/c++/6.1.1"
         "-I/usr/bin/../lib64/gcc/x86_64-pc-linux-gnu/6.1.1/../../../../include/c++/6.1.1/x86_64-pc-linux-gnu"
         "-I/usr/bin/../lib64/gcc/x86_64-pc-linux-gnu/6.1.1/../../../../include/c++/6.1.1/backward"
         "-I/usr/local/include"
         "-I/usr/bin/../lib/clang/3.8.1/include"
         "-I/usr/include"
         ))
         )))
;;(provide '.dirs-locals)
;;; .dirs-locals.el ends here
