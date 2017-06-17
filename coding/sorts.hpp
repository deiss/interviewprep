#ifndef SORTS
#define SORTS

#include "util.hpp"

#include <iostream>
#include <vector>

using namespace std;

namespace sorts {

// Base classes.
class sorts {
 public:
  static bool is_sorted(const vector<int>& a, bool increasing) {
    for (int i = 1; i < a.size(); ++i) {
      if (increasing && a.at(i) < a.at(i-1)) return false;
      if (!increasing && a.at(i) > a.at(i-1)) return false;
    }
    return true;
  }
};

class in_place_sort : public sorts {
 public:
  virtual void sort(vector<int>&, bool = true) const = 0;

  bool test(vector<int>& a, bool increasing) const {
    auto prev_size = a.size();
    sort(a, increasing);
    if (prev_size != a.size()) {
      cout << endl;
      cout << "  Error: sorted vector has different size." << endl;
      return false;
    }
    if (!is_sorted(a, increasing)) {
      cout << endl;
      cout << "  Error (not sorted): "; print_vec(a);
      return false;
    }
    return true;
  }
};

class outta_place_sort : public sorts {
 public:
  virtual vector<int> sort(const vector<int>&, bool = true) const = 0;

  bool test(const vector<int>& a, bool increasing) const {
    auto sorted = sort(a, increasing);
    if (sorted.size() != a.size()) {
      cout << endl;
      cout << "  Error: sorted vector has different size:" << endl;
      cout << "  Sorted:   "; print_vec(sorted);
      cout << "  Unsorted: "; print_vec(a);
      return false;
    }
    if (!is_sorted(sorted, increasing)) {
      cout << endl;
      cout << "  Error (not sorted): "; print_vec(sorted);
      return false;
    }
    return true;
  }
};


// In place sorts.
class selection_sort : public in_place_sort {
 public:
  virtual void sort(vector<int>&, bool = true) const;
};

class insertion_sort : public in_place_sort {
 public:
  virtual void sort(vector<int>&, bool = true) const;
};

class quick_sort : public in_place_sort {
 public:
  virtual void sort(vector<int>&, bool = true) const;
};

class heap_sort : public in_place_sort {
 public:
  virtual void sort(vector<int>&, bool = true) const;
};


// Out of place sorts.
class counting_sort : public outta_place_sort {
 public:
  virtual vector<int> sort(const vector<int>&, bool = true) const;
};

class radix_sort : public outta_place_sort {
 public:
  virtual vector<int> sort(const vector<int>&, bool = true) const;
};

class merge_sort : public outta_place_sort {
 public:
  virtual vector<int> sort(const vector<int>&, bool = true) const;
};

}

#endif

