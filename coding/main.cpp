#include "tests.hpp"

#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
  srand(time(nullptr));
  sorts::run_tests();
  datastructures::run_tests();
  math::run_tests();
  arrays::run_tests();
  graphs::run_tests();
}
