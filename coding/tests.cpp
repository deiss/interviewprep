#include "datastructures.hpp"
#include "graphs.hpp"
#include "math.hpp"
#include "arrays.hpp"
#include "sorts.hpp"
#include "tests.hpp"

#include <set>
#include <vector>

namespace sorts {

bool test_in_place_sort(const in_place_sort& s, bool increasing) {
  vector<int> a1({1, 39, 39, 3, 20, 3, 3, 17, 9, 0, 0});
  vector<int> a2({9, 540, 1, 29, 0, 28, 3, 57, 5, 5, 5, 5});
  vector<int> a3({1});
  vector<int> a4({});

  int wrong = 0;
  increasing ? cout << "(increasing) " : cout << "(decreasing) ";
  cout << "1... " << flush; if (!s.test(a1, increasing)) wrong++;
  cout << "2... " << flush; if (!s.test(a2, increasing)) wrong++;
  cout << "3... " << flush; if (!s.test(a3, increasing)) wrong++;
  cout << "4... " << flush; if (!s.test(a4, increasing)) wrong++;
  if (wrong == 0) cout << "OK";

  cout << endl;
  return wrong == 0;
}

bool test_outta_place_sort(const outta_place_sort& s, bool increasing) {
  vector<int> a1({1, 39, 39, 3, 20, 3, 3, 17, 9, 0, 0});
  vector<int> a2({9, 540, 1, 29, 0, 28, 3, 57, 5, 5, 5, 5});
  vector<int> a3({1});
  vector<int> a4({});

  int wrong = 0;
  increasing ? cout << "(increasing) " : cout << "(decreasing) ";
  cout << "1... " << flush; if (!s.test(a1, increasing)) wrong++;
  cout << "2... " << flush; if (!s.test(a2, increasing)) wrong++;
  cout << "3... " << flush; if (!s.test(a3, increasing)) wrong++;
  cout << "4... " << flush; if (!s.test(a4, increasing)) wrong++;
  if (wrong == 0) cout << "OK";

  cout << endl;
  return wrong == 0;
}

void run_tests() {
  int wrong = 0;
  int nb = 7;
  int total = nb;

  cout << "** SORTS **" << endl;

  // In place sorts.
  try {
    vector<int> test({});
    selection_sort().sort(test);
    cout << "[TEST: Selection sort]" << endl;
    if (!test_in_place_sort(selection_sort(), true) ||
        !test_in_place_sort(selection_sort(), false)) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    vector<int> test({});
    insertion_sort().sort(test);
    cout << endl << "[TEST: Insertion sort]" << endl;
    if (!test_in_place_sort(insertion_sort(), true) ||
        !test_in_place_sort(insertion_sort(), false)) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    vector<int> test({});
    quick_sort().sort(test);
    cout << endl << "[TEST: Quick sort]" << endl;
    if (!test_in_place_sort(quick_sort(), true) ||
        !test_in_place_sort(quick_sort(), false)) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    vector<int> test({});
    heap_sort().sort(test);
    cout << endl << "[TEST: Heap sort]" << endl;
    if (!test_in_place_sort(heap_sort(), true) ||
        !test_in_place_sort(heap_sort(), false)) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  // Out of place sorts.
  try {
    vector<int> test({});
    counting_sort().sort(test);
    cout << endl << "[TEST: Counting sort]" << endl;
    if (!test_outta_place_sort(counting_sort(), true) ||
        !test_outta_place_sort(counting_sort(), false)) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    vector<int> test({});
    radix_sort().sort(test);
    cout << endl << "[TEST: Radix sort]" << endl;
    if (!test_outta_place_sort(radix_sort(), true) ||
        !test_outta_place_sort(radix_sort(), false)) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    vector<int> test({});
    merge_sort().sort(test);
    cout << endl << "[TEST: Merge sort]" << endl;
    if (!test_outta_place_sort(merge_sort(), true) ||
        !test_outta_place_sort(merge_sort(), false)) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  cout << "Executed " << total << " out of " << nb << " tests. ";
  cout << (total - wrong) << "/" << total << " tests pass." << endl;
}

}

namespace datastructures {

bool test_pqueue() {
  int wrong = 0;
  cout << "  (max)" << endl << "    1: ";
  if (!pqueue::test({1, 39, 39, 3, 20, 3, 3, 17, 9, 0, 0}, true,
                    {39, 20, 39, 17, 1, 3, 3, 3, 9, 0, 0},
                    {0, 0, 0, 40, 0, 0, 0, 100, 0, 200, 0},
                    {0, 0, 0, 40, 0, 0, 0, 100, 0, 200, 0})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "    2: ";
  if (!pqueue::test({9, 540, 1, 29, 0, 28, 3, 57, 5, 5, 5, 5}, true,
                    {540, 57, 28, 29, 5, 5, 3, 9, 5, 0, 5, 1},
                    {0, 0, 0, 600, 700, 800, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 600, 700, 800, 0, 0, 0, 0, 0, 0})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "    3: ";
  if (!pqueue::test({1}, true, {1}, {4}, {4})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "    4: ";
  if (!pqueue::test({}, true, {}, {}, {})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;

  cout << "  (min)" << endl << "    1: ";
  if (!pqueue::test({1, 39, 39, 3, 20, 3, 3, 17, 9, 0, 0}, false,
                    {0, 0, 3, 3, 1, 39, 3, 17, 9, 20, 39},
                    {21, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {21, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "    2: ";
  if (!pqueue::test({9, 540, 1, 29, 0, 28, 3, 57, 5, 5, 5, 5}, false,
                    {0, 5, 1, 9, 5, 5, 3, 57, 29, 540, 5, 28},
                    {700, 0, 60, 0, 0, 99, 0, 0, 0, 0, 0},
                    {700, 0, 60, 0, 0, 99, 0, 0, 0, 0, 0})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "    3: ";
  if (!pqueue::test({1}, false, {1}, {4}, {4})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "    4: ";
  if (!pqueue::test({}, false, {}, {}, {})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;

  return wrong == 0;
}

bool test_bst() {
  int wrong = 0;

  cout << "  1: ";
  if (!bst::test({1, 39, 39, 3, 20, 3, 3, 17, 9, 0})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "  2: ";
  if (!bst::test({9, 540, 1, 29, 0, 28, 3, 57, 5, 5})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "  3: ";
  if (!bst::test({1})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;
  cout << "  4: ";
  if (!bst::test({})) {
    wrong++;
    cout << "FAIL" << endl;
  } else cout << "OK" << endl;

  return wrong == 0;
}

bool test_ll_cycle() {
  node* tail = new node(6);
  node* h1 = new node(10, new node(5, new node(7, new node(7, tail))));
  tail->next = h1;
  node* h2 = new node(7, new node(8, new node(4, new node(6, h1))));
  int mu, lambda;
  ll_cycle(h2, &mu, &lambda);
  if (mu != 4 || lambda != 5) {
    cout << "  Error: ll_cycle()" << endl;
    cout << "  Wrong length (" << lambda << ")";
    cout << " or position of the cycle (" << mu << ")" << endl;
    return false;
  }
  return true;
}

void run_tests() {
  int wrong = 0;
  int nb = 3;
  int total = nb;

  cout << endl << "** DATA STRUCTURES **" << endl;

  try {
    pqueue::test_all();
    cout << endl << "[TEST: Priority Queue]" << endl;
    if (!test_pqueue()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    bst::test_all();
    cout << endl << "[TEST: Binary Search Tree]" << endl;
    if (!test_bst()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    int mu, lambda; ll_cycle(nullptr, &mu, &lambda);
    cout << endl << "[TEST: Linked List Cycle]" << endl;
    if (!test_ll_cycle()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  cout << "Executed " << total << " out of " << nb << " tests. ";
  cout << (total - wrong) << "/" << total << " tests pass." << endl;
}

}

namespace math {

bool test_gcd() {
  auto display_error = [](int a, int b, int r) {
    cout << endl;
    cout << "  Error: GCD(" << a << ", " << b << ") = " << r;
    cout << " (found " << gcd(a, b) << ").";
    cout << endl;
  };
  if (gcd(24, 20) != 4) {
    display_error(24, 20, 4);
    return false;
  }
  if (gcd(14, 7) != 7) {
    display_error(14, 7, 7);
    return false;
  }
  if (gcd(3, 6) != 3) {
    display_error(3, 6, 3);
    return false;
  }
  if (gcd(6, 8) != 2) {
    display_error(6, 8, 2);
    return false;
  }
  if (gcd(8, 6) != 2) {
    display_error(8, 6, 2);
    return false;
  }
  return true;
}

bool test_selection() {
  for (int i = 0; i < 9; ++i) {
    vector<int> a({2, 9, 10, 3, 2, 52, 190, 93, 3});
    vector<int> sorted = a; sort(sorted.begin(), sorted.end());
    if (selection(a, i + 1) != sorted.at(i)) {
        cout << endl;
        cout << "  Error: selection()" << endl;
        cout << "  Did not select the right number" << endl;
        return false;
    }
  }
  return true;
}

bool test_subsets() {
  auto ssets = subsets("12345");
  if (ssets.size() != 32) {
    cout << endl;
    cout << "  Error: subsets()" << endl;
    cout << "  Did not return the right number of subsets ";
    cout << "(" << ssets.size() << ")" << endl;
    return false;
  }
  return true;
}

bool test_permutations() {
  auto perms = permutations("12345");
  if (perms.size() != 120) {
    cout << endl;
    cout << "  Error: permutations()" << endl;
    cout << "  Did not return the right number of permutations ";
    cout << "(" << perms.size() << ")" << endl;
    return false;
  }
  return true;
}

bool test_kmp() {
  if (kmp("ABCDABD", "ABC ABCDAB ABCDABCDABDE") != 1) {
    cout << endl;
    cout << "  Error: KMP()" << endl;
    cout << "  Did not find the right number of matches" << endl;
    return false;
  }
  if (kmp("ABA",
          "ABACBCBABABBABCBBCBABCBABCBABABABCBBABCBABABABCBCBABCABA") != 7) {
    cout << endl;
    cout << "  Error: KMP()" << endl;
    cout << "  Did not find the right number of matches" << endl;
    return false;
  }
  return true;
}

bool test_is_prime() {
  vector<long long int> composites = {
      1299722, 1300074, 1300425, 1300753,
      1299747, 1300099, 1300427, 1300772,
      1299765, 1300113, 1300437, 1300775,
      1299793, 1300128, 1300452, 1300783,
      1299814, 1300131, 1300459, 1300817,
      1299819, 1300135, 1300467, 1300831,
      1299822, 1300140, 1300473, 1300839,
      1299829, 1300143, 1300481, 1300844,
      1299837, 1300149, 1300489, 1300847,
      1299843, 1300157, 1300503, 1300911,
      1299861, 1300182, 1300512, 1300922,
  };
  vector<long long int> primes = {
      1299721, 1300073, 1300421, 1300751,
      1299743, 1300097, 1300423, 1300769,
      1299763, 1300111, 1300433, 1300771,
      1299791, 1300127, 1300451, 1300781,
      1299811, 1300129, 1300457, 1300813,
      1299817, 1300133, 1300463, 1300829,
      1299821, 1300139, 1300471, 1300837,
      1299827, 1300141, 1300477, 1300841,
      1299833, 1300147, 1300487, 1300843,
      1299841, 1300153, 1300501, 1300907,
      1299853, 1300181, 1300511, 1300921,
  };
  for (auto p: composites) {
    if (is_prime(p)) {
      cout << endl;
      cout << "  Error: is_prime()" << endl;
      cout << "  Classified " << p << " as prime (it is composite)" << endl;
      return false;
    }
  }
  for (auto p: primes) {
    if (!is_prime(p)) {
      cout << endl;
      cout << "  Error: is_prime()" << endl;
      cout << "  Classified " << p << " as composite (it is prime)" << endl;
      return false;
    }
  }
  return true;
}

void run_tests() {
  int wrong = 0;
  int nb = 6;
  int total = nb;

  cout << endl << "** NBRS **" << endl;

  try {
    gcd(1, 3);
    cout << endl << "[TEST: GCD]" << endl;
    if (!test_gcd()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    vector<int> a({1});
    selection(a, 1);
    cout << endl << "[TEST: Selection]" << endl;
    if (!test_selection()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    subsets("123");
    cout << endl << "[TEST: Subsets]" << endl;
    if (!test_subsets()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    permutations("123");
    cout << endl << "[TEST: Permutations]" << endl;
    if (!test_permutations()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    is_prime(200);
    cout << endl << "[TEST: Primality]" << endl;
    if (!test_is_prime()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    kmp("", "");
    cout << endl << "[TEST: KMP]" << endl;
    if (!test_kmp()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  cout << "Executed " << total << " out of " << nb << " tests. ";
  cout << (total - wrong) << "/" << total << " tests pass." << endl;
}

}

namespace arrays {

bool test_kadane() {
  auto ans = kadane({-2, -3, 4, -1, -2, 1, 5, -3});
  if (ans != 7) {
    cout << endl;
    cout << "  Error: kadane()" << endl;
    cout << "  Did not return the right answer (" << ans << ")" << endl;
    return false;
  }
  return true;
}

bool test_binsearch() {
  auto ans1 = binsearch({2, 5, 8, 12, 16, 23, 38, 56, 72, 91}, 15);
  auto ans2 = binsearch({2, 5, 8, 12, 16, 23, 38, 56, 72, 91}, 38);
  if (ans1) {
    cout << endl;
    cout << "  Error: binsearch()" << endl;
    cout << "  Found a key that is not in the array" << endl;
    return false;
  }
  if (!ans2) {
    cout << endl;
    cout << "  Error: binsearch()" << endl;
    cout << "  Did not find a key that is in the array" << endl;
    return false;
  }
  return true;
}

bool test_closest_points() {
  int nb_tests = 1000;
  int max_nb_points = 500;
  int max_x = 100;
  int max_y = 100;
  for (int i = 0; i < nb_tests; ++i) {
    int len = rand() % max_nb_points + 2;
    vector<pair<double, double>> points(len);
    set<double> x_values; x_values.insert(0);
    for (int j = 0; j < len; ++j) {
      double val_x = 0;
      while (x_values.find(val_x) != x_values.end())
        val_x = (rand() % (max_x * 10)) / 10.;
      points[j].first = val_x;
      x_values.insert(val_x);
      points[j].second = (rand() % (max_y * 10)) / 10.;
    }
    double ans = closest_points(points);
    double local_ans = -1;
    pair<pair<double, double>, pair<double, double>> best;
    for (int k = 0; k < len - 1; ++k) {
      for (int l = k + 1; l < len; ++l) {
        double d = sqrt(pow(points[k].first - points[l].first, 2) +
                        pow(points[k].second - points[l].second, 2));
        if (local_ans == -1 || d < local_ans) {
          local_ans = d;
          best.first = points[k];
          best.second = points[l];
        }
      }
    }
    if (fabs(ans - local_ans) > 0.001) {
      cout << endl;
      cout << "  Error: Closest Pair()" << endl;
      cout << "  Did not find the right closest pair (returned: "
           << ans << ", expected: " << local_ans << ")" << endl;
      cout << "  With (" << best.first.first << ", " << best.first.second <<
          ") and (" << best.second.first << ", " << best.second.second << ")." << endl;
      return false;
    }
  }
  return true;
}

void run_tests() {
  int wrong = 0;
  int nb = 3;
  int total = nb;

  cout << endl << "** ARRAYS **" << endl;

  try {
    kadane({});
    cout << endl << "[TEST: Kadane]" << endl;
    if (!test_kadane()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    binsearch({}, 0);
    cout << endl << "[TEST: Binary Search]" << endl;
    if (!test_binsearch()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    vector<pair<double, double>> points({{1, 1}});
    closest_points(points);
    cout << endl << "[TEST: Closest Pair of Points]" << endl;
    if (!test_closest_points()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  cout << "Executed " << total << " out of " << nb << " tests. ";
  cout << (total - wrong) << "/" << total << " tests pass." << endl;
}

}

namespace graphs {

bool test_topo() {
  // Normal.
  graph topo = graph::build_graph(true);
  bool has_cycle = true;
  vector<vertex*> ordered = topo.topo_sort(&has_cycle);
  if (has_cycle) {
    cout << endl;
    cout << "  Error: topo_sort()" << endl;
    cout << "  Found a cycle but there is none." << endl;
    return false;
  }
  if (ordered.size() != topo.vertices.size()) {
    cout << endl;
    cout << "  Error: topo_sort()" << endl;
    cout << "  Some vertices are missing." << endl;
    return false;
  }
  set<vertex*> remaining(topo.vertices.begin(), topo.vertices.end());
  for (int i = 0; i < ordered.size(); ++i) {
    vertex* v = ordered[0];
    remaining.erase(v);
    for (auto* r : remaining) {
      for (auto* n : r->neighs) {
        if (n == v) {
          cout << endl;
          cout << "  Error: topo_sort()" << endl;
          cout << "  Selected node depends on another." << endl;
          return false;
        }
      }
    }
  }

  // Cycle.
  graph cycle = graph::build_graph(true, true);
  has_cycle = false;
  ordered = cycle.topo_sort(&has_cycle);
  if (!has_cycle) {
    cout << endl;
    cout << "  Error: topo_sort()" << endl;
    cout << "  Did not find the cycle." << endl;
    return false;
  }

  return true;
}

bool test_prim() {
  graph prim = graph::build_graph(false);
  vector<edge*> mincover = prim.prim();
  int sum = 0; for (auto* e : mincover) sum += e->cost;
  if (sum != 19) {
    cout << endl;
    cout << "  Error: prim()" << endl;
    cout << "  Wrong covering set." << endl;
    return false;
  }
  return true;
}

bool test_2_color() {
  graph color = graph::build_graph(false);
  bool answer = color.two_coloring();
  if (answer) {
    cout << endl;
    cout << "  Error: 2 coloring()" << endl;
    cout << "  Graph is not 2-colorable, returned true." << endl;
    return false;
  }
  return true;
}

bool test_dfs() {
  graph topo = graph::build_graph(true);
  auto list = topo.dfs(topo.vertices[0]);
  vector<int> result({1, 2, 3, 7, 4, 5, 6, 8, 10, 9});
  if (list != result) {
    cout << endl;
    cout << "  Error: dfs()" << endl;
    cout << "  Wrong dfs output, expected: "; print_vec(result);
    cout << "  Got: "; print_vec(list);
    return false;
  }
  return true;
}

bool test_bfs() {
  graph topo = graph::build_graph(true);
  auto list = topo.bfs(topo.vertices[0]);
  vector<int> result({1, 2, 6, 5, 4, 3, 9, 8, 7, 10});
  if (list != result) {
    cout << endl;
    cout << "  Error: bfs()" << endl;
    cout << "  Wrong bfs output, expected: "; print_vec(result);
    cout << "  Got: "; print_vec(list);
    return false;
  }
  return true;
}

bool test_floyd_warshall() {
  graph fw1 = graph::build_graph(false);
  auto ans1 = fw1.floyd_warshall();
  if (ans1 != vector<vector<int>>({
        {0, 4, 10, 5, 6, 6, 8, 10, 9, 11},
        {4, 0, 6, 1, 2, 2, 4, 6, 5, 7},
        {10, 6, 0, 7, 4, 7, 2, 4, 4, 6},
        {5, 1, 7, 0, 3, 3, 5, 7, 6, 8},
        {6, 2, 4, 3, 0, 4, 2, 4, 4, 6},
        {6, 2, 7, 3, 4, 0, 5, 7, 3, 5},
        {8, 4, 2, 5, 2, 5, 0, 2, 2, 4},
        {10, 6, 4, 7, 4, 7, 2, 0, 4, 2},
        {9, 5, 4, 6, 4, 3, 2, 4, 0, 2},
        {11, 7, 6, 8, 6, 5, 4, 2, 2, 0}})
      ) {
    cout << endl;
    cout << "  Error: floyd_warshall()" << endl;
    cout << "  Wrong weight matrix" << endl;
    for (auto& v : ans1) {
      for (auto i : v) cout << i << " "; cout << endl;
    }
    cout << endl;
  }
  graph fw2 = graph::build_graph(true);
  auto ans2 = fw2.floyd_warshall();
  if (ans2[0] != vector<int>({0, 4, 13, 5, 6, 6, 8, 13, 9, 11})) {
    cout << endl;
    cout << "  Error: floyd_warshall()" << endl;
    cout << "  Wrong weight matrix" << endl;
  }
  return true;
}

bool test_biconnected_components() {
  graph g1 = graph::build_graph(false);
  set<set<int>> check1({ {2, 4}, {1, 2}, {2, 3, 10, 8, 6, 9, 7, 5} });
  set<int> apoints1({2});
  for (vertex* start : g1.vertices) {
    set<int> apoints;
    auto answer1 = g1.biconnected_components(start, apoints);
    set<set<int>> ans1_to_set;
    for (auto& c : answer1) {
      //cout << "group: ";
      set<int> s;
      for (auto* v : c) {
        //cout << v->value << " ";
        s.insert(v->value);
      }
      ans1_to_set.insert(s);
      //cout << endl;
    }
    if (ans1_to_set != check1) {
      cout << endl;
      cout << "  Error: biconnected_components()" << endl;
      cout << "  Wrong set of components" << endl;
      return false;
    }
    //for (auto i : apoints) cout << i << " ";
    if (apoints != apoints1) {
      cout << endl;
      cout << "  Error: biconnected_components()" << endl;
      cout << "  Wrong set of articulation points" << endl;
      return false;
    }
  }

  graph g2 = graph::build_graph(false, false, true);
  set<set<int>> check2({ {2, 4}, {1, 2}, {2, 3, 7, 5}, {7, 10, 8, 6, 9} });
  set<int> apoints2({2, 7});
  for (vertex* start : g2.vertices) {
    set<int> apoints;
    auto answer2 = g2.biconnected_components(start, apoints);
    set<set<int>> ans2_to_set;
    for (auto& c : answer2) {
      //cout << "group: ";
      set<int> s;
      for (auto* v : c) {
        //cout << v->value << " ";
        s.insert(v->value);
      }
      ans2_to_set.insert(s);
      //cout << endl;
    }
    if (ans2_to_set != check2) {
      cout << endl;
      cout << "  Error: biconnected_components()" << endl;
      cout << "  Wrong set of components" << endl;
      return false;
    }
    //for (auto i : apoints) cout << i << " ";
    if (apoints != apoints2) {
      cout << endl;
      cout << "  Error: biconnected_components()" << endl;
      cout << "  Wrong set of articulation points" << endl;
      return false;
    }
  }

  return true;
}

void run_tests() {
  int wrong = 0;
  int nb = 7;
  int total = nb;

  cout << endl << "** GRAPHS **" << endl; 

  try {
    graph g; bool res; g.topo_sort(&res);
    cout << endl << "[TEST: Topological Sort]" << endl;
    if (!test_topo()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    graph g; g.add_vertex(1); g.prim();
    cout << endl << "[TEST: Prim]" << endl;
    if (!test_prim()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    graph g; g.two_coloring();
    cout << endl << "[TEST: 2-coloring]" << endl;
    if (!test_2_color()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    graph g; g.dfs(g.add_vertex(1));
    cout << endl << "[TEST: DFS]" << endl;
    if (!test_dfs()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    graph g; g.bfs(g.add_vertex(1));
    cout << endl << "[TEST: BFS]" << endl;
    if (!test_bfs()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    graph g; g.floyd_warshall();
    cout << endl << "[TEST: Floyd-Warshall]" << endl;
    if (!test_floyd_warshall()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  try {
    graph g; set<int> s; g.biconnected_components(g.add_vertex(1), s);
    cout << endl << "[TEST: Biconnected Components]" << endl;
    if (!test_biconnected_components()) wrong++;
    cout << endl;
  } catch(const not_implemented_exc& e) {
    total--;
  }

  cout << "Executed " << total << " out of " << nb << " tests. ";
  cout << (total - wrong) << "/" << total << " tests pass." << endl;
}

}

