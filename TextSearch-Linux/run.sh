#!/bin/bash
cd ./cppClient
printf "Demonstrate parallel text search component\n"
printf "Command format is: [root][text][num of threads][pattern1][pattern2]...\n"
printf "\n Test case 1, root is \"..\", searching string is \"main\", number of threads are 4, patterns are \"*.cpp\",\"*.h\"\n"
printf "command line: \"..\" \"main\" 4 \"*.cpp\" \"*.h\"\n"
./dist/Debug/GNU-Linux/cppclient ".." "main" "4" "*.cpp" "*.h"

printf "\n Test case 2, root is \"..\", searching string is \"#include\",number of threads are 3,patterns are \"*.cpp\",\"*.h\"\n"
printf "command line: \"..\" \"#include\" 3 \"*.cpp\" \"*.h\"\n"
./dist/Debug/GNU-Linux/cppclient ".." "#include" "3" "*.cpp" "*.h"

