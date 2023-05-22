#include "map.h"



map::map()
{
	this->heightB = 0;
	this->widthB = 0;
	this->mapa = nullptr;
	this->graph = new Graph();
}

map::map(int width, int height)
{
	this->heightB = width;
	this->widthB = height;

	this->mapa = new char* [heightB];
	for (int i = 0; i < heightB; i++) {
		this->mapa[i] = new char[widthB];
	}

	this->graph = new Graph();
}

map::~map()
{
	for (int i = 0; i < heightB; i++) {
		delete[] mapa[i];
	}
	delete[] mapa;


}



void map::addCity(point coord, myString name)
{
	graph->addNode(city(coord, name));
}

void map::BFS()
{
	
	int moves[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	bool** visited = new bool* [heightB];
	for (int i = 0; i < heightB; i++) {
		visited[i] = new bool [widthB];
	}

	int** dist = new int* [heightB];
	for (int i = 0; i < heightB; i++) {
		dist[i] = new int[widthB];
	}

	

	vector<point> q;
	vector<point> qS;
for (int i = 0; i < this->getGraph()->getArray()->getSize(); i++) {
	
		for (int i = 0; i < heightB; i++) {
			for (int j = 0; j < widthB; j++) {
				dist[i][j] = 0;
				visited[i][j] = false;
			}
		}

	point start = point(this->getGraph()->getArray()->get(i).getMotherCity().coord);
	
	if (start == point(-1, -1)) {
		continue;
	}

	qS.push(start);
	q.push(start);
	visited[start.getX()][start.getY()] = true;
	dist[start.getX()][start.getY()] = 0;




	while(qS.getSize() != 0) {
		
		q.push(qS.get(0));
		visited[qS.get(0).getX()][qS.get(0).getY()] = true;
		dist[qS.get(0).getX()][qS.get(0).getY()] = 0;


		while (q.getSize() != 0) {
			int x = q.get(0).getX();
			int y = q.get(0).getY();
			q.popFront();

			for (int l = 0; l < 4; ++l) {
				int ti = x + moves[l][0];
				int tj = y + moves[l][1];
				if (ti < 0 || ti >= heightB || tj < 0 || tj >= widthB) {
					// This move goes out of the field
					continue;
				}

				if (mapa[ti][tj] == '#' && !visited[ti][tj]) {
					visited[ti][tj] = true;
					dist[ti][tj] = dist[x][y] + 1;
					q.push(point(ti, tj));
				}

				if (mapa[ti][tj] == '*' && !visited[ti][tj]) {
					visited[ti][tj] = true;
					dist[ti][tj] = dist[x][y] + 1;
					int dest = this->getGraph()->findNumbCity(point(ti, tj));
					int src = this->getGraph()->findNumbCity(point(qS.get(0).getX(), qS.get(0).getY()));
					if (src != -1 && dest != -1) {
						this->getGraph()->addEdge(this->getGraph(), src, dest, dist[ti][tj]);
					}
					dist[ti][tj] = 1;
					qS.push(point(ti, tj));
				}

			}
		}
		qS.popFront();


		


		}

	

	}



	for (int i = 0; i < heightB; i++) {
		delete[] visited[i];
		delete[] dist[i];
	}
	delete[] visited;
	delete[] dist;


}



void map::print()
{
	for (int i = 0; i < heightB; i++) {
		for (int j = 0; j < widthB; j++) {
			cout << mapa[i][j];
		}
		cout << endl;
	}
}

point map::findCity(point coord)
{
	int K = - 1;
if (coord.getX() == 0 && K == -1) {
	K = 0;
}
for (; K <= 1; ++K) {
		
		

	if (coord.getX() == (heightB - 1) && K == 0) { continue; }
		for (int L = -1; L <= 1; ++L) {
			if (coord.getY() == 0 && L == -1) {
				L = 0;
			}
			if (coord.getY() == (widthB - 1) && L == 1) { 
				continue; 
			}
			if (coord.getX() == (heightB - 1) && K == 1) {
				continue;
			}
			if (K == 0 and L == 0) {
				continue;
			}

			if (mapa[coord.getX() + K][coord.getY() + L] == '*') {
				return point(coord.getX() + K, coord.getY() + L);
			}

		}
	}
	return point(-1, -1);
}

void map::checkMap()
{
	for (int i = 0; i < heightB; i++) {
		for (int j = 0; j < widthB; j++) {

			if (mapa[i][j] > 64 && mapa[i][j] < 91) {
				myString nameCity;
				point cityPunkt = this->findCity(point(i, j));
				while (mapa[i][j] > 64 && mapa[i][j] < 91 || mapa[i][j] > 47 && mapa[i][j] < 58 || mapa[i][j] > 96 && mapa[i][j] < 123) {
					nameCity = nameCity.appendBack(mapa[i][j]);
					j++;
				}
				if (cityPunkt == point(-1, -1)) {
					cityPunkt = this->findCity(point(i, j - 1));
				}
				this->addCity(cityPunkt, nameCity);
			}
		}
	}
	this->shortestPathTree = new pathTree(this->getGraph()->getNumbVertices());
}
