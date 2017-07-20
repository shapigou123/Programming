#include <iostream>
#include "CMap.h"
#include "node.h"

using namespace std;

int main()
{
	CMap *pMap = new CMap(8);

	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);

	pMap->setValueToMatrixForUndirectedGraph(0,1);
	pMap->setValueToMatrixForUndirectedGraph(0,3);
	pMap->setValueToMatrixForUndirectedGraph(1,2);
	pMap->setValueToMatrixForUndirectedGraph(1,5);
	pMap->setValueToMatrixForUndirectedGraph(3,6);
	pMap->setValueToMatrixForUndirectedGraph(3,7);
	pMap->setValueToMatrixForUndirectedGraph(2,4);
	pMap->setValueToMatrixForUndirectedGraph(6,7);

	pMap->printMatix();
	cout <<endl;

	pMap->resetNode();
	pMap->depthFirstTraverse(0);
	cout<<endl;

	pMap->resetNode();
	pMap->breadthFirstTraverse(0);
	cout<<endl;

	return 0;
}