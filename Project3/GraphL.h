// -------------------------------------------------GraphL.h-----------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Created: Jan. 29, 2018
// Last Mdofied: Feb. 11, 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Declaration of methods to creates a graph using adjacency list
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

class GraphL {
	const static int MAXNODES = 100;
public:
	//------------------- constructors/destructor  -------------------------------
	GraphL();
	~GraphL();
	//-------------------------- buildGraph --------------------------------------
	// Creates a GraphL object from a fstream. Assumes correct input.
	// Preconditions: An ifstream containing the number of nodes, names of the 
	// nodes and the paths between nodes
	// Postconditions: A
	void buildGraph(ifstream&);
	//------------------------- displayGraph -------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void displayGraph();
	//----------------------- depthFirstSearch -----------------------------------
	// Displays the depth first ordering of 
	// Preconditions: 
	// Postconditions: 
	void depthFirstSearch(); // find and display depth-first ordering to cout
private:
	struct EdgeNode;      // forward reference for the compiler
	struct GraphNode {    // structs used for simplicity, use classes if desired
		EdgeNode* edgeHead; // head of the list of edges
		NodeData* data;     // data information about each node
		bool visited;
	};
	struct EdgeNode {
		int adjGraphNode; // subscript of the adjacent graph node
		EdgeNode* nextEdge; 
	};
	//--------------------------- is_number --------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	bool is_number(const string&);
	//------------------------------ dfs -----------------------------------------
	// 
	// Preconditions: 
	// Postconditions: 
	void dfs(int);
	//--------------------------- is_number --------------------------------------
	// 
	// Preconditions: EdgeNode pointer with the value of the edgeHead
	// Postconditions: Removes all EdgeNode objects from the list
	void removeAll(EdgeNode*);
	GraphNode graph[MAXNODES]; // array of GraphNodes
	int size; // number of nodes in the graph
};

