#include "shortest-pathTree.h"
#define IFAFEWCITIES 1

void pathTree::setVertexPathTree(int src, destLength* dest)
{
	this->vertex[src] = srcDist(dest, getNumbVert());
}

bool pathTree::isExistVertexInPathTree(int src)
{
	if (this->vertex[src].exist == true) { 
		return true; 
	}
	return false;
}

void pathTree::dijkstra(Graph* graph, int src)
{
	int numVertex = graph->getNumbVertices();

	destLength* dest = new destLength[numVertex];


	dest[src].length = 0;
	

	MyHeap heap;
	
	heap.push({ src, 0 });

	while (!heap.empty()) {
		MinHeapNode minHeapNode = heap.pop();

		int vert = minHeapNode.v;

		ListNode* ptr = graph->getArray()->get(vert).getHead();

		

		while (ptr != nullptr) {
			if (dest[vert].length + ptr->weight < dest[ptr->dest].length ) {

				

				dest[ptr->dest].length = dest[vert].length + ptr->weight;
				
				if (dest[vert].pathOfVertex->getSize() > 0) {
					if (dest[ptr->dest].pathOfVertex->get(dest[ptr->dest].pathOfVertex->getSize() - 1) == ptr->dest) {
						dest[ptr->dest].pathOfVertex->~vector();
						dest[ptr->dest].pathOfVertex = new vector<int>;
					}
					for (int i = 0; i < dest[vert].pathOfVertex->getSize(); i++) {
						
						dest[ptr->dest].pathOfVertex->push(dest[vert].pathOfVertex->get(i));
					}
					dest[ptr->dest].pathOfVertex->push(ptr->dest);
					
				}
				else {
					dest[ptr->dest].pathOfVertex->push(ptr->dest);
				}
				
				

				heap.push({ ptr->dest, dest[ptr->dest].length });
			

			}
				ptr = ptr->next;
		}


	}

	setVertexPathTree(src, dest);
}

void pathTree::print()
{
	for (int i = 0; i < getNumbVert(); i++) {
		cout << vertex[i] << endl;
	}
}

