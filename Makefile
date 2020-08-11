# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++ -std=c++11
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o othello.o MCTS.o
	$(CXX) $(CXXFLAGS) -o main main.o othello.o MCTS.o

# The main.o target can be written more simply

main.o: main.cpp othello.h MCTS.h
	$(CXX) $(CXXFLAGS) -c main.cpp

othello.o: othello.h

