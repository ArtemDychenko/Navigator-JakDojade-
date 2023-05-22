#ifndef GRAPH_H
#define GRAPH_H
#include "point.h"
#include "vector.h"
#include "string.h"
#include <iostream>


struct city {
	point coord;
	myString name;

	city() {
		this->coord = point(-1, -1);
		this->name = "";
	}

	city(point coord, myString name) {
		this->coord = coord;
		this->name = name;
	}

};


struct ListNode {
	int dest;
	int weight;
	ListNode* next;

	ListNode() {
		this->dest = 0;
		this->weight = 0;
		this->next = nullptr;
	}

	ListNode(int dest, int weight) {
		this->dest = dest;
		this->weight = weight;
		this->next = nullptr;
	}
	~ListNode() { };

};


struct adjList {
private:
	city motherCity;
	ListNode* head;
public:
	adjList() {
		this->head = nullptr;
		this->motherCity = city();
	}


	~adjList() {
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode* temp = curr;
			curr = curr->next;
			delete temp;
		}
		head = nullptr;
	}

	adjList(city motherCity) {
		this->motherCity = motherCity;
		this->head = nullptr;
	}

	void addNodeToList(int direction, int weight) {
		if (this->head == nullptr) {

			ListNode* blo = new ListNode;
			blo->dest = direction;
			blo->weight = weight;
			this->head = blo;
		}
		else {
			ListNode* blo = new ListNode;
			ListNode* ptr = this->head;
			while (ptr->next != nullptr) {
				ptr = ptr->next;
			}
			blo->dest = direction;
			blo->weight = weight;
			ptr->next = blo;
		}
	}

	city getMotherCity() { return motherCity; };
	ListNode* getHead() { return head; };

	friend ostream& operator<<(ostream& os, const adjList& obj) {

		os << obj.motherCity.name << ": coord(" << obj.motherCity.coord << ") ";
		ListNode* ptr = obj.head;
		if (ptr != nullptr) {
			os << "dest: " << ptr->dest << " " << " weight:" << ptr->weight << endl;
			while (ptr->next != nullptr) {
				ptr = ptr->next;
				os << "dest: " << ptr->dest << " " << " weight:" << ptr->weight << endl;
			}
		}
		return os;
	}

};


class Graph {
private:
	int numVertices;
	vector<adjList>* array;
public:
	Graph() {
		this->numVertices = 0;
		this->array = new vector<adjList>;
	}

	~Graph() {
		delete[] array;
	}

	int findNumbCity(point polozenie) {
		for (int i = 0; i < numVertices; i++) {
			if (array->get(i).getMotherCity().coord == polozenie) {
				return i;
			}
		}
		return -1;
	}

	int findNumbCity(myString nameCity) {
		for (int i = 0; i < numVertices; i++) {
			if (array->get(i).getMotherCity().name == nameCity) {
				return i;
			}
		}
		return -1;
	}

	bool isBigger(ListNode* head, int dest, int weight) {
		ListNode* ptr = head;
		if (dest < 0)
		if (ptr != nullptr) {
			if (ptr->dest == dest) {
				if (weight < ptr->weight) {
					ptr->weight = weight;
					return false;
				}
				else {
					return false;
				}
			}
			else if (ptr->next == nullptr) {
				return true;
			}
			while (ptr->next != nullptr) {
				ptr = ptr->next;
				if (ptr->dest == dest) {
					if (weight < ptr->weight) {
						ptr->weight = weight;
						return false;
					}
					else {
						return false;
					}
				}
			}
			return true;
		}
		return true;
	}

	void addNode(city motherCity) {
		this->numVertices++;
		adjList city(motherCity);
		this->array->push(city);
	}

	void addEdge(Graph* graph, int src, int dest, int weight) {

		if (graph->array->getSize() > src && graph->array->getSize() > dest) {
			if (isBigger(graph->array->get(src).getHead(), dest, weight)) {
				graph->array->get(src).addNodeToList(dest, weight);
			}
			if (isBigger(graph->array->get(dest).getHead(), src, weight)) {
				graph->array->get(dest).addNodeToList(src, weight);
			}
		}
	}

	void addAirportEdge(Graph* graph, int src, int dest, int weight) {
		if (graph->array->getSize() > src && graph->array->getSize() > dest) {
			if (isBigger(graph->array->get(src).getHead(), dest, weight)) {
				graph->array->get(src).addNodeToList(dest, weight);
			}
		}
	}

	int getNumbVertices() { return numVertices; };

	vector<adjList>* getArray() { return array; };

	void print() {
		array->print();
	}
};




#endif