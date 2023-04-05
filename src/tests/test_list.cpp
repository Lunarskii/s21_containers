#include "test_core.h"
#include <list>

using namespace std;

bool listsEqual(List<int> L1, list<int> L2) {
    if (L1.size() != L2.size()) {
        return false;
    }
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    for (; it_L1 != L1.end(); ++it_L1, ++it_L2) {
        if (*it_L1 != *it_L2) {
            return false;
        }
    }
    return true;
}

TEST(CONSTRUCTORS, DEFAULT_CONSTRUCTOR) {
    List<int> L1;

    ASSERT_EQ(L1.empty(), true);
}

TEST(CONSTRUCTORS, NSIZE_CONSTRUCTOR) {
    List<int> L1(3);

    for (List<int>::iterator it = L1.begin(); it != L1.end(); ++it) {
        ASSERT_EQ(*it, 0);
    }
}

TEST(CONSTRUCTORS, LIST_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3};

    List<int>::iterator it = L1.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(*it, 3);
}

TEST(CONSTRUCTORS, COPY_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3};
    List<int> L2(L1);
    List<int> L3 = {1, 2, 3};

    List<int>::iterator it_L1 = L1.begin();
    List<int>::iterator it_L2 = L2.begin();
    List<int>::iterator it_L3 = L3.begin();

    for (; it_L3 != L3.end(); ++it_L3, ++it_L2, ++it_L1) {
        ASSERT_EQ(*it_L3, *it_L2);
        ASSERT_EQ(*it_L3, *it_L1);
    }
}

TEST(CONSTRUCTORS, MOVE_CONSTRUCTOR) { // там просто лежат рандомные тесты, это не мув конструктор
    List<int> L1 = {1};
    List<int>::iterator it = L1.begin();
    ASSERT_EQ(*it, 1);
    *it = 4;
    ASSERT_EQ(*it, 4);
    List<int>::iterator it2 = L1.begin();
    ASSERT_EQ(*it2, 4);
}

TEST(METHOD_SIZE, SIZE_DEFAULT_CONTRUCTOR) {
    List<int> L1;
    list<int> L2;
    ASSERT_EQ(L1.size(), L2.size());
}

TEST(METHOD_SIZE, SIZE_NSIZE_CONSTRUCTOR) {
    List<int> L1(3);
    list<int> L2(3);
    ASSERT_EQ(L1.size(), L2.size());
}

TEST(METHOD_SIZE, SIZE_LIST_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3, 4, 5};
    list<int> L2 = {1, 2, 3, 4, 5};
    ASSERT_EQ(L1.size(), L2.size());
}

TEST(METHOD_SIZE, SIZE_COPY_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3, 4, 5, 6, 7};
    List<int> L2(L1);
    list<int> L3 = {1, 2, 3, 4, 5, 6, 7};
    list<int> L4(L3);
    ASSERT_EQ(L2.size(), L4.size());
}

// TEST(METHOD_SIZE, SIZE_MOVE_CONSTRUCTOR) {
    
// }

TEST(METHOD_EMPTY, EMPTY_DEFAULT_CONSTRUCTOR) {
    List<int> L1;
    list<int> L2;
    ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(METHOD_EMPTY, EMPTY_NSIZE_CONSTRUCTOR) {
    List<int> L1(1);
    list<int> L2(1);
    ASSERT_EQ(L1.empty(), L2.empty());

    List<int> L3(0);
    list<int> L4(0);
    ASSERT_EQ(L3.empty(), L4.empty());

    List<int> L5(0);
    list<int> L6(0);
    L5.push_back(0);
    L6.push_back(0);
    ASSERT_EQ(L5.empty(), L6.empty());
    L5.pop_front();
    L6.pop_front();
    ASSERT_EQ(L5.empty(), L6.empty());
}

TEST(METHOD_EMPTY, EMPTY_LIST_CONSTRUCTOR) {
    List<int> L1 = {};
    list<int> L2 = {};
    ASSERT_EQ(L1.empty(), L2.empty());

    List<int> L3 = {1};
    list<int> L4 = {1};
    ASSERT_EQ(L3.empty(), L4.empty());

    L1.push_back(1);
    L2.push_back(1);
    ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(METHOD_EMPTY, EMPTY_COPY_CONSTRUCTOR) {
    // List<int> L1;
    // List<int> L2(L1);
    // list<int> L3;
    // list<int> L4(L3);
    // ASSERT_EQ(L2.empty(), L4.empty());

    List<int> L5 = {1};
    List<int> L6(L5);
    list<int> L7 = {1};
    list<int> L8(L7);
    ASSERT_EQ(L6.empty(), L8.empty());
}

// TEST(METHOD_EMPTY, EMPTY_) {
    
// }

TEST(METHOD_SWAP, SWAP_ONE_LIST_EMPTY1) {
    List<int> L1 = {1, 2, 3};
    List<int> L2 = {};
    list<int> L3 = {1, 2, 3};
    list<int> L4 = {};
    L1.swap(L2);
    L3.swap(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_SWAP, SWAP_ONE_LIST_EMPTY2) {
    List<int> L1 = {};
    List<int> L2 = {4, 5, 6};
    list<int> L3 = {};
    list<int> L4 = {4, 5, 6};
    L1.swap(L2);
    L3.swap(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_SWAP, SWAP_EMPTY_LISTS) {
    List<int> L1 = {};
    List<int> L2 = {};
    list<int> L3 = {};
    list<int> L4 = {};
    L1.swap(L2);
    L3.swap(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_SWAP, SWAP_SAME_NUMBER_OF_ELEMENTS) {
    List<int> L1 = {1, 2, 3};
    List<int> L2 = {4, 5, 6};
    list<int> L3 = {1, 2, 3};
    list<int> L4 = {4, 5, 6};
    L1.swap(L2);
    L3.swap(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_SWAP, SWAP_DIFFERENT_NUMBER_OF_ELEMENTS1) {
    List<int> L1 = {1, 2, 3, 4, 5};
    List<int> L2 = {4, 5, 6};
    list<int> L3 = {1, 2, 3, 4, 5};
    list<int> L4 = {4, 5, 6};
    L1.swap(L2);
    L3.swap(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_SWAP, SWAP_DIFFERENT_NUMBER_OF_ELEMENTS2) {
    List<int> L1 = {1, 2, 3};
    List<int> L2 = {4, 5, 6, 128, 40};
    list<int> L3 = {1, 2, 3};
    list<int> L4 = {4, 5, 6, 128, 40};
    L1.swap(L2);
    L3.swap(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_REVERSE, REVERSE_5_ELEMENTS) {
    List<int> L1 = {1, 2, 3, 4, 5};
    list<int> L2 = {1, 2, 3, 4, 5};
    L1.reverse();
    L2.reverse();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_REVERSE, REVERSE_4_ELEMENTS) {
    List<int> L1 = {1, 2, 3, 4};
    list<int> L2 = {1, 2, 3, 4};
    L1.reverse();
    L2.reverse();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_REVERSE, REVERSE_1_ELEMENTS) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    L1.reverse();
    L2.reverse();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_REVERSE, REVERSE_0_ELEMENTS) {
    List<int> L1 = {};
    list<int> L2 = {};
    L1.reverse();
    L2.reverse();
    ASSERT_EQ(listsEqual(L1, L2), true);
}
