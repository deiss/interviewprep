#ifndef GRAPH
#define GRAPH

#include <map>
#include <set>

using namespace std;

namespace graphs {

class vertex {
 public:
  vertex(int v) : value(v) {}

  int value;
  vector<vertex*> neighs;
};

class edge {
 public:
  edge(vertex* v1, vertex* v2, int cost) : v1(v1), v2(v2), cost(cost) {}

  vertex* v1;
  vertex* v2;
  int cost;
};


class graph {
 public:

  graph() : edgeat(10, vector<edge*>(10)) {}

  vector<vertex*> topo_sort(bool*);
  vector<edge*> prim();
  bool two_coloring();
  vector<int> dfs(vertex*);
  vector<int> bfs(vertex*);
  vector<vector<int>> floyd_warshall();
  vector<vector<graphs::vertex*>> biconnected_components(
      vertex*, set<int>&) const;
  vector<vector<graphs::vertex*>> scc() const;

  static graph build_graph(bool directed, bool add_cycle = false,
                           bool remove_2_6 = false, bool make_scc = false) {
    graph g;

    vertex* v1 = g.add_vertex(1); vertex* v2 = g.add_vertex(2);
    vertex* v3 = g.add_vertex(3); vertex* v4 = g.add_vertex(4);
    vertex* v5 = g.add_vertex(5); vertex* v6 = g.add_vertex(6);
    vertex* v7 = g.add_vertex(7); vertex* v8 = g.add_vertex(8);
    vertex* v9 = g.add_vertex(9); vertex* v10 = g.add_vertex(10);

    g.connect(v1, v2, 4, directed);
    if (!remove_2_6) g.connect(v2, v6, 2, directed);
    if (make_scc) g.connect(v3, v1, 5, directed);
    if (make_scc) g.connect(v10, v6, 6, directed);
    g.connect(v2, v5, 2, directed); g.connect(v2, v4, 1, directed);
    g.connect(v2, v3, 9, directed); g.connect(v3, v7, 2, directed);
    g.connect(v5, v7, 2, directed); g.connect(v6, v9, 3, directed);
    g.connect(v6, v8, 7, directed); g.connect(v8, v10, 2, directed);
    g.connect(v8, v7, 2, directed); g.connect(v9, v10, 2, directed);
    g.connect(v9, v7, 2, directed);

    if (add_cycle) {
      g.connect(v10, v8, 7, directed);
    }

    return g;
  }

  int cost(vertex* v1, vertex* v2) {
    auto e = edgebet(v1, v2);
    return e != nullptr ? e->cost : 0;
  }

  edge* edgebet(vertex* v1, vertex* v2, bool directed = false) {
    auto e1 = edgeat[vert2int[v1]][vert2int[v2]];
    if (directed) {
      return e1;
    }
    auto e2 = edgeat[vert2int[v2]][vert2int[v1]];
    return e1 != nullptr ? e1 : e2;
  }

  vertex* add_vertex(int value) {
    vertex* v = new vertex(value);
    vertices.push_back(v);
    vert2int.insert(make_pair(v, counter++));
    return v;
  }

  // If directed: v1 --> v2 (v2 doesn't see v1)
  void connect(vertex* v1, vertex* v2, int cost, bool directed = false) {
    edge* e = new edge(v1, v2, cost);
    edges.push_back(e);
    edgeat[vert2int[v1]][vert2int[v2]] = e;
    auto needv1 = true;
    for (int i = 0; i < v1->neighs.size(); ++i) {
      if (v1->neighs[i] == v2) {
        needv1 = false;
        break;
      }
    }
    if (needv1) v1->neighs.push_back(v2);
    if (!directed) {
      edgeat[vert2int[v2]][vert2int[v1]] = e;
      auto needv2 = true;
      for (int i = 0; i < v2->neighs.size(); ++i) {
        if (v2->neighs[i] == v1) {
          needv2 = false;
          break;
        }
      }
      if (needv2) v2->neighs.push_back(v1);
    }
  }

  vector<vertex*> vertices;
  vector<edge*> edges;
  vector<vector<edge*>> edgeat;
  map<vertex*, int> vert2int;

 private:
  int counter = 0;
};

}

#endif
