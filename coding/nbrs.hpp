#ifndef NBRS
#define NBRS

#include <set>

namespace nbrs {

int gcd(int, int);
int selection(vector<int>&, int);
set<string> subsets(const string&);
set<string> permutations(const string&);
int kadane(const vector<int>&);
bool binsearch(const vector<int>&, int);
int kmp(const string&, const string&);

}

#endif

