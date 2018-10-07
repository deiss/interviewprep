#include "datastructures.hpp"
#include "graphs.hpp"
#include "math.hpp"
#include "arrays.hpp"
#include "sorts.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

// *****************************************************************************
// ******************************** Sorting ************************************
// *****************************************************************************

// Selection Sort.
void sorts::selection_sort::sort(vector<int>& a, bool increasing) const {
  throw not_implemented_exc();
}

// Insertion Sort.
void sorts::insertion_sort::sort(vector<int>& a, bool increasing) const {
  throw not_implemented_exc();
}

// Quick Sort.
void sorts::quick_sort::sort(vector<int>& a, bool increasing) const {
  throw not_implemented_exc();
}

// Heap Sort.
void sorts::heap_sort::sort(vector<int>& a, bool increasing) const {
  throw not_implemented_exc();
}

// Counting Sort.
vector<int> sorts::counting_sort::sort(
    const vector<int>& a, bool increasing) const {
  throw not_implemented_exc();
}

// Radix Sort.
vector<int> sorts::radix_sort::sort(
    const vector<int>& a, bool increasing) const {
  throw not_implemented_exc();
}

// Merge Sort.
vector<int> sorts::merge_sort::sort(
    const vector<int>& a, bool increasing) const {
  throw not_implemented_exc();
}


// *****************************************************************************
// ***************************** Data Structures *******************************
// *****************************************************************************

// Priority Queue.
// Variables: a, maxqueue.
int datastructures::pqueue::left(int node) const {
  throw not_implemented_exc();
}

int datastructures::pqueue::right(int node) const {
  throw not_implemented_exc();
}

int datastructures::pqueue::parent(int node) const {
  throw not_implemented_exc();
}

// Try Left, then Right for tests purposes.
void datastructures::pqueue::heapify(int node, int size) {
  throw not_implemented_exc();
}

void datastructures::pqueue::build() {
  throw not_implemented_exc();
}

void datastructures::pqueue::insert(int key) {
  throw not_implemented_exc();
}

int datastructures::pqueue::extract() {
  throw not_implemented_exc();
}

void datastructures::pqueue::increase_key(int node, int new_key) {
  throw not_implemented_exc();
}

void datastructures::pqueue::decrease_key(int node, int new_key) {
  throw not_implemented_exc();
}


// Binary Search Tree.
// Variables: root, key, left, right, parent.
datastructures::bst::node* datastructures::bst::search(int key) const {
  throw not_implemented_exc();
}

datastructures::bst::node* datastructures::bst::vmin(node* start) const {
  throw not_implemented_exc();
}

datastructures::bst::node* datastructures::bst::vmax(node* start) const {
  throw not_implemented_exc();
}

datastructures::bst::node* datastructures::bst::successor(node* start) const {
  throw not_implemented_exc();
}

datastructures::bst::node*
datastructures::bst::predecessor(node* start) const {
  throw not_implemented_exc();
}

datastructures::bst::node* datastructures::bst::insert(int key) {
  throw not_implemented_exc();
}

void datastructures::bst::del(node* start) {
  throw not_implemented_exc();
}

void datastructures::bst::walk(node* start, vector<int>& sorted) const {
  throw not_implemented_exc();
}

// Variables: next.
void datastructures::ll_cycle(node* start, int* mu, int* lambda) {
  throw not_implemented_exc();
}

// *****************************************************************************
// *********************************** Math ************************************
// *****************************************************************************

int math::gcd(int a, int b) {
  throw not_implemented_exc();
}

int math::selection(vector<int>& a, int i) {
  throw not_implemented_exc();
}

set<string> math::subsets(const string& letters) {
  throw not_implemented_exc();
}

set<string> math::permutations(const string& letters) {
  throw not_implemented_exc();
}

bool math::is_prime(long long int nb) {
  throw not_implemented_exc();
}

int math::kmp(const string& pattern, const string& text) {
  throw not_implemented_exc();
}


// *****************************************************************************
// ******************************** Arrays *************************************
// *****************************************************************************

int arrays::kadane(const vector<int>& a) {
  throw not_implemented_exc();
}

bool arrays::binsearch(const vector<int>& a, int key) {
  throw not_implemented_exc();
}

// Variables: first: x, second: y. You can assume each x value is unique.
double arrays::closest_points(const vector<pair<double, double>>& points) {
  throw not_implemented_exc();
}

void arrays::fisher_yates(vector<int>& a) {
  throw not_implemented_exc();
}


// *****************************************************************************
// ******************************** Graphs *************************************
// *****************************************************************************

// Variables: vertices, edges, v1, v2, cost, value, neighs.
vector<graphs::vertex*> graphs::graph::topo_sort(bool* has_cycle) {
  throw not_implemented_exc();
}

// Variables: vertices, edges, v1, v2, cost, value, neighs.
bool graphs::graph::two_coloring() {
  throw not_implemented_exc();
}

// Functions: edgebet(v1, v2) returns edge that links v1 and v2.
// Variables: vertices, edges, v1, v2, cost, value, neighs.
vector<graphs::edge*> graphs::graph::prim() {
  throw not_implemented_exc();
}

// Variables: vertices, edges, v1, v2, cost, value, neighs.
vector<int> graphs::graph::dfs(vertex* start) {
  throw not_implemented_exc();
}

// Variables: vertices, edges, v1, v2, cost, value, neighs.
vector<int> graphs::graph::bfs(vertex* start) {
  throw not_implemented_exc();
}

// Variables: edgeat[v1][v2] v1 --> v2.
vector<vector<int>> graphs::graph::floyd_warshall() {
  throw not_implemented_exc();
}

vector<vector<graphs::vertex*>>
graphs::graph::biconnected_components(vertex* start, set<int>& apoints) const {
  throw not_implemented_exc();
}
