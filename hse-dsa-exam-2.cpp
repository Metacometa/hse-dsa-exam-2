#pragma once

#include <iostream>
#include "Ticket6.h"
#include "Ticket7.h"
#include "Ticket11.h"
#include "Ticket16.h"
#include "Ticket17.h"
#include "Ticket18.h"
#include "graphs.h"

using namespace std;

int main()
{
	Ticket6 ticket6;
	ticket6.findConnectedComponents(ticket6_test2);

	Ticket7 ticket7;
	ticket7.topological_sort(ticket7_test3);

	Ticket11 ticket11;
	ticket11.Dijkstra(dijkstra_test2, 1, 7);

	Ticket16 ticket16;
	ticket16.Kruskal(mst_test3);

	Ticket17 ticket17;
	ticket17.Prim(mst_test3);

	Ticket18 ticket18;
	ticket18.Boruvka(mst_test3);


}
