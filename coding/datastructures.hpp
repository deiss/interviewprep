#ifndef DS
#define DS

#include "sorts.hpp"
#include "util.hpp"

#include <iostream>
#include <vector>

using namespace std;

namespace datastructures {

class pqueue {
 public:
  pqueue(const vector<int>& a, bool maxqueue) : a(a), maxqueue(maxqueue) {
    build();
  }

  int left(int) const;
  int right(int) const;
  int parent(int) const;
  void heapify(int node) { heapify(node, a.size()); }
  void heapify(int, int);
  void build();
  int extract();
  void increase_key(int, int);
  void decrease_key(int, int);
  void insert(int);
  
  vector<int> a;
  const bool maxqueue;

  static void test_all() {
    pqueue q({1}, true);
    q.left(0); q.right(0); q.parent(0);
    q.heapify(0);
    q.extract();
    q.insert(1);
    q.increase_key(0, 2);
    q.decrease_key(0, 3);
  }

  bool test_extract() {
    auto sorted = a;
    sort(sorted.begin(), sorted.end(), [this](int lhs, int rhs) {
      if (this->maxqueue) return lhs > rhs;
      else return lhs < rhs;
    });
    for (int i = 0; i < sorted.size(); ++i) {
      auto res = extract();
      if (res != sorted[i]) {
        cout << endl;
        cout << "  Error: Got: " << res << "  Expected: " << sorted.at(i);
        cout << endl;
        return false;
      }
    }
    return true;
  }

  static bool test(
      const vector<int>& a, const bool maxqueue, const vector<int>& build,
      const vector<int>& increase_keys, const vector<int>& decrease_keys) {
    // Build.
    cout << "[b" << flush; pqueue q(a, maxqueue);
    if (q.a != build) {
      cout << endl;
      cout << "  Error: build()" << endl;
      cout << "  Got: "; print_vec(q.a);
      cout << "  Expected: "; print_vec(build);
      return false;
    }

    // Extract.
    cout << "e" << flush;
    q.test_extract();

    // Insert. Check with Extract.
    cout << "i" << flush;
    vector<int> inserts({1, 4, 6, 3439, 238, 49, 0, 2});
    pqueue q_inserts(a, maxqueue);
    for (int i = 0; i < inserts.size(); ++i) q_inserts.insert(inserts[i]);
    q_inserts.test_extract();

    // Increase-key
    cout << "+" << flush;
    pqueue q_increase(a, maxqueue);
    for (int i = 0; i < increase_keys.size(); ++i)
      q_increase.increase_key(i, q_increase.a[i] + increase_keys[i]);
    q_increase.test_extract();

    // Decrease-key
    cout << "-" << flush;
    pqueue q_decrease(a, maxqueue);
    for (int i = 0; i < decrease_keys.size(); ++i)
      q_decrease.decrease_key(i, q_decrease.a[i] - decrease_keys[i]);
    q_decrease.test_extract();

    cout << "] " << flush;
    return true;
  }
};

class bst {
 public:
  class node {
   public:
    node(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {}
    int key;
    node* left;
    node* right;
    node* parent;
  };

  bst(const vector<int>& a) : root(nullptr) { build(a); }

  void build(const vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
      insert(a[i]);
    }
  }

  node* search(int) const;
  node* vmin(node*) const;
  node* vmax(node*) const;
  node* successor(node*) const;
  node* predecessor(node*) const;
  node* insert(int);
  void del(node*);
  void walk(node*, vector<int>&) const;

  void walk(vector<int>& a) { walk(root, a); }
  node* vmax() { return vmax(root); }
  node* vmin() { return vmin(root); }

  node* root;

  static void test_all() {
    bst b({1});
    b.search(1);
    b.vmin(); b.vmax();
    b.successor(b.root); b.predecessor(b.root);
    b.del(b.root);
    vector<int> a;
    b.walk(a);
  }

