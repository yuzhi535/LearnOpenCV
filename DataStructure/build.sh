#! /bin/bash
if test $# -eq 0; then
    echo "Please enter the src file path and the output file name "
    read -p "src file path: "  src
    read -p "output file name: "  output
    g++ ${src} -o ${output} $(pkg-config --libs --cflags opencv) && mv ${output} ../bin/ && ../bin/${output}
    
else
    if test $# -eq 1; then 
        g++ $1 $(pkg-config --libs --cflags opencv) && mv a.out ../bin/ && ../bin/a.out
    else
        g++ $1 -o $2 $(pkg-config --libs --cflags opencv) && mv $2 ../bin/ && ../bin/$2
    fi
fi
