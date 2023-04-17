#include "test_core.h"
#include <list>

using namespace s21;
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
    list<int> L2;
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(CONSTRUCTORS, NSIZE_CONSTRUCTOR) {
    List<int> L1(3);
    list<int> L2(3);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(CONSTRUCTORS, LIST_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(CONSTRUCTORS, COPY_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3};
    List<int> L2(L1);
    list<int> L3 = {1, 2, 3};
    list<int> L4(L3);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(CONSTRUCTORS, MOVE_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3};
    List<int> L2(std::move(L1));
    list<int> L3 = {1, 2, 3};
    list<int> L4(std::move(L3));
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
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

TEST(METHOD_SIZE, SIZE_MOVE_CONSTRUCTOR) {
    List<int> L1 = {1, 2, 3, 4, 5};
    List<int> L2(std::move(L1));
    list<int> L3 = {1, 2, 3, 4, 5};
    list<int> L4(std::move(L3));
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

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
    List<int> L1;
    List<int> L2(L1);
    list<int> L3;
    list<int> L4(L3);
    ASSERT_EQ(L2.empty(), L4.empty());

    List<int> L5 = {1};
    List<int> L6(L5);
    list<int> L7 = {1};
    list<int> L8(L7);
    ASSERT_EQ(L6.empty(), L8.empty());
}

TEST(METHOD_EMPTY, EMPTY_MOVE_CONSTRUCTOR) {
    List<int> L1;
    List<int> L2(std::move(L1));
    list<int> L3;
    list<int> L4(std::move(L3));
    ASSERT_EQ(L1.empty(), L3.empty());
    ASSERT_EQ(L2.empty(), L4.empty());
}

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

TEST(METHOD_INSERT, INSERT_START_OF_THE_LIST_3_ELEMENTS) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    L1.insert(it_L1, 128);
    L2.insert(it_L2, 128);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_INSERT, INSERT_MIDDLE_OF_THE_LIST) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = ++L1.begin();
    list<int>::iterator it_L2 = ++L2.begin();
    L1.insert(it_L1, 128);
    L2.insert(it_L2, 128);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_INSERT, INSERT_START_OF_THE_LIST_1_ELEMENT) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    L1.insert(it_L1, 128);
    L2.insert(it_L2, 128);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_INSERT, INSERT_END_OF_THE_LIST) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    ++it_L1;
    ++it_L2;
    L1.insert(it_L1, 128);
    L2.insert(it_L2, 128);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_INSERT, INSERT_CYCLIC_SHIFT) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    ++it_L1;
    ++it_L1;
    ++it_L2;
    ++it_L2;
    L1.insert(it_L1, 128);
    L2.insert(it_L2, 128);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_INSERT, INSERT_EMPTY_LIST) {
    List<int> L1 = {};
    list<int> L2 = {};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    L1.insert(it_L1, 128);
    L2.insert(it_L2, 128);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_MAX_SIZE, MAX_SIZE) {
    List<int> L1;
    list<int> L2;
    ASSERT_EQ(L1.max_size(), L2.max_size());
}

TEST(METHOD_ERASE, ERASE_FIRST_ELEM) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    L1.erase(it_L1);
    L2.erase(it_L2);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_ERASE, ERASE_LAST_ELEM) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = --L1.end();
    list<int>::iterator it_L2 = --L2.end();
    L1.erase(it_L1);
    L2.erase(it_L2);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_ERASE, ERASE_MIDDLE_ELEM) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = ++L1.begin();
    list<int>::iterator it_L2 = ++L2.begin();
    L1.erase(it_L1);
    L2.erase(it_L2);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_SORT, SORT_1) {
    List<int> L1 = {9, 2, 3, 1, 4};
    list<int> L2 = {9, 2, 3, 1, 4};
    L1.sort();
    L2.sort();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_SORT, SORT_2) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    L1.sort();
    L2.sort();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_SORT, SORT_3) {
    List<int> L1 = {};
    list<int> L2 = {};
    L1.sort();
    L2.sort();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_SORT, SORT_TYPE_STRING) {
    List<string> L1 = {"abcd", "abcdef", "abc"};
    list<string> L2 = {"abcd", "abcdef", "abc"};
    L1.sort();
    L2.sort();
    List<string>::iterator it_L1 = L1.begin();
    list<string>::iterator it_L2 = L2.begin();
    for (; it_L2 != L2.end(); ++it_L2, ++it_L1) {
        ASSERT_EQ(*it_L1, *it_L2);
    }
}

