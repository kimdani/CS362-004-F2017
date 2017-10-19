testme: testme.c
    gcc -o testme testme.c -Wall -std=c99 -ftest-coverage -fprofile-arcs
    ./testme
