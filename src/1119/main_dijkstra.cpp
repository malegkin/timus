#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include <algorithm>
#include <array>
#include <memory>
#include <cmath>
#include <vector>

using namespace std;

class Node {
    uint16_t    _x;
    uint16_t    _y;
    uint32_t    _hash;
    bool        _is_diag;
    public:
        Node(uint16_t x, uint16_t y):
            _x(x),
            _y(y),
            _hash(10*1000*x + y)
        {}

        inline uint32_t get_hash() const {
            return _hash;
        }

        friend bool operator<(const Node &lhs, const Node &rhs){
            return lhs.get_hash() < rhs.get_hash();
        }

        friend double operator-(const Node &lhs, const Node &rhs){
            if (!( rhs < lhs ))
                return 0;

//            if (lhs._x == 0 || lhs._y == 0 )
//                return 0;

            double out = 100.*(lhs._x - rhs._x + lhs._y - rhs._y);
            
            if (lhs._x != rhs._x && lhs._y != rhs._y)
                out -= 200. - sqrt(2*100*100);

            return out; 
        }

        std::string to_string() {
            return std::to_string( _hash );
        }
};


int main()
{
    uint16_t we; // west -> east
    uint16_t sn; // south -> north   
    uint16_t dc;  // diagonals count
    
    std::cin >> we >> sn >> dc;

//    uint8_t grid[1001][1001] = {};
//    uint8_t diagonally[1001][1001] = {};

    std::vector<Node> nodes;
    
    nodes.push_back( Node(0, 0) );
    nodes.push_back( Node(we + 1, sn + 1 ) );  
 
    while (dc--){
        uint16_t x,y;
        std::cin >>x >>y;
        if (x == 0 && y == 0)
            continue;
        nodes.push_back( Node(x,y) );
    }

    std::sort(std::begin(nodes), std::end(nodes));


    std::vector< std::vector< std::pair<size_t, double>>> g( nodes.size() );
    for (size_t i = 0; i < nodes.size(); i++){
        for (size_t j = i + 1; j < nodes.size(); j++){
            g[i].push_back( std::make_pair(j, nodes[j] - nodes[i] ));
        }
    }
    
/*
    for (size_t i = 0; i < g.size(); i++){
        std::cout << i << ":" << std::endl;
        for (auto a: g[i]){
            std::cout << "\t" << i << " - " << a.first << " - " << a.second << std::endl;
        }
    }
*/
    size_t n = nodes.size();
    vector<double> d (n, std::numeric_limits<double>::max() );
    vector<int>  p (n);
	d[0] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == std::numeric_limits<double>::max())
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first;
			double len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
/*
    vector<int> path;
    for (int v=t; v!=s; v=p[v])
	    path.push_back (v);
    path.push_back (s);
    reverse (path.begin(), path.end());
*/
    std::cout << round(d[n-1] - sqrt(2*100*100)) << std::endl;
    
    return 0;

    uint32_t costs[102][102] = {};
    for (size_t i = 0; i < nodes.size(); i++){
        for (size_t j = 0; j < nodes.size(); j++){
            costs[i][j] = nodes[i] - nodes[j];
        }
    }
    
/*
    for (size_t i = 0; i < 102; i++){
        for (size_t j = 0; j < 102; j++){
            std::cout << costs[i][j] << "\t";
        }
            std::cout << std::endl;
    }
*/
/*
    bool visited[102];
    uint32_t r[102];

    for (size_t i = 0; i < 102; i++){
        visited[i] = false;
        r[i] = costs[0][i];
    }


    size_t index=0,u=0;
    for (int i=0; i < n; i++)
    {
        int min=INT_MAX;
        for (int j=0; j < n; j++)
        {
            if (!visited[j] && r[j] < min)
            {
                min = r[j]; 
                index = j;
            }
        }

        u=index;
        visited[u]=true;
        for(int j=0;j<n;j++)
        {
            if (!visited[j] && costs[u][j] != INT_MAX && r[u] != INT_MAX && (r[u] + costs[u][j] < r[j]))
            {
                r[j] = r[u] + costs[u][j];
            }
        }
    }

    std::cout << r[n-1] <<std::endl;
*/
//    for(auto a: nodes){
//        std::cout << a.to_string( ) << std::endl; 
//    }
    
    
    
    return 0;
}
