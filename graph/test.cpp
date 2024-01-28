#include <iostream>
#include <vector>

#include "graph.h"

struct Node {
	int value;
	std::vector<Node*> adj;
};

std::vector<Node*> get_next(const Node& u) {
	return u.adj;
};


int main(void) {
	const size_t N = 10;
	std::vector<Node> nodes;
	nodes.reserve(N);
	for (size_t i = 0; i < N; i++) {
		nodes.push_back(Node{ (int)i });
	}
	Node* prev = nullptr;
	for (auto ri = nodes.rend(); ri != nodes.rbegin(); ri++) {
		ri->adj.push_back(prev);
		prev = &(*ri);
	}
	
	std::vector<Node*>(*adj)(const Node & u) = get_next;

	struct cost {
		int operator()(graph::dijkstra_wrapper<Node>* u, graph::dijkstra_wrapper<Node>* v) { return 1; }
	} c;

	auto res = graph::dijkstra(nodes, 0, adj, c);

	return 0;
}