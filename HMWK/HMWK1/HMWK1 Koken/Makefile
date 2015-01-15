CC = g++
CFLAGS  = -g -Wall

default: build

build:clean statistician position quadratic

statistician:
	$(CC) $(CFLAGS) -o statistician HW1_2.cpp HW1_2_test.cpp

position:
	$(CC) $(CFLAGS) -o position HW1_5.cpp HW1_5_test.cpp

quadratic:
	$(CC) $(CFLAGS) -o quadratic HW1_8.cpp HW1_8_test.cpp

clean:
	rm -rf statistician statistician.dSYM position position.dSYM quadratic quadratic.dSYM
