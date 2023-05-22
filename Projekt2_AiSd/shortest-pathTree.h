#ifndef SHORTESTPATHTREE_H
#define SHORTESTPATHTREE_H
#define INF 1e9;

//#include "graph.h"
#include "heap.h"
using namespace std;


struct destLength {
	int length;
	vector<int>* pathOfVertex;

	destLength() {
		this->length = INF;
		this->pathOfVertex = new vector<int>;
	}

	friend ostream& operator<<(ostream& os, const destLength& obj) {
		
			os << obj.length << " ";
			obj.pathOfVertex->print();
		

			return os;
		
	}
};

struct srcDist {
	bool exist;
	destLength* dest;
	int numVertex;

	srcDist() {
		this->dest = nullptr;
		this->exist = false;
	}

	srcDist(destLength* dest, int numVertex) {
		this->dest = dest;
		this->exist = true;
		this->numVertex = numVertex;
	} 

	

	friend ostream& operator<<(ostream& os, const srcDist& obj) {

		os << "isExist: " << obj.exist << " ";
		if (obj.dest != nullptr) {


			for (int i = 0; i < obj.numVertex; i++) {
				os << obj.dest[i] << " ";
			}
		}

		return os;
	}

};

class pathTree {
private:
	srcDist* vertex;
	int numbOfVertex;


public:
	pathTree() {
		this->vertex = nullptr;
		this->numbOfVertex = 0;
	}



	pathTree(int numverVertex) {
		this->vertex = new srcDist[numverVertex]();
		this->numbOfVertex = numverVertex;
		this->vertex->numVertex = numverVertex;
	}

	

	srcDist getVertexByIndex(int index) { return vertex[index]; };



	void setVertexPathTree(int src, destLength* dest);

	bool isExistVertexInPathTree(int src);

	void dijkstra(Graph* graph, int src);

	

	int getNumbVert() { return numbOfVertex; };

	void print();

};





#endif