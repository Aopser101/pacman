#ifndef PATHFINDING_H_INCLUDED
#define PATHFINDING_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

template <typename T>
struct Graph{
	typedef tuple<int, int> Location;
	static array<Location, 4> DIRS;

	unordered_set<Location>Walls;

	int width, height;
	Graph(int width_, int height_) :width(width_), height(height_){}

	inline bool in_bounds(Location id){
		int x, y;
		tie(x, y) = id;
		return 0 <= x<width && 0 <= y<height;
	}

	inline bool passable(Location id){
		return !walls.count(id);
	}

	vector<Location> neighbors(Location id){
		int x, y, dx, dy;
		tie(x, y) = id;
		bool possible;
		vector<Location> results;
		for (auto dir : DIRS) {
			tie(dx, dy) = dir;
			Location next(x + dx, y + dy);
			if (in_bounds(next) && passable(next)) {
				results.push_back(next);
			}
		}
		if ((x + y) % 2 == 0) {
			// aesthetic improvement on square grids
			std::reverse(results.begin(), results.end());
		}
		return results;
	}
};

array<Graph::Location, 4> Graph::DIRS{ Graph::Location{ 1, 0 }, Graph::Location{ 0, -1 }, Graph::Location{ -1, 0 }, Graph::Location{ 0, 1 } };


inline int heuristic(Graph::Location a, Graph::Location b) {
	int x1, y1, x2, y2;
	tie(x1, y1) = a;
	tie(x2, y2) = b;
	return abs(x1 - x2) + abs(y1 - y2);
}

template<typename T, typename Number = int>
struct PriorityQueue {
	typedef pair<Number, T> PQElement;
	priority_queue<PQElement, vector<PQElement>,
		std::greater<PQElement >> elements;

	inline bool empty() { return elements.empty(); }

	inline void put(T item, Number priority) {
		elements.emplace(priority, item);
	}

	inline T get() {
		T best_item = elements.top().second;
		elements.pop();
		return best_item;
	}
};

template<typename Graph>
void a_star_search
(Graph graph,
typename Graph::Location start,
typename Graph::Location goal,
unordered_map<typename Graph::Location, typename Graph::Location>& came_from,
unordered_map<typename Graph::Location, int>& cost_so_far)
{
	typedef typename Graph::Location Location;
	PriorityQueue<Location> frontier;
	frontier.put(start, 0);

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		auto current = frontier.get();

		if (current == goal) {
			break;
		}

		for (auto next : graph.neighbors(current)) {
			int new_cost = cost_so_far[current] + graph.cost(current, next);
			if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				int priority = new_cost + heuristic(next, goal);
				frontier.put(next, priority);
				came_from[next] = current;
			}
		}
	}
}

#endif // PATHFINDING_H_INCLUDED
