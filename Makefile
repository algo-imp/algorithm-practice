
# Specify the compiler
CC = g++

#CCOPTS = -ansi -pedantic -Wall -g
CCOPTS = -g -Wall

# Make the source
all:	tccc2003-semifinal3-zigzag

# main: 	srm184-div2-lev3
	
srm181-div1-lev3:
	$(CC) $(CCOPTS)  srm181-div1-lev3.cpp -o srm181-div1-lev3.out
	
srm184-div2-lev3:
	$(CC) $(CCOPTS)  srm184-div2-lev3.cpp -o srm184-div2-lev3.out
	
tccc2003-semifinal3-zigzag:
	$(CC) $(CCOPTS)  tccc2003-semifinal3-zigzag.cpp -o tccc2003-semifinal3-zigzag.out
	
clean :
	rm -f *.o *.out
