#include "test_core.h"
#include <list>

using namespace std;
TEST(CONSTRUCTORS, DEFAULT_CONSTRUCTOR) {
    List<int> x = {1, 2, 3};
    list<int> y = {1, 2, 3};

    List<int>::iterator it_x = x.begin();
    list<int>::iterator it_y = y.begin();
    for (; it_x != x.end() || it_y != y.end(); ++it_x, ++it_y) {
        ASSERT_EQ(*it_x, *it_y);
    }
}

