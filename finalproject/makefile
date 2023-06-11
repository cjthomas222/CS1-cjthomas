# # compiler name
# CXX = g++
# # c++ compiler flags
# # -g: adds debugging information to the executable file
# # - Wall turns on most, but not  all, compiler warnings
# # -std=C++17 uses c++17 standard
# # put all the required flags separated by space
# CXXFLAGS = -c -g -Wall -std=c++17

# # the build target executable file; .exe is not required
# PROGRAM = hangman.exe

# PROGRAM = hangman.out

# # list .cpp files separated by space
# CPPFILES = hangman.cpp

# # make all rule/default rule that'll be run when we run "make"
# # first compile each file to object file
# # then make a single binary program
# all:
# 	$(CXX) $(CXXFLAGS) $(CPPFILES)
# 	$(CXX) header.h -o $(PROGRAM) *.o

# # make clean rule
# # delete object and binary files
# clean:
# 	rm -f $(PROGRAM) *.o
CC = clang++
CFLAGS = -Wall -g
PROGRAM = hangman.out
CPPFILES = hangman.cpp
 
# ****************************************************
# Targets needed to bring the executable up to date
 
all:
	$(CC) $(CFLAGS) $(CPPFILES)
	$(CC) -o $(Program) header.h

clean:
	rm -f $(PROGRAM) *.o
