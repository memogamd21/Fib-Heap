
#ifndef FIBONACCIHEAP_H
#define FIBONACCIHEAP_H

#include <vector>

using namespace std;

class fibonacciHeap
{
public:

	fibonacciHeap();
	struct node {
		node* Parent;
		node* Child;
		node* Left;
		node* Right;
		bool marked;
		int key;
		int degree;

	};
	struct FiboHeap {
		node* min;
		int numofMarked;
		int heapdegree;
		int numofNodes;
		vector <node*> rootlist;
	};
	FiboHeap* MakeFHeap();
	node* findMin(FiboHeap* H);
	FiboHeap* fHeap;
	FiboHeap* extractMin(FiboHeap* M);
	FiboHeap* consolidate(FiboHeap* Y);
	FiboHeap* Link(FiboHeap* J, node* D, node* M);
	FiboHeap* Insert(FiboHeap* H, int k);
	vector<node*> TraversedHeap;
	void Traverse(node* B);





};

#endif // !FIBONACCIHEAP_H
