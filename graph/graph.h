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
	struct compare_wrappers {
		bool operator()(const dijkstra_wrapper* l, const dijkstra_wrapper* r) const {
			return l->dist > r->dist;	// > for a min PQ
		}
	};
	template<class T, struct costF, struct relax>
	std::unordered_map<T, dijkstra_wrapper> dijkstra(const std::vector<T>& vertecies, const size_t& start_i, int (*get_adj)(const T& u), costF& cost_func, relax& relax_func);
}