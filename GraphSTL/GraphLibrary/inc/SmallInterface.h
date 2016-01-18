#ifndef _SMALLINTERFACE_H_
#define _SMALLINTERFACE_H_

#include<string>

using namespace std;


class SmallInterface
{

	public:
		SmallInterface(){};
		virtual ~SmallInterface(){};
		virtual void* getNodePtr(string) = 0;
		virtual bool getActivity(void *) = 0;
		virtual int getNumberOfNodes() = 0;
};


#endif
