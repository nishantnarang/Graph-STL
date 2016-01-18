  #include "Node.h"


  template<typename T>
  Node<T>::Node() //Default Constructor of Node
  {
	Data = 0;
	Name = "";
	Id = 0;
  }

  template<typename T>
  Node<T>::Node(T val,string name,vector<string> neighbours)  //Constructor which Assign Value to Node
  {	
	Data = val;
	Name = name;
	int sz = neighbours.size();
	for(int i  = 0;i < sz;i++)
	{
		Neighbours.push_back(neighbours[i]);
	}
	Id = 0;			
  }		


  
   template<typename T>
   void Node<T>::setId(int id)
   {
	Id = id;
   }
		

  template<typename T>
  void Node<T>::setInterface(SmallInterface  *ptr)
  {		
	Var =  ptr;
  }  
	
  template<typename T>
  void Node<T>::setData(T val)
  {
  	Data = val;
  }


  template<typename T>
  void Node<T>::setName(string name)
  {
  	Name = name; 
  }

   template<typename T>
   void Node<T>::setNeighbours(vector<string> neighbours)
   {
   	int sz = neighbours.size();
	for(int i = 0;i < sz;i++)
	{
		Neighbours.push_back(neighbours[i]);
	}

    }

   
   template<typename T>
   int Node<T>::getId()
   {
	return Id;
   } 

   template<typename T>
   T Node<T>::getData()
   {
	return Data;		
   }

		
   template<typename T>
   string Node<T>::getName()
   {
	return Name;
   }

   template<typename T>
   vector<string> Node<T>::getNeighbours()
   {
	return Neighbours;
   }


   template<typename T>
   void Node<T>::Bfs()
   {

	if(Id <= 0)
		return;
	const int ArraySize = Var->getNumberOfNodes()+2;
	bool Mark[ArraySize];
	bool isActive;
	Node<T> *Me,*MyFriend;
	int sz,i;
	queue<Node<T>* > Queue;

	memset(Mark,false,sizeof(Mark));
	

	Queue.push(this);
	Mark[this->getId()] = true;
	
	while(!Queue.empty())
	{
		Me = Queue.front();
	        isActive = Var->getActivity(Me);
		Queue.pop();
		if(!isActive)
			continue;
		vector<string> V = Me->getNeighbours();
		cout<<Me->getName()<<" ";
		sz = V.size();
		for(i = 0;i < sz;i++)
		{
			 MyFriend = static_cast<Node<T>*>(Var->getNodePtr(V[i]));
			if(!Mark[MyFriend->getId()])
			{
				Queue.push(MyFriend);
				Mark[MyFriend->getId()] = true;
			}			
		}
	}
	cout<<endl;
										
   }


   template<typename T>
   void Node<T>::Dfs()
   {	
	if(Id <= 0)
		return;
	const int ArraySize = Var->getNumberOfNodes() + 2;
	bool *Mark;
	Mark = new bool[ArraySize];
	memset(Mark,false,sizeof(bool)*ArraySize);	
	DfsTraversal(this,Mark);
	cout<<endl;
	delete [] Mark;		
   }
  
   template<typename T>
   void Node<T>::DfsTraversal(Node<T> *Root,bool *Mark)
   {		
	int i,sz;
	vector<string> V;
	Node<T> *MyFriend;
	if(!Var->getActivity(Root))
		return;
	Mark[Root->getId()] = true;
	V = Root->getNeighbours();
	sz = V.size();
	cout<<Root->getName()<<" ";

	for(i = 0;i < sz;i++)
	{
		MyFriend = static_cast<Node<T>*>(Var->getNodePtr(V[i]));
		if(!Mark[MyFriend->getId()])
		{
			DfsTraversal(MyFriend,Mark);
		}
	}	
   }	


   
 template class Node<int>;
 template class Node<float>;
 template class Node<double>;	
