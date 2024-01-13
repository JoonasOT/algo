#include <iostream>
#include <queue>
#include "graph.h"

namespace graph {
	template<class T, struct costF>
	std::vector<dijkstra_wrapper> dijkstra(const std::vector<T>& vertecies, const size_t& start_i, costF& cost_func) {
		
		std::vector<dijkstra_wrapper> graph;
		graph.reserve(vertecies.size());
		for ( const T& e : vertecies ) graph.push_back(dijkstra_wrapper{&e});

		std::priority_queue<*dijkstra_wrapper> PQ;
		
		graph.at(start_i).dist = 0;
		graph.at(start_i).c = GRAY;
		PQ.push(&(graph.at(start_i)));


	}
}