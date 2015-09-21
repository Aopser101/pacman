#ifndef PATHFINDING_H_INCLUDED
#define PATHFINDING_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

int heuristic(node a, node b){
    return abs(a.xPos-b.xPos)+abs(a.yPos-b.yPos);
}

template <typename T>
struct Graph{
    typedef tuple<int,int> Location;

    unordered_set<Location>Walls;

    Graph(int width_, int height_):width(width_), height(height_){}

    int width, height;

    inline bool in_bounds(Location id){
        int x,y;
        tie(x,y)=id;
        return 0<=x<width && 0<=y<height;
    }
    
    inline bool passable(Location id){
        return !walls.count(id);
    }

};



#endif // PATHFINDING_H_INCLUDED
};



#endif // PATHFINDING_H_INCLUDED

