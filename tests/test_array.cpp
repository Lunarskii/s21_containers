#include "test_core.h"
#include <array>

bool arrayEquals(s21::array<int, 10> &a1,
                     std::array<int, 10> &a2) {
    for (std::size_t i = 0; i < 9; ++i) {
        if (a1[i] != a2[i]) {
            return false;
        }
    }
    return true;
}

TEST(ARRAY_CONSTRUCTORS, ARRAY_DEFAULT_CONSTRUCTOR) {
    s21::array<int, 10> a1;

    ASSERT_NO_THROW(a1[0]);
}

TEST(ARRAY_CONSTRUCTORS, ARRAY_LIST_CONSTRUCTOR) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(arrayEquals(a1, a2), true);
}

TEST(ARRAY_CONSTRUCTORS, ARRAY_COPY_CONSTRUCTOR) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    s21::array<int, 10> a2(a1);
    std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a4(a3);

    ASSERT_EQ(arrayEquals(a2, a4), true);
}

TEST(ARRAY_CONSTRUCTORS, ARRAY_MOVE_CONSTRUCTOR) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    s21::array<int, 10> a2(std::move(a1));
    std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a4(std::move(a3));

    ASSERT_EQ(arrayEquals(a1, a3), true);
    ASSERT_EQ(arrayEquals(a2, a4), true);
}

TEST(ARRAY_METHODS, ARRAY_BEGIN) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(*a1.begin(), *a2.begin());
}

TEST(ARRAY_METHODS, ARRAY_END) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    s21::array<int, 10>::iterator it = a1.end();
    --it;
    std::array<int, 10>::iterator std_it = a2.end();
    --std_it;

    ASSERT_EQ(*it, *std_it);
}

TEST(ARRAY_METHODS, ARRAY_DATA) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(*a1.data(), *a2.data());
}

TEST(ARRAY_METHODS, ARRAY_AT_IN_BOUNDS) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1.at(2), a2.at(2));
}

TEST(ARRAY_METHODS, ARRAY_AT_OUT_OF_BOUNDS) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_THROW(a1.at(20), std::out_of_range);
    ASSERT_THROW(a2.at(20), std::out_of_range);
}

TEST(ARRAY_METHODS, ARRAY_FRONT) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1.front(), a2.front());
}

TEST(ARRAY_METHODS, ARRAY_BACK) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1.back(), a2.back());
}

TEST(ARRAY_METHODS, ARRAY_EMPTY_IS_EMPTY) {
    s21::array<int, 10> a1;
    std::array<int, 10> a2;

    ASSERT_EQ(a1.empty(), a2.empty());
}

TEST(ARRAY_METHODS, ARRAY_EMPTY_IS_NOT_EMPTY) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1.empty(), a2.empty());
}

TEST(ARRAY_METHODS, ARRAY_SIZE_ZERO) {
    s21::array<int, 0> a1;
    std::array<int, 0> a2;

    ASSERT_EQ(a1.size(), a2.size());
}

TEST(ARRAY_METHODS, ARRAY_SIZE_NOT_ZERO) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1.size(), a2.size());
}

TEST(ARRAY_METHODS, ARRAY_MAX_SIZE_ZERO) {
    s21::array<int, 0> a1;
    std::array<int, 0> a2;

    ASSERT_EQ(a1.max_size(), a2.max_size());
}

TEST(ARRAY_METHODS, ARRAY_MAX_SIZE_NOT_ZERO) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1.max_size(), a2.max_size());
}

TEST(ARRAY_METHODS, ARRAY_SWAP_SAME_SIZE) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    s21::array<int, 10> a2{9, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a4{9, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    a1.swap(a2);
    a3.swap(a4);
    ASSERT_EQ(arrayEquals(a1, a3), true);
    ASSERT_EQ(arrayEquals(a2, a4), true);
}

TEST(ARRAY_METHODS, ARRAY_FILL) {
    s21::array<int, 10> a1;
    std::array<int, 10> a2;

    a1.fill(1);
    a2.fill(1);
    ASSERT_EQ(arrayEquals(a1, a2), true);
}

TEST(ARRAY_OPERATOR_OVERLOADS, ARRAY_COPY_ASSIGNMENT_OPERATOR) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    s21::array<int, 10> a2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    a1 = a2;
    a3 = a4;
    ASSERT_EQ(arrayEquals(a1, a3), true);
}

TEST(ARRAY_OPERATOR_OVERLOADS, ARRAY_MOVE_ASSIGNMENT_OPERATOR) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    s21::array<int, 10> a2{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    std::array<int, 10> a3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a4{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    a1 = std::move(a2);
    a3 = std::move(a4);
    ASSERT_EQ(arrayEquals(a1, a3), true);
}

TEST(ARRAY_OPERATOR_OVERLOADS, ARRAY_INDEXATION_OPERATOR_INDEXING1) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1[1], a2[1]);
}

TEST(ARRAY_OPERATOR_OVERLOADS, ARRAY_INDEXATION_OPERATOR_INDEXING2) {
    const s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_EQ(a1[1], a2[1]);
}

TEST(ARRAY_OPERATOR_OVERLOADS, ARRAY_INDEXATION_OPERATOR_INDEXING3) {
    const s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    ASSERT_THROW(a1[100], std::out_of_range);
}

TEST(ARRAY_OPERATOR_OVERLOADS, ARRAY_INDEXATION_OPERATOR_ASSERTION) {
    s21::array<int, 10> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    a1[1] = 60;
    a2[1] = 60;
    ASSERT_EQ(a1[1], a2[1]);
}
