#include "fibonacciHeap.h"
#include <iostream>

using namespace std;


fibonacciHeap::fibonacciHeap()
{
	fHeap = MakeFHeap();
}


fibonacciHeap::FiboHeap* fibonacciHeap::MakeFHeap() {
	FiboHeap* Temp = new FiboHeap();
	Temp->heapdegree = 0;
	Temp->min = NULL;
	Temp->numofMarked = 0;
	Temp->numofNodes = 0;
	return Temp;
}

fibonacciHeap::node* fibonacciHeap::findMin(FiboHeap* H)
{
	return H->min;
}

fibonacciHeap::FiboHeap* fibonacciHeap::extractMin(FiboHeap* M)
{
	node* temp = new node();
	node* temp2 = new node();
	temp = M->min;
	if ((temp != NULL && temp->Right != temp) || (temp -> Child != NULL)) {
		temp2 = temp->Child;
		while (temp2->Right != M->min->Child) {
			M->rootlist.push_back(temp2);
			temp2->Parent = NULL;
			temp2 = temp2->Right;
		}
		delete temp;
		int index;
		for (int j = 0; j < M->rootlist.size(); j++) {
			if (M->rootlist[j]->key == M->min->key) {
				index = j;
			}

			M->rootlist.erase(M->rootlist.begin()+index);
			node* min = new node();
			min = M->rootlist[0];
			for (int i = 0; i < M->rootlist.size(); i++) {
				if (M->rootlist[i]->key < min->key) {
					min = M->rootlist[i];
				}
			}
			M->min = min;
			M->numofNodes--;
			consolidate(M);
			return M;
		}
	}
	else if (temp == temp->Right && temp->Child == NULL) {// case when we have only one node in the fibonacci heap
		M->min = NULL;
		M->numofNodes = 0;
		M->numofMarked = 0;
		M->rootlist.erase(M->rootlist.begin());// root list is empty now
		return M;
	}
	/*else {// case where we have only two nodes in the rootlist
		temp2 = temp->Child;
		while (temp2->Right != M->min->Child) {
			M->rootlist.push_back(temp2);
			temp2->Parent = NULL;
			temp2 = temp2->Right;
		}
		M->min = M->min->Right;
		delete temp;
		int index2;
		for (int J = 1; J < M->rootlist.size(); J++) {
			if (M->rootlist[J]->key < M->min->key) {
				index2 = J;
			}
			M->rootlist.erase(M->rootlist.begin()+index2);
			consolidate(M);
			M->numofNodes--;
			return M;



		}

	}*/
	}



fibonacciHeap::FiboHeap* fibonacciHeap::consolidate(FiboHeap* Y)
{
	const int f = Y->heapdegree;
	node* A[f];
	for (int g = 0; g < Y->heapdegree; g++)
	{
		A[g] = NULL;
	}
	node* temp = new node();
	int deg;
	for (int O = 0; O < Y->rootlist.size(); O++)
	{
		temp = Y->rootlist[O];
		deg = temp->degree;
		A[deg] = temp;
		//
		if (A[deg] != NULL && Y->rootlist[O]->degree == deg) {
			Link(Y, A[deg], Y->rootlist[O]);
			A[deg] = NULL;
			deg = deg + 1;
		}
	}
	return Y;
}

fibonacciHeap::FiboHeap* fibonacciHeap::Link(FiboHeap* J, node* D, node* M)
{
	if (D->key < M->key) {
		M->Parent = D;
		D->degree++;
		int index3;
		for (int l = 0; l < J->rootlist.size(); l++) {
			if (J->rootlist[l]->key == M->key) {
				index3 = l;
			}
		}
        D->marked = false;
		J->rootlist.erase(J->rootlist.begin() + index3);
		return J;

	}
	else if (D->key > M->key)
	{
		D->Parent = M;
		M->degree++;
		int index3;
		for (int n = 0; n < J->rootlist.size(); n++) {
			if (J->rootlist[n]->key == M->key) {
				index3 = n;
			}
		}
		J->rootlist.erase(J->rootlist.begin()+index3);
		M->marked = false;
		return J;
	}
}


void fibonacciHeap::Traverse(node* B)
{
	node* temp4 = new node();
	temp4 = B;
	node* temp5 = new node();
	while (B != temp4->Right) {
		TraversedHeap.push_back(temp4);
		temp5 = temp4->Child;
		while (temp4->Child != temp5->Right) {
            if(temp5->Child == NULL){
			TraversedHeap.push_back(temp5);
		}else if(temp5->Child != NULL){
            Traverse(temp5);
		}
		temp5 = temp5->Right;
	}
	temp4 = temp4->Right;
}
}

fibonacciHeap::FiboHeap* fibonacciHeap::Insert(FiboHeap* H, int k)
{
	node* temp = new node();
	temp->Child = NULL;
	temp->degree = 0;
	temp->key = k;
	temp->Left = H->rootlist[H->rootlist.size()];
	temp->Right = H->rootlist[0];
	H->rootlist[0]->Left = temp;
	H->rootlist[H->rootlist.size()]->Right = temp;
	temp->Parent = NULL;
	temp->marked = false;
	H->rootlist.push_back(temp);
	H->numofNodes++;
	consolidate(H);
	return H;
}
