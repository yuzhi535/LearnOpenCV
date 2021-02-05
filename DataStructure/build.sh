echo "Please enter the source file path and the output"
read src output
g++ ${src} -o ${output} `pkg-config --libs --cflags opencv` && ./${output}