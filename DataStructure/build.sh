#! /bin/bash
if test $# -eq 0; then
    echo "Please enter the src file path and the output file name "
    read -p "src file path: " src
    read -p "output file name: " output
    g++ ${src} -o ${output}.run $(pkg-config --libs --cflags opencv) && mv ${output}.run ../bin/ && ../bin/${output}.run

else
    if test $# -eq 1; then
        g++ $1 $(pkg-config --libs --cflags opencv) && mv a.out ../bin/ && ../bin/a.out
    else
        g++ $1 -o $2.run $(pkg-config --libs --cflags opencv) && mv $2.run ../bin/ && ../bin/$2.run
    fi
fi