TEST(METHOD_SORT, SORT_SORTED_LIST) {
    List<int> L1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> L2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    L1.sort();
    L2.sort();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_MERGE, MERGE_IDENTICAL_LISTS) {
    List<int> L1 = {1, 2, 3, 4, 5};
    List<int> L2 = {1, 2, 3, 4, 5};
    list<int> L3 = {1, 2, 3, 4, 5};
    list<int> L4 = {1, 2, 3, 4, 5};
    L1.merge(L2);
    L3.merge(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

// TEST(METHOD_MERGE, MERGE_FIRST_LIST_REVERSE) {
//     List<int> L1 = {5, 4, 3, 2, 1};
//     List<int> L2 = {1, 2, 3, 4, 5};
//     list<int> L3 = {5, 4, 3, 2, 1};
//     list<int> L4 = {1, 2, 3, 4, 5};
//     L1.merge(L2);
//     L3.merge(L4);

//     List<int>::iterator it_L1 = L1.begin();
//     list<int>::iterator it_L3 = L3.begin();

//     cout << endl << "L1:" << endl;
//     for (; it_L1 != L1.end(); ++it_L1) {
//         cout << *it_L1 << " ";
//     }
//     cout << endl << "L2" << endl;
//     for (; it_L3 != L3.end(); ++it_L3) {
//         cout << *it_L3 << " ";
//     }
//     cout << endl;

//     ASSERT_EQ(listsEqual(L1, L3), true);
//     ASSERT_EQ(listsEqual(L2, L4), true);
// }

// TEST(METHOD_MERGE, MERGE_SECOND_LIST_REVERSE) {
//     List<int> L1 = {1, 2, 3, 4, 5};
//     List<int> L2 = {5, 4, 3, 2, 1};
//     list<int> L3 = {1, 2, 3, 4, 5};
//     list<int> L4 = {5, 4, 3, 2, 1};
//     L1.merge(L2);
//     L3.merge(L4);
//     ASSERT_EQ(listsEqual(L1, L3), true);
//     ASSERT_EQ(listsEqual(L2, L4), true);
// }

TEST(METHOD_MERGE, MERGE_FIRST_LIST_EMPTY) {
    List<int> L1 = {};
    List<int> L2 = {5, 4, 3, 2, 1};
    list<int> L3 = {};
    list<int> L4 = {5, 4, 3, 2, 1};
    L1.merge(L2);
    L3.merge(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_MERGE, MERGE_SECOND_LIST_EMPTY) {
    List<int> L1 = {1, 2, 3, 4, 5};
    List<int> L2 = {};
    list<int> L3 = {1, 2, 3, 4, 5};
    list<int> L4 = {};
    L1.merge(L2);
    L3.merge(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_MERGE, MERGE_SORTED_LISTS_1) {
    List<int> L1 = {1, 2, 3, 4, 5};
    List<int> L2 = {6, 7, 8, 9, 10};
    list<int> L3 = {1, 2, 3, 4, 5};
    list<int> L4 = {6, 7, 8, 9, 10};
    L1.merge(L2);
    L3.merge(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_MERGE, MERGE_SORTED_LISTS_2) {
    List<int> L1 = {1, 3, 5, 7};
    List<int> L2 = {2, 4, 6, 8};
    list<int> L3 = {1, 3, 5, 7};
    list<int> L4 = {2, 4, 6, 8};
    L1.merge(L2);
    L3.merge(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(METHOD_MERGE, MERGE_TYPE_STRING) {
    List<string> L1 = {"abc", "abcd", "abcdef"};
    List<string> L2 = {"ab", "abcde"};
    list<string> L3 = {"abc", "abcd", "abcdef"};
    list<string> L4 = {"ab", "abcde"};
    L1.merge(L2);
    L3.merge(L4);
    List<string>::iterator it_L1 = L1.begin();
    List<string>::iterator it_L2 = L2.begin();
    list<string>::iterator it_L3 = L3.begin();
    list<string>::iterator it_L4 = L4.begin();
    for (; it_L3 != L3.end(); ++it_L3, ++it_L1) {
        ASSERT_EQ(*it_L1, *it_L3);
    }
    for (; it_L4 != L4.end(); ++it_L4, ++it_L2) {
        ASSERT_EQ(*it_L2, *it_L4);
    }
}

TEST(METHOD_UNIQUE, UNIQUE_SORTED_LIST) {
    List<int> L1 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
    list<int> L2 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
    L1.unique();
    L2.unique();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_UNIQUE, UNIQUE_UNSORTED_LIST) {
    List<int> L1 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
    list<int> L2 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
    L1.unique();
    L2.unique();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_UNIQUE, UNIQUE_EMPTY_LIST) {
    List<int> L1 = {};
    list<int> L2 = {};
    L1.unique();
    L2.unique();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_UNIQUE, UNIQUE_ONE_ELEM) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    L1.unique();
    L2.unique();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_SPLICE, SPLICE_FIRST_ELEM) {
    List<int> L1 = {1, 2, 3};
    List<int> L2 = {4, 5, 6};
    list<int> empty_list = {};
    list<int> result = {4, 5, 6, 1, 2, 3};
    List<int>::const_iterator it = L1.cbegin();
    L1.splice(it, L2);
    ASSERT_EQ(listsEqual(L1, result), true);
    ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(METHOD_SPLICE, SPLICE_SECOND_ELEM) {
    List<int> L1 = {1, 2};
    List<int> L2 = {4, 5, 6};
    list<int> empty_list = {};
    list<int> result = {1, 4, 5, 6, 2};
    List<int>::const_iterator it = ++L1.cbegin();
    L1.splice(it, L2);
    ASSERT_EQ(listsEqual(L1, result), true);
    ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(METHOD_SPLICE, SPLICE_TO_EMPTY_LIST) {
    List<int> L1 = {};
    List<int> L2 = {4, 5, 6};
    list<int> empty_list = {};
    list<int> result = {4, 5, 6};
    List<int>::const_iterator it = L1.cbegin();
    L1.splice(it, L2);
    ASSERT_EQ(listsEqual(L1, result), true);
    ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(METHOD_SPLICE, SPLICE_FROM_EMPTY_LIST) {
    List<int> L1 = {1, 2, 3};
    List<int> L2 = {};
    list<int> empty_list = {};
    list<int> result = {1, 2, 3};
    List<int>::const_iterator it = L1.cbegin();
    L1.splice(it, L2);
    ASSERT_EQ(listsEqual(L1, result), true);
    ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(METHOD_FRONT, FRONT_EMPTY_LIST) {
    List<int> L1;
    list<int> L2;
    ASSERT_EQ(L1.front(), L2.front());
}

TEST(METHOD_FRONT, FRONT_3_ELEMENTS) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    ASSERT_EQ(L1.front(), L2.front());
}

TEST(METHOD_BACK, BACK_EMPTY_LIST) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    ASSERT_EQ(L1.back(), L2.back());
}

TEST(METHOD_BACK, BACK_3_ELEMENTS) {
    List<int> L1;
    list<int> L2;
    ASSERT_EQ(L1.back(), L2.back());
}

TEST(METHOD_PUSH_FRONT, PUSH_FRONT) {
    List<int> L1;
    list<int> L2;
    L1.push_front(1);
    L2.push_front(1);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_PUSH_BACK, PUSH_BACK) {
    List<int> L1;
    list<int> L2;
    L1.push_back(1);
    L2.push_back(1);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_POP_FRONT, POP_FRONT) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    L1.pop_front();
    L2.pop_front();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_POP_BACK, POP_BACK) {
    List<int> L1 = {1};
    list<int> L2 = {1};
    L1.pop_back();
    L2.pop_back();
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(ITERATORS, PLUS_PLUS_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = ++L1.begin();
    list<int>::iterator it_L2 = ++L2.begin();
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ITERATORS, MINUS_MINUS_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = --L1.begin();
    list<int>::iterator it_L2 = --L2.begin();
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ITERATORS, OPERATOR_PLUS_PLUS) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = L1.begin()++;
    list<int>::iterator it_L2 = L2.begin()++;
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ITERATORS, OPERATOR_MINUS_MINUS) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = L1.begin()--;
    list<int>::iterator it_L2 = L2.begin()--;
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ITERATORS, DEREFERENCE_OPERATOR_EXISTING_LIST_1) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ITERATORS, DEREFERENCE_OPERATOR_EXISTING_LIST_2) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::iterator it_L1 = L1.begin();
    list<int>::iterator it_L2 = L2.begin();
    *it_L1 = 128;
    *it_L2 = 128;
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(ITERATORS, DEREFERENCE_OPERATOR_NOT_EXISTING_LIST) {
    try {
        List<int>::iterator it_L1;
        *it_L1;
    } catch (const std::exception& e) {
        ASSERT_STREQ(e.what(), "Invalid index");
    }
}

TEST(ITERATORS, NOT_EQUAL_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    ASSERT_EQ(L1.begin() != L1.begin(), L2.begin() != L2.begin());
}

TEST(ITERATORS, EQUAL_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    ASSERT_EQ(L1.begin() == L1.begin(), L2.begin() == L2.begin());
}

TEST(CONST_ITERATORS, PLUS_PLUS_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::const_iterator it_L1 = ++L1.cbegin();
    list<int>::const_iterator it_L2 = ++L2.cbegin();
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(CONST_ITERATORS, MINUS_MINUS_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::const_iterator it_L1 = --L1.cbegin();
    list<int>::const_iterator it_L2 = --L2.cbegin();
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(CONST_ITERATORS, OPERATOR_PLUS_PLUS) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::const_iterator it_L1 = L1.cbegin()++;
    list<int>::const_iterator it_L2 = L2.cbegin()++;
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(CONST_ITERATORS, OPERATOR_MINUS_MINUS) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::const_iterator it_L1 = L1.cbegin()--;
    list<int>::const_iterator it_L2 = L2.cbegin()--;
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(CONST_ITERATORS, DEREFERENCE_OPERATOR_EXISTING_LIST) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    List<int>::const_iterator it_L1 = L1.cbegin();
    list<int>::const_iterator it_L2 = L2.cbegin();
    ASSERT_EQ(*it_L1, *it_L2);
}

TEST(CONST_ITERATORS, DEREFERENCE_OPERATOR_NOT_EXISTING_LIST) {
    try {
        List<int>::const_iterator it_L1;
        *it_L1;
    } catch (const std::exception& e) {
        ASSERT_STREQ(e.what(), "Invalid index");
    }
}

TEST(CONST_ITERATORS, NOT_EQUAL_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    ASSERT_EQ(L1.cbegin() != L1.cbegin(), L2.cbegin() != L2.cbegin());
}

TEST(CONST_ITERATORS, EQUAL_OPERATOR) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3};
    ASSERT_EQ(L1.cbegin() == L1.cbegin(), L2.cbegin() == L2.cbegin());
}

TEST(METHOD_EMPLACE, EMPLACE) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 4, 5, 6, 2, 3};
    L1.emplace(++L1.begin(), 4, 5, 6);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_EMPLACE_BACK, EMPLACE_BACK) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {1, 2, 3, 4, 5, 6};
    L1.emplace_back(4, 5, 6);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(METHOD_EMPLACE_FRONT, EMPLACE_FRONT) {
    List<int> L1 = {1, 2, 3};
    list<int> L2 = {4, 5, 6, 1, 2, 3};
    L1.emplace_front(4, 5, 6);
    ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(LIST, OPERATOR_EQUAL_COPY) {
    List<int> L1 = {1, 2, 3};
    List<int> L2 = {4, 5, 6};
    list<int> L3 = {1, 2, 3};
    list<int> L4 = {4, 5, 6};
    L1 = L2;
    L3 = L4;
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(LIST, OPERATOR_EQUAL_MOVE) {
    List<int> L1 = {1, 2, 3};
    List<int> L2 = {4, 5, 6};
    list<int> L3 = {1, 2, 3};
    list<int> L4 = {4, 5, 6};
    L1 = std::move(L2);
    L3 = std::move(L4);
    ASSERT_EQ(listsEqual(L1, L3), true);
    ASSERT_EQ(listsEqual(L2, L4), true);
}
