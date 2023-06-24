#pragma once

#include <iostream>
#include "Ticket4.h"
#include "Ticket6.h"
#include "Ticket7.h"
#include "Ticket8.h"

#include "Ticket9.h"
#include "Ticket10.h"
#include "Ticket11.h"
#include "Ticket12.h"
#include "Ticket13.h"

#include "Ticket16.h"
#include "Ticket17.h"
#include "Ticket18.h"
#include "graphs.h"

using namespace std;

int main()
{
	Ticket4 ticket4;
	ticket4.PrefixSumMatrix(ticket4_test2, 1, 1, 2, 2);

	Ticket6 ticket6;
	ticket6.findConnectedComponents(ticket6_test2);

	Ticket7 ticket7;
	ticket7.topological_sort(ticket7_test3);

	Ticket8 ticket8;
	ticket8.findStronglyConnectedComponents(ticket8_test1);

	Ticket9 ticket9;
	ticket9.findBridges(ticket9_test2);

	Ticket10 ticket10;
	ticket10.findArticulationPoints(ticket9_test2);

	Ticket11 ticket11;
	ticket11.findEulerianCircuit(ticket11_test1);

	Ticket12 ticket12;
	ticket12.Dijkstra(dijkstra_test2, 1, 7);

	Ticket13 ticket13;
	ticket13.BellmanFord(bellman_ford_test1, 1, 4);

	Ticket16 ticket16;
	ticket16.Kruskal(mst_test3);

	Ticket17 ticket17;
	ticket17.Prim(mst_test3);

	Ticket18 ticket18;
	ticket18.Boruvka(mst_test3);


}
