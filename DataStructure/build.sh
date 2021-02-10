#! /bin/bash
if test $# -eq 0; then
    echo "Please enter the src file path and the output file name "
    read -p "src file path: "  src
    read -p "output file name: "  output
    g++ ${src} -o ${output} $(pkg-config --libs --cflags opencv) && ./${output}
else
    g++ $1 -o $2 $(pkg-config --libs --cflags opencv) && ./$2
fi
