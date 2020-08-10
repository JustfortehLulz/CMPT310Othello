# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o othello.o
	$(CXX) $(CXXFLAGS) -o main main.o othello.o

# The main.o target can be written more simply

main.o: main.cpp othello.h
	$(CXX) $(CXXFLAGS) -c main.cpp

othello.o: othello.h

