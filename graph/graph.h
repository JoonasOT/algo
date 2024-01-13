#include <vector.h>

namespace graph {
	enum COLOR { WHITE, GRAY, BLACK }; 

	template<class T>
	struct dijkstra_wrapper {
		T* data;
		COLOR c = WHITE;
		long int dist = -1;
		dijkstra_wrapper* prev = nullptr;
	};

	template<class T, struct costF>
	std::vector<dijkstra_wrapper> dijkstra(const std::vector<T>& vertecies, const size_t& start_i, costF& cost_func);
}