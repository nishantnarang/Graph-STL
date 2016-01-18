
 #include "Graph.h"

 template<typename T1>
 void Graph<T1>::AddNode(Node<T1> *ptr)
 {
 	int  sz = NodeList.size();
	NodeList.push_back(ptr);
	Active.push_back(true);
	M[ptr->getName()] = sz+1;
	numberOfNodes++;	
	ptr->setId(numberOfNodes);
	ptr->setInterface(dynamic_cast<SmallInterface*>(this));
 }


 template<typename T1>
 void Graph<T1>::DeleteNode(Node<T1> *ptr)
 {
	
	if(M[ptr->getName()] == 0)
	{
		return;
	}
	else
	{

		int val = M[ptr->getName()];
		Active[val-1] = false;
		ptr->getNeighbours().clear();		
	}	
	
 }


 template<typename T1>
 void Graph<T1>::Print()
 {
	int sz;

	sz = NodeList.size();

	if(Mark != 0)
	{
		for(int i = 0;i < prevsz;i++)
		{
			delete[] Mark[i];
		}
		Mark = 0;
	}
	Mark = new int*[sz];
	for(int i = 0;i < sz;i++)
		Mark[i] = new int[sz]();

	prevsz = sz;
	for(int i = 0;i < sz;i++)
	{
		if(Active[i])
		{
			End = -1;
			SearchNode(NodeList[i]);	
		}
	}
 }



 template<typename T1>
 void Graph<T1>::SearchNode(Node<T1> *ptr)
 {
	vector<string> V;
	V = ptr->getNeighbours();
	int sz = V.size();
	int rootIdx  = M[ptr->getName()]-1;
	
	for(int i = 0;i < sz;i++)
	{	
		string str = V[i];
		int childIdx = M[str]-1;
		if(Active[childIdx])
		{	
			if(!Mark[rootIdx][childIdx])
			{
				End = 0;	
				Mark[rootIdx][childIdx] = 1;
				cout<<NodeList[rootIdx]->getName()<<"("<<NodeList[rootIdx]->getData()<<")"<<"..";
				SearchNode(NodeList[childIdx]);
			}
		}				
	}
	if(End == 0)
	{
		cout<<NodeList[rootIdx]->getName()<<"("<<NodeList[rootIdx]->getData()<<")"<<endl;
		End = 1;
	}		
 }



 template<typename T1>
 void Graph<T1>::Clear()
 {
	NodeList.clear();
	Active.clear();	
	M.clear();
	numberOfNodes = 0;
	
	if(Mark != 0)
	{
		for(int i = 0;i < prevsz;i++)
		{
			delete[] Mark[i];
		}
		Mark = 0;
	}	
 }


 template<typename T1>
 void* Graph<T1>::getNodePtr(string name)
 {
	int val = M[name]-1;
	return NodeList[val];
 }

 template<typename T1>
 bool Graph<T1>::getActivity(void *data)
 {
 	Node<T1> *ptr = static_cast<Node<T1>*>(data);
	int val = M[ptr->getName()]-1;
	return Active[val];	
 }


 template<typename T1>
 int Graph<T1>::getNumberOfNodes()
 {
	return numberOfNodes;	
 }
 
 template class Graph<int>;
 template class Graph<float>;
 template class Graph<double>; 
