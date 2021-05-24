// -------------------------------------------------GraphM.h-----------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Created: Jan. 29, 2018
// Last Mdofied: Feb. 11, 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Declaration of methods to creates a graph using adjacency matrix and an adjacency t
// --------------------------------------------------------------------------------------------------------------------
// Notes: Uses nodedata
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#include "nodedata.h"
#include <fstream>
//#include <iomanip>
//#include <locale>
//#include "atlstr.h"
#include <iostream>
#include <cctype>
#include <string>

class GraphM {
	const static int MAXNODES = 100;
public:
	//------------------- constructors/destructor  -------------------------------
	GraphM();
	~GraphM();
	//-------------------------- buildGraph --------------------------------------
	// Creates a GraphM object from a fstream. Assumes correct input.
	// Preconditions: 
	// Postconditions: An ifstream containing the number of nodes, names of the 
	// nodes and the paths between nodes followed by their weight
	void buildGraph(ifstream&);
	//-------------------------- insertEdge --------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void insertEdge();
	//-------------------------- removeEdge --------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void removeEdge();
	//-------------------------- insertEdge --------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void findShortestPath();
	//----------------------- findShortestPath -----------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void display(int, int); // display path from one node to another to cout
	//-------------------------- displayAll --------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void displayAll(); // display shortest distance, path to cout
private:
	struct TableType {
		bool visited;          // whether node has been visited
		int dist;              // shortest distance from source known so far
		int path;              // previous node in path of min dist
	};
	NodeData data[MAXNODES];              // data for graph nodes 
	int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix
	int size;                             // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path
	//--------------------------- is_number --------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	bool is_number(const string&);
	//------------------------ shortestPathFrom ----------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void shortestPathFrom(int, int);
};

