#! /bin/bash
if test $# -eq 1; then
    echo -o "Please enter the src file path and the output file name"
    read -p "src: " src
    read -p  "output: " output
    g++ ${src} -o ${output} $(pkg-config --libs --cflags opencv) && ./${output}
else
    g++ $1 -o $2 $(pkg-config --libs --cflags opencv) && ./$2
fi
