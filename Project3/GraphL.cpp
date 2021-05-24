// -----------------------------------------------GraphL.cpp-----------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Created: Jan. 29, 2018
// Last Mdofied: Feb. 11, 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
// Notes: Uses nodedata
// --------------------------------------------------------------------------------------------------------------------

#include "GraphL.h"

GraphL::GraphL() {
	size = 0;
}

GraphL::~GraphL() {
	for (int i = 1; i <= size; i++) {
		removeAll(graph[i].edgeHead);
		delete graph[i].data;
	}
}

void GraphL::buildGraph(ifstream &in) {
	string tempS = "";
	int x = 0;
	int arr[2] = { -1,-1 };
	getline(in, tempS);
	if (!is_number(tempS))
		return;
	size = stoi(tempS);
	tempS = "";
	for (int i = 1; i <= size; i++) {
		getline(in, tempS);
		NodeData* temp = new NodeData(tempS);
		graph[i].data = temp;
		graph[i].edgeHead = NULL;
		temp = nullptr;
		tempS = "";
	}
	while (!(arr[0] == 0 && arr[1] == 0)) {
		for (int i = 0; i < 2; i++) {
			in >> tempS;
			if (!is_number(tempS))
				return;
			arr[i] = stoi(tempS);
			tempS = "";
		}
		if (!(arr[0] == 0 && arr[1] == 0)) {
			EdgeNode *head, *newNode;
			newNode = new EdgeNode;
			newNode->adjGraphNode = arr[1];
			newNode->nextEdge = NULL;
			head = graph[arr[0]].edgeHead;
			graph[arr[0]].edgeHead = newNode;
			newNode->nextEdge = head;
		}
	}
	getline(in, tempS);
}

void GraphL::displayGraph() {
	EdgeNode* curr;
	for (int i = 1; i <= size; i++) {
		cout << *graph[i].data << " " << i << " ";
		curr = graph[i].edgeHead;
		if (curr != NULL) {
			cout << curr->adjGraphNode << " ";
			while (curr->nextEdge != NULL) {
				curr = curr->nextEdge;
				cout << curr->adjGraphNode << " ";
			}
		}
		cout << endl;
	}
}

void GraphL::depthFirstSearch() {
	for (int i = 1; i <= size; i++)
		graph[i].visited = false;
	for (int i = 1; i <= size; i++)
		if (!graph[i].visited)
			dfs(i);
}

bool GraphL::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void GraphL::dfs(int n) {
	graph[n].visited = true;
	cout << n << endl;  // Output vertices in depth-first order
	EdgeNode *current = graph[n].edgeHead;
	int min = size + 1;
	while (current != NULL) {
		if (!graph[current->adjGraphNode].visited && current->adjGraphNode)
			dfs(current->adjGraphNode);
		current = current->nextEdge;
	}
}

void GraphL::removeAll(EdgeNode *p) {
	if (p != NULL) {
		removeAll(p->nextEdge);
		delete p;
		p = NULL;
	}
}