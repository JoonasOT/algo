#include <vector>
#include <unordered_map>

namespace graph {
	enum COLOR { WHITE, GRAY, BLACK }; 

	template<class T>
	struct dijkstra_wrapper {
		T* data;
		COLOR c = WHITE;
		long int dist = -1;
		dijkstra_wrapper* prev = nullptr;
	};
	template<class T>
	struct compare_wrappers {
		bool operator()(const dijkstra_wrapper* l, const dijkstra_wrapper* r) const {
			return l->dist > r->dist;	// > for a min PQ
		}
	};
	template<class T, class costF>
	std::unordered_map<T, dijkstra_wrapper<T>> dijkstra(const std::vector<T>& vertecies, const size_t& start_i, std::vector<T*> (*get_adj)(const T& u), costF& cost_func);
}