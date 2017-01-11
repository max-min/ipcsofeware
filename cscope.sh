#!/bin/sh
find . -name "*.h" -o -name "*.cpp" -o -name "*.c"> cscope.files
cscope -bkq -i cscope.files
#ctags -R
ctags -R --c++-kinds=+p --fields=+iaS --extra=+q
