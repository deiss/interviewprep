#ifndef MATHS
#define MATHS

#include <cmath>
#include <set>

namespace math {

int gcd(int, int);
int selection(vector<int>&, int);
set<string> subsets(const string&);
set<string> permutations(const string&);
bool is_prime(long long int);
int kmp(const string&, const string&);  // TODO: move into strings.

}

#endif
