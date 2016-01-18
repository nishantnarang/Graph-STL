#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include "Graph.h"

using namespace std;

int main()
{
	
	string str;
	vector<string> V;

	// defining Node pointers
	Node<int> *Obj1,*Obj2,*Obj3,*Obj4;

	/*allocating memory to Nodes*/
	Obj1 = new Node<int>;
	Obj2 = new Node<int>;
	Obj3 = new Node<int>;
	Obj4 = new Node<int>;
	
	// filling Obj1 Information 
	Obj1->setData(5);
	Obj1->setName("nishant");
	V.push_back("shubham");
	V.push_back("manish");
	Obj1->setNeighbours(V);
	
	// filling Obj2 Information *
	Obj2->setData(6);
	Obj2->setName("shubham");
	V.clear();
	V.push_back("peeyush");
	Obj2->setNeighbours(V);

	
	// filling Obj3 Inforamtion 
	Obj3->setData(8);
	Obj3->setName("manish");
	V.clear();
	V.push_back("peeyush");
	V.push_back("shubham");
	Obj3->setNeighbours(V);

	//filling Obj4 information 
	Obj4->setData(11);
	Obj4->setName("peeyush");
	V.clear();
	Obj4->setNeighbours(V);

	//Defining an Graph Variable  
	Graph<int>  G;

	// Adding Nodes  to the Graph 
	G.AddNode(Obj1);
	G.AddNode(Obj2);
	G.AddNode(Obj3);
	G.AddNode(Obj4);

	cout<<"printing the graph in bfs form"<<endl;
	Obj1->Bfs();
	cout<<endl;
	
	cout<<"printing the graph in dfs form"<<endl;
	Obj1->Dfs();
	cout<<endl;

	cout<<"printing the graph in dot format"<<endl;
	G.Print();
	cout<<endl;
	/*deleting Nodes of the Graph */
	G.DeleteNode(Obj3);
       	G.DeleteNode(Obj4);

	cout<<"printing the graph after deleting the nodes"<<endl;
	G.Print();
	cout<<endl;
	/* clear the Graph */
	G.Clear();	
	
	return 0;
 }






