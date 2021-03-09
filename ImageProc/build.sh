#! /bin/bash
# Given that the number ofarguments of an arbitrary program I've wrote, this script only builds the cpp file, not run it!
# so you must run it by yourself!

if test $# -eq 0; then
    echo "Please enter the src file path and the output file name "
    read -p "src file path: " src
    read -p "output file name: " output
    g++ ${src} -o ${output} $(pkg-config --libs --cflags opencv) && mv ${output} ../bin/

else
    if test $# -eq 1; then
        g++ $1 $(pkg-config --libs --cflags opencv) && mv a.out ../bin/
    else
        g++ $1 -o $2 $(pkg-config --libs --cflags opencv) && mv $2 ../bin/
        # or g++ $1 -o $2 `pkg-config --libs --cflags opencv` && mv $2 ../bin/
    fi
fi
