#pragma once

#include <iostream>
#include "Ticket6.h"
#include "Ticket7.h"
#include "Ticket16.h"
#include "Ticket17.h"
#include "graphs.h"

using namespace std;

int main()
{
	Ticket6 ticket6;
	ticket6.findConnectedComponents(ticket6_test2);

	Ticket7 ticket7;
	ticket7.topological_sort(ticket7_test3);

	Ticket16 ticket16;
	ticket16.Kruskal(ticket16_test3);

	Ticket17 ticket17;
	ticket17.Prim(ticket16_test3);

}
