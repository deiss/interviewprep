#ifndef UTIL
#define UTIL

#include <iostream>
#include <vector>

using namespace std;

class not_implemented_exc : public exception {
 public:
  not_implemented_exc() {}
  virtual ~not_implemented_exc() {}
  virtual const char* what() const throw() {
    return "Function not implemented.";
  }

 private:
  
};

template<typename T>
void print_vec(const vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
  cout << endl;
}

template<typename T>
void print_pqueue(const vector<T>& a) {
  int count = 1;
  int stage = 1;
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
    if (i + 1 == count) {
      cout << endl;
      count += 2*stage;
      stage *= 2;
    }
  }
  cout << endl;
}

#endif

