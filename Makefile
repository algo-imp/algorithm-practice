
# Specify the compiler
CC = g++

#CCOPTS = -ansi -pedantic -Wall -g
CCOPTS = -g -Wall

# Make the source
all:	srm184-div2-lev3

# main: 	srm184-div2-lev3
	
srm181-div1-lev3:
	$(CC) $(CCOPTS)  srm181-div1-lev3.cpp -o srm181-div1-lev3.out
	
srm184-div2-lev3:
	$(CC) $(CCOPTS)  srm184-div2-lev3.cpp -o srm184-div2-lev3.out
clean :
	rm -f *.o *.out
