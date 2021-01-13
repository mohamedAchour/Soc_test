CPPFLAGS =-I$(INCLUDE) -W -Wall #-pedantic -ansi
CC = g++           #define compiler
#BIN = ./bin/       #executables directory
EXEFILE = exec_time #executale name (we can choose any name)
OBJ_FILES = main.o #$(addprefix $(OBJ),exec_time.o ) 

$(EXEFILE) : $(OBJ_FILES) 
	$(CC) -o $@ $(OBJ_FILES) 

#compilation rules
%.o : %.cpp         
	$(CC) -c $(CPPFLAGS) $< -o $@ 
	#gcc $(CFLAGS) $< -o $@

.DEFAULT_GOAL = all

all : $(EXEFILE) 

.PHONY : clean

clean :
	rm -rf  $(OBJ_FILES) $(EXEFILE) *.s 