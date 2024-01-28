#include <iostream>
#include <queue>
#include "graph.h"

namespace graph {
	template<class T, struct costF, struct relax>
	std::unordered_map<T, dijkstra_wrapper> dijkstra(const std::vector<T>& vertecies,
										   const size_t& start_i,
										   int (*get_adj)(const T& u),
										   costF& cost_func,
										   relax& relax_func) {
		
		std::unordered_map<T, dijkstra_wrapper> graph;

		graph.reserve(vertecies.size());
		for ( const T& e : vertecies ) graph[e] = dijkstra_wrapper{&e};

		std::priority_queue<dijkstra_wrapper*, std::vector<dijkstra_wrapper*>, compare_wrappers> PQ;
		
		graph.at(start_i).dist = 0;
		graph.at(start_i).c = GRAY;
		PQ.push(&(graph.at(start_i)));

		while (!PQ.empty()) {
			dijkstra_wrapper* u = PQ.top(); PQ.pop();
			if (u->c == BLACK) continue;

			for (const auto& adj_p : get_adj(*u->data) {
				dijkstra_wrapper* v = &graph[adj_p];
				relax_func(u, v);
				if (v->c == WHITE) {
					v->c = GRAY;
					PQ.push(v);
				}
			}
			u->c = BLACK;
		}
	}
}