#Ex1_0 the  real one;;
 # $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

CC     = gcc
FLAGS = -Wall -Werror -g
DEPSF = trietree.o main.o
DEPS     =  trietree.h

#The main Execute files:
all: frequency

frequency: $(DEPSF)
	$(CC) $(FLAGS) $^ -o $@

main.o: main.c $(DEPS)
	$(CC) -c $(FLAGS) $<
	
trietree.o: trietree.c $(DEPS)
	$(CC) -c $(FLAGS) $<

.PHONY: 
	clean  all
clean:
	rm  *$(DEPSF) frequency
 
