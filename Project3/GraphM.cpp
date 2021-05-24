// -----------------------------------------------GraphM.cpp-----------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Created: Jan. 29, 2018
// Last Mdofied: Feb. 11, 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
// Notes: Uses nodedata
// --------------------------------------------------------------------------------------------------------------------

#include "GraphM.h"

GraphM::GraphM() {
	size = 0;
}

GraphM::~GraphM() {

}

void GraphM::buildGraph(ifstream &in) {
	string tempS = "";
	int x = 0;
	int arr[3] = { -1,-1,-1 };
	getline(in, tempS);
	if (!is_number(tempS))
		return;
	size = stoi(tempS);
	tempS = "";
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			C[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < size; i++) {
		getline(in, tempS);
		data[i] = NodeData(tempS);
		tempS = "";
	}
	while (!(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)) {
		for (int i = 0; i < 3; i++) {
			in >> tempS;
			if (!is_number(tempS))
				return;
			arr[i] = stoi(tempS);
			tempS = "";
		}
		C[arr[0]][arr[1]] = arr[2];
	}
	getline(in, tempS);
}

void GraphM::insertEdge() {

}

void GraphM::removeEdge() {
}

void GraphM::findShortestPath() {
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			T[i][j].visited = false;
			T[i][j].dist = INT_MAX;
			T[i][j].path = -1;
		}
	}
	for (int i = 1; i <= size; i++) {
		T[i][i].dist = 0;
		shortestPathFrom(i, i);
	}
}

void GraphM::display(int from, int to) {

}

void GraphM::displayAll() {
	for (int i = 1; i <= size; i++) {

		for (int j = 1; j <= size; j++) {
			if (T[i][j].dist != INT_MAX)
				cout << T[i][j].dist << " | ";
			else
				cout << "--" << " | ";
		}
		cout << endl;
	}
}

bool GraphM::is_number(const string& s) {
	string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void GraphM::shortestPathFrom(int from, int source) {
	T[source][from].visited = true;
	int minNode = -1, minDist = INT_MAX;
	for (int i = 1; i <= size; i++) {
		if (!(T[source][i].visited) && C[from][i] != INT_MAX) {
			if (T[source][i].dist > T[source][from].dist + C[from][i]) {
				T[source][i].dist = T[source][from].dist + C[from][i];
				T[source][i].path = from;
			}
			if (T[source][i].dist < minDist) {
				minNode = i;
				minDist = T[source][i].dist;
			}
		}
	}
	if (minNode != -1)
		shortestPathFrom(minNode, source);
	return;
}