  static bool test(const vector<int>& a) {
    // Build, insert.
    cout << "[b" << flush; bst b(a);
    vector<int> sorted;
    b.walk(sorted);
    if (!sorts::sorts::is_sorted(sorted, true)) {
      cout << endl;
      cout << "  Error: build()" << endl;
      cout << "  Got: "; print_vec(sorted);
      sort(sorted.begin(), sorted.end());
      cout << "  Expected: "; print_vec(sorted);
      return false;
    }

    // Search.
    cout << "s" << flush;
    for (int i = 0; i < a.size(); ++i) {
      auto answer = b.search(a[i]);
      if (answer == nullptr || answer->key != a[i]) {
        cout << endl;
        cout << "  Error: search()" << endl;
        cout << "  Could not find key: " << a[i] << ": ";
        answer == nullptr ? cout << "  (ans: nullptr)" :
                            cout << "  (key: " << answer->key << ")";
        cout << endl;
        vector<int> sorted;
        b.walk(sorted);
        print_vec(sorted);
        return false;
      }
    }

    // Vmax, Vmin.
    cout << "m" << flush;
    if (a.size() > 0 && b.vmax() == nullptr) {
      cout << endl;
      cout << "  Error: vmax()" << endl;
      cout << "  Returned nullptr from a non-empty tree." << endl;
      return false;
    } else if (a.size() > 0 &&
               b.vmax()->key != *max_element(a.begin(), a.end())) {
      cout << endl;
      cout << "  Error: vmax()" << endl;
      cout << "  Returned a value that is not the maximum." << endl;
      return false;
    }

    if (a.size() > 0 && b.vmin() == nullptr) {
      cout << endl;
      cout << "  Error: vmin()" << endl;
      cout << "  Returned nullptr from a non-empty tree." << endl;
      return false;
    } else if (a.size() > 0 &&
               b.vmin()->key != *min_element(a.begin(), a.end())) {
      cout << endl;
      cout << "  Error: vmin()" << endl;
      cout << "  Returned a value that is not the maximum." << endl;
      return false;
    }

    // Successor.
    cout << "x" << flush;
    vector<int> succ({1, -1, 39, 39, 3, 20, 3, 3, 17, 9, 0});
    bst b_succ(succ);
    node* node_39 = b_succ.search(39);
    node* succ_39 = b.successor(node_39);
    if (succ_39 != nullptr) {
      cout << endl;
      cout << "  Error: successor()" << endl;
      cout << "  Returned a non-null node for the successor of the maximum.";
      cout << endl;
      return false;
    }
    node* node_20 = b_succ.search(20);
    node* succ_20 = b.successor(node_20);
    if (succ_20 == nullptr || succ_20->key != 39) {
      cout << endl;
      cout << "  Error: successor()" << endl;
      cout << "  Did not return the successor." << endl;
      return false;
    }
    node* node_3 = b_succ.search(3);
    node* succ_3 = b.successor(node_3);
    if (succ_3 == nullptr || succ_3->key != 9) {
      cout << endl;
      cout << "  Error: successor()" << endl;
      cout << "  Did not return the successor." << endl;
      return false;
    }
    node* node_9 = b_succ.search(9);
    node* succ_9 = b.successor(node_9);
    if (succ_9 == nullptr || succ_9->key != 17) {
      cout << endl;
      cout << "  Error: successor()" << endl;
      cout << "  Did not return the successor." << endl;
      return false;
    }

    // Predecessor.
    cout << "p" << flush;
    node* node_0 = b_succ.search(-1);
    node* pred_0 = b.predecessor(node_0);
    if (pred_0 != nullptr) {
      cout << endl;
      cout << "  Error: predecessor()" << endl;
      cout << "  Returned a non-null node for the predecessor of the minimum.";
      cout << endl;
      return false;
    }
    node* pred_9 = b.predecessor(node_9);
    if (pred_9 == nullptr || pred_9->key != 3) {
      cout << endl;
      cout << "  Error: predecessor()" << endl;
      cout << "  Did not return the predecessor." << endl;
      return false;
    }
    node* node_1 = b_succ.search(1);
    node* pred_1 = b.predecessor(node_1);
    if (pred_1 == nullptr || pred_1->key != 0) {
      cout << endl;
      cout << "  Error: predecessor()" << endl;
      cout << "  Did not return the predecessor." << endl;
      return false;
    }

    // Delete.
    cout << "d" << flush;
    b_succ.del(b_succ.search(3));
    sorted.clear();
    b_succ.walk(sorted);
    if (sorted.size() != succ.size() - 1) {
      cout << endl;
      cout << "  Error: del()" << endl;
      int nb = succ.size() - sorted.size();
      cout << "  Deletion deleted " << nb << " nodes." << endl;
      return false;
    }
    if (!sorts::sorts::is_sorted(sorted, true)) {
      cout << endl;
      cout << "  Error: del()" << endl;
      cout << "  Got: "; print_vec(sorted);
      sort(sorted.begin(), sorted.end());
      cout << "  Expected: "; print_vec(sorted);
      return false;
    }
    b_succ.del(b_succ.search(3));
    sorted.clear();
    b_succ.walk(sorted);
    if (sorted.size() != succ.size() - 2) {
      cout << endl;
      cout << "  Error: del()" << endl;
      int nb = succ.size() - sorted.size() - 1;
      cout << "  Deletion deleted " << nb << " nodes." << endl;
      return false;
    }
    if (!sorts::sorts::is_sorted(sorted, true)) {
      cout << endl;
      cout << "  Error: del()" << endl;
      cout << "  Got: "; print_vec(sorted);
      sort(sorted.begin(), sorted.end());
      cout << "  Expected: "; print_vec(sorted);
      return false;
    }
    b_succ.del(b_succ.search(-1));
    sorted.clear();
    b_succ.walk(sorted);
    if (sorted.size() != succ.size() - 3) {
      cout << endl;
      cout << "  Error: del()" << endl;
      int nb = succ.size() - sorted.size() - 2;
      cout << "  Deletion deleted " << nb << " nodes." << endl;
      return false;
    }
    if (!sorts::sorts::is_sorted(sorted, true)) {
      cout << endl;
      cout << "  Error: del()" << endl;
      cout << "  Got: "; print_vec(sorted);
      sort(sorted.begin(), sorted.end());
      cout << "  Expected: "; print_vec(sorted);
      return false;
    }
    if (a.size() > 0) {
      bst b_del(a);
      b_del.del(b_del.search(a[rand() % a.size()])); 
      sorted.clear();
      b.walk(sorted);
      if (!sorts::sorts::is_sorted(sorted, true)) {
        cout << endl;
        cout << "  Error: del()" << endl;
        cout << "  Got: "; print_vec(sorted);
        sort(sorted.begin(), sorted.end());
        cout << "  Expected: "; print_vec(sorted);
        return false;
      }
    }

    cout << "] ";
    return true;
  }
};

struct node {
  int value;
  node* next;
  node(int v, node* n = nullptr) : value(v), next(n) {}
};

void ll_cycle(node*, int*, int*);

}

#endif

