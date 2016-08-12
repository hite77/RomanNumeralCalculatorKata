# RomanNumeralCalculatorKata
Allows adding, and subtracting.  Written in C, with check test framework, gcc, and gnu make

To run tests, run make on command line, or make test.

All of the executables are tests, that drive the roman calculator methods of add and subtract.

It basically breaks the two roman numeral numbers into decimal, performs normal addition/subtraction, and then converts back into roman numeral form.

If you make target docker: run make docker, it will build and run a docker to run the roman numeral kata within ubuntu 14.04, docker image.

It does not compile on mac now, it has a -lrt option that Mac does not need, but Linux does need.

add/subtract/convert when appropriate will return with the following:

*0: Nothing wrong
*1: You tried to enter a roman digit with a multiplier too large (smaller than 10 times: aka IM)
*2: 4000 or greater entered, or result of add greater than 4000
*3: V, L, or D more than one (VV is invalid)
*4: Subtract gives negative value or zero.

If any of the codes above 1 are returned the answer returned will be 0, which itself is an invalid answer.

Thanks,

Author: Jason Hite
email: jhite@pillartechnology.com
August 11, 2016


