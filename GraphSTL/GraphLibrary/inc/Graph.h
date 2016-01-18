#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<string>

#include "Node.h"

using namespace std;


template<typename T1>
class Graph:public SmallInterface
{
	private:
	 vector<Node<T1>*> NodeList; //this Contains List of Nodes in Graph
 	 vector<bool> Active; // Vector defines Aliveness of Node whether Node is Alive or Deleted
         map<string,int> M; // Map used for mapping node names to there positon in NodeList Vector
	 int End;	 //Variable used for SearchNode function
         int **Mark;    //Pointer to  2d array which represent edges visited or not in Graph while Printing
	 int prevsz;    //Variable used for Print Function
	 int numberOfNodes; //Number of Nodes Added in Graph

	private: 
	 void SearchNode(Node<T1>*); //Used by Print function for Searching the Node Path

	public:
	Graph() //default Constructor
	{
		Mark = 0;
		numberOfNodes = 0;	
	}
	void AddNode(Node<T1>*); // for adding the Node in Graph provided Node Pointer
	void DeleteNode(Node<T1>*); // for deleting the Node in Graph provided Node Pointer
	void Print();	// for Printing the Graph in Dot Format 
	void Clear();	// for deleting the Graph i.e freeing the memory
	virtual  void* getNodePtr(string); // function inherited from SmallInterface Class
	virtual  bool getActivity(void *); //function inherited from SmallInterface Class 
	virtual int getNumberOfNodes();  // function inherited from SmallInterface Class

};


#endif

