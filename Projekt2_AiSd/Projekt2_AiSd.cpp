#include <iostream>
#include "string.h"
#include "vector.h"
#include "map.h"
#include "shortest-pathTree.h"

using namespace std;

int main()
{
	int heightB, widthB;
	char ch;	
	int numAirports;
	int numQuestions;
	char buffer[128] = {};
	myString nameCity1, nameCity2;
	cin >> widthB >> heightB;
	map mapa(heightB, widthB);


	for (int i = 0; i < heightB; i++) {
		for (int j = 0; j < widthB; j++) {
			ch = getchar();
			if (ch == '\n') {
				ch = getchar();
			}
			mapa.getMapa()[i][j] = ch;
		}
	}
	

	mapa.checkMap();
	mapa.BFS();

	


	cin >> numAirports;
	for (int i = 0; i < numAirports; i++) {
		cin >> buffer;
		int src = mapa.getGraph()->findNumbCity(buffer);
		cin >> buffer;
		int dest = mapa.getGraph()->findNumbCity(buffer);
		int weight;
		cin >> weight;
		mapa.getGraph()->addAirportEdge(mapa.getGraph(), src, dest, weight);
	}

	mapa.getGraph()->print();


	int modeOfQuestion;
	cin >> numQuestions;
	for (int i = 0; i < numQuestions; i++) {
		cin >> buffer;
		int src = mapa.getGraph()->findNumbCity(buffer);
		cin >> buffer;
		int dest = mapa.getGraph()->findNumbCity(buffer);
		cin >> modeOfQuestion;
		if (!mapa.getTree()->isExistVertexInPathTree(src)) {
			mapa.getTree()->dijkstra(mapa.getGraph(), src);
		}
			if (modeOfQuestion == 0) {
				cout << mapa.getTree()->getVertexByIndex(src).dest[dest].length << endl;
			}
			else {
				cout << mapa.getTree()->getVertexByIndex(src).dest[dest].length << " ";

				for (int i = 0; i < mapa.getTree()->getVertexByIndex(src).dest[dest].pathOfVertex->getSize() - 1; i++) {
					cout << mapa.getGraph()->getArray()->get(mapa.getTree()->getVertexByIndex(src).dest[dest].pathOfVertex->get(i)).getMotherCity().name << " ";
				}
				cout << endl;
			}
		}
}