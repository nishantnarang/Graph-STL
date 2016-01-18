#ifndef _NODE_H_
#define _NODE_H_


#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<string>

#include "SmallInterface.h"

using namespace std;

/* this is an Node Class Which is responsible for making Nodes of Graph */

template<typename T>
class Node
{
	private:
	T Data;   //Data inside the Node
	string Name; // name of the Node
	vector<string> Neighbours; //List of names of All neighbours of Node
	SmallInterface *Var;    // pointer to interface used by Dfs And Bfs member functions
 	int Id;   //Id of Node in Graph

	private:
	 void DfsTraversal(Node<T>*,bool*); // Dfs helper function
	
	public:
	Node(); //Default Constructor of Node
	Node(T,string ,vector<string>);  //Constructor which Assign Value to Node
	void setData(T); //Set Data to the Node
	void setName(string); //Set Name of the Node
	void setId(int);
	void setNeighbours(vector<string>); //set Neighbours Names
	void setInterface(SmallInterface *); //setter function for Var Interface 
 	T getData(); // get Data 
	string getName(); // get Name 
	int getId();  // get Id
	vector<string> getNeighbours(); // get Neighbours Names List
	void Bfs();    // Bfs function
	void Dfs();    // Dfs function
	 
	
};

#endif
