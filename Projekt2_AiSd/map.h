#ifndef MAP_H
#define MAP_H

#include "vector.h"
#include "string.h"
#include "point.h"
#include "graph.h"
#include "shortest-pathTree.h"


class map {
private:
	int heightB, widthB;
	char** mapa;
	Graph* graph;
	pathTree* shortestPathTree;


public:
	map();
	map(int width, int height);
	~map();
	void addCity(point coord, myString name);
	void BFS();
	void print();
	point findCity(point coord);
	void checkMap();
	Graph* getGraph() { return graph; };
	pathTree* getTree() { return shortestPathTree; };
	char** getMapa() { return mapa; };
	int getWidthMap() { return heightB; };
	int getHeightMap() { return widthB; };
};

#endif