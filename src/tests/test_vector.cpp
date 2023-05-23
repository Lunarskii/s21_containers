#include <vector>

#include "test_core.h"

template <typename value_type>
bool compare_vectors(const s21::vector<value_type> &v1,
                     const std::vector<value_type> &v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  for (std::size_t i = 0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

TEST(VectorTest, DefaultConstructor) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, DefaultConstructor_Correct) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, DefaultConstructor_Incorrect) {
  s21::vector<int> v1;
  std::vector<int> v2;
  v2.push_back(1);
  EXPECT_NE(v1.size(), v2.size());
}

TEST(VectorTest, SizeConstructor) {
  s21::vector<int> v1(5);
  std::vector<int> v2(5);
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, SizeConstructor_Correct) {
  s21::vector<int> v1(5);
  std::vector<int> v2(5);
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, SizeConstructor_Incorrect) {
  s21::vector<int> v1(5);
  std::vector<int> v2(6);
  EXPECT_NE(v1.size(), v2.size());
}

TEST(VectorTest, InitializerListConstructor) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, InitializerListConstructor_Correct) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, InitializerListConstructor_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3, 4};
  EXPECT_NE(v1.size(), v2.size());
}

TEST(VectorTest, CopyConstructor) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_copy(v2);
  EXPECT_TRUE(compare_vectors(v1_copy, v2_copy));
}

TEST(VectorTest, CopyConstructor_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  EXPECT_EQ(v1.size(), v1_copy.size());
}

TEST(VectorTest, CopyConstructor_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_copy(v1);
  s21::vector<int> v1_wrong{1, 2, 3, 4};
  EXPECT_NE(v1_copy.size(), v1_wrong.size());
}

TEST(VectorTest, MoveConstructor) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved(std::move(v2));
  EXPECT_TRUE(compare_vectors(v1_moved, v2_moved));
}

TEST(VectorTest, MoveConstructor_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  EXPECT_EQ(v1_moved[0], 1);
  EXPECT_EQ(v1_moved[1], 2);
  EXPECT_EQ(v1_moved[2], 3);
}

TEST(VectorTest, MoveConstructor_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved(std::move(v1));
  EXPECT_NE(v1_moved.size(), v1.size());
}

TEST(VectorTest, MoveAssignment) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved;
  v2_moved = std::move(v2);
  EXPECT_TRUE(compare_vectors(v1_moved, v2_moved));
}

TEST(VectorTest, MoveAssignment_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  EXPECT_EQ(v1_moved[0], 1);
  EXPECT_EQ(v1_moved[1], 2);
  EXPECT_EQ(v1_moved[2], 3);
}

TEST(VectorTest, MoveAssignment_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_moved;
  v1_moved = std::move(v1);
  EXPECT_NE(v1_moved.size(), v1.size());
}

TEST(VectorTest, At) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  for (std::size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v1.at(i), v2.at(i));
  }
}

TEST(VectorTest, At_Correct) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.at(0), 1);
  EXPECT_EQ(v1.at(1), 2);
  EXPECT_EQ(v1.at(2), 3);
}

TEST(VectorTest, At_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_THROW(v1.at(3), std::out_of_range);
}

TEST(VectorTest, FrontAndBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.front(), v2.front());
}

TEST(VectorTest, FrontAndBack_Correct) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.front(), 1);
  EXPECT_EQ(v1.back(), 3);
}

TEST(VectorTest, FrontAndBack_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(v1.front(), 3);
  EXPECT_NE(v1.back(), 1);
}

TEST(VectorTest, Data) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(*v1.data(), *v2.data());
}

TEST(VectorTest, Data_Correct) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(*(++v1.data()), 2);
}

TEST(VectorTest, Data_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(*(++v1.data()), 1);
}

TEST(VectorTest, Empty) {
  s21::vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(VectorTest, Empty_Correct) {
  s21::vector<int> v1;
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, Empty_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_FALSE(v1.empty());
}

TEST(VectorTest, Size) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, Size_Correct) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_EQ(v1.size(), 3);
}

TEST(VectorTest, Size_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  EXPECT_NE(v1.size(), 4);
}

TEST(VectorTest, MaxSize) {
  s21::vector<int> v1;
  std::vector<int> v2;
  double ratio = static_cast<double>(v1.max_size()) / v2.max_size();
  // отношение размеров приближенно равно 2 с погрешностью 0.1
  EXPECT_NEAR(ratio, 2.0, 0.1);
}

TEST(VectorTest, MaxSize_Correct) {
  s21::vector<int> v1;
  EXPECT_GT(v1.max_size(), 0);
}

TEST(VectorTest, MaxSize_Incorrect) {
  s21::vector<int> v1;
  EXPECT_NE(v1.max_size(), -1);
}

TEST(VectorTest, ReserveAndCapacity) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.reserve(100);
  v2.reserve(100);
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTest, ReserveAndCapacity_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  EXPECT_GE(v1.capacity(), 100);
}

TEST(VectorTest, ReserveAndCapacity_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  EXPECT_NE(v1.capacity(), 50);
}

TEST(VectorTest, ShrinkToFit) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.shrink_to_fit();
  v2.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTest, ShrinkToFit_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), v1.size());
}

TEST(VectorTest, ShrinkToFit_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.reserve(100);
  v1.shrink_to_fit();
  EXPECT_NE(v1.capacity(), 100);
}

TEST(VectorTest, Clear) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.clear();
  v2.clear();
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, Clear_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.clear();
  EXPECT_TRUE(v1.empty());
}

TEST(VectorTest, Clear_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.clear();
  EXPECT_FALSE(v1.size() == 3);
}

TEST(VectorTest, PushBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.push_back(4);
  v2.push_back(4);
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, PushBack_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.push_back(4);
  EXPECT_EQ(v1.size(), 4);
  EXPECT_EQ(v1.back(), 4);
}

TEST(VectorTest, PushBack_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.push_back(4);
  EXPECT_NE(v1.size(), 3);
  EXPECT_NE(v1.back(), 3);
}

TEST(VectorTest, PopBack) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.pop_back();
  v2.pop_back();
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, PopBack_Correct) {
  s21::vector<int> v1{1, 2, 3};
  v1.pop_back();
  EXPECT_EQ(v1.size(), 2);
  EXPECT_EQ(v1.back(), 2);
}

TEST(VectorTest, PopBack_Incorrect) {
  s21::vector<int> v1{1, 2, 3};
  v1.pop_back();
  EXPECT_NE(v1.size(), 3);
  EXPECT_NE(v1.back(), 3);
}

TEST(VectorTest, Swap) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_swap{4, 5, 6};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_swap{4, 5, 6};
  v1.swap(v1_swap);
  v2.swap(v2_swap);

  EXPECT_TRUE(compare_vectors(v1, v2));
  EXPECT_TRUE(compare_vectors(v1_swap, v2_swap));
}

TEST(VectorTest, Swap_Correct) {
  s21::vector<int> v1{1, 2, 3};
  s21::vector<int> v1_swap{4, 5, 6};
  v1.swap(v1_swap);
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.front(), 4);
  EXPECT_EQ(v1.back(), 6);
  EXPECT_EQ(v1_swap.size(), 3);
  EXPECT_EQ(v1_swap.front(), 1);
  EXPECT_EQ(v1_swap.back(), 3);
}

//==================================================================================
// VectorIterator
//==================================================================================

TEST(VectorIteratorTest, Increment_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorIteratorTest, Increment_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  ++it;
  EXPECT_NE(*it, 1);
  ++it;
  EXPECT_NE(*it, 2);
}

TEST(VectorIteratorTest, Decrement_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorIteratorTest, Decrement_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.end();
  --it;
  EXPECT_NE(*it, 2);
  --it;
  EXPECT_NE(*it, 1);
}

TEST(VectorIteratorTest, Dereference_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorIteratorTest, Dereference_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it = v.begin();
  EXPECT_NE(*it, 2);
  ++it;
  EXPECT_NE(*it, 1);
}

TEST(VectorIteratorTest, Equality_Correct) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it1 = v.begin();
  s21::vector<int>::iterator it2 = v.begin();
  EXPECT_TRUE(it1 == it2);
  ++it1;
  EXPECT_FALSE(it1 == it2);
}

TEST(VectorIteratorTest, Equality_Incorrect) {
  s21::vector<int> v{1, 2, 3};
  s21::vector<int>::iterator it1 = v.begin();
  s21::vector<int>::iterator it2 = v.begin();
  EXPECT_FALSE(it1 != it2);
  ++it1;
  EXPECT_TRUE(it1 != it2);
}

//==================================================================================
// VectorConstIterator
//==================================================================================

TEST(VectorConstIteratorTest, Increment_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.begin();
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorConstIteratorTest, Increment_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.begin();
  ++it;
  EXPECT_NE(*it, 1);
  ++it;
  EXPECT_NE(*it, 2);
}

TEST(VectorConstIteratorTest, Decrement_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
  --it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorConstIteratorTest, Decrement_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.end();
  --it;
  EXPECT_NE(*it, 2);
  --it;
  EXPECT_NE(*it, 1);
}

TEST(VectorConstIteratorTest, Dereference_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorConstIteratorTest, Dereference_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it = v.begin();
  EXPECT_NE(*it, 2);
  ++it;
  EXPECT_NE(*it, 1);
}

TEST(VectorConstIteratorTest, Equality_Correct) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it1 = v.begin();
  s21::vector<int>::const_iterator it2 = v.begin();
  EXPECT_TRUE(it1 == it2);
  ++it1;
  EXPECT_FALSE(it1 == it2);
}

TEST(VectorConstIteratorTest, Equality_Incorrect) {
  const s21::vector<int> v{1, 2, 3};
  s21::vector<int>::const_iterator it1 = v.begin();
  s21::vector<int>::const_iterator it2 = v.begin();
  EXPECT_FALSE(it1 != it2);
  ++it1;
  EXPECT_TRUE(it1 != it2);
}

// Test for const iterator's operator+
TEST(VectorConstIteratorTest2, ConstIteratorOperatorPlusTest1) {
  const s21::vector<int> v{1,2,3};

  s21::vector<int>::const_iterator it = v.begin();
  s21::vector<int>::const_iterator result = it + 2;

  EXPECT_EQ(*result, 3);
}

// Test for const iterator's operator-
TEST(VectorConstIteratorTest2, ConstIteratorOperatorMinusTest1) {
  const s21::vector<int> v{1,2,3};
  s21::vector<int>::const_iterator it = v.end();
  s21::vector<int>::const_iterator result = it - 2;

  EXPECT_EQ(*result, 2);
}

// Test for const iterator's operator++
TEST(VectorConstIteratorTest2, ConstIteratorOperatorPlusPlusTest1) {
  const s21::vector<int> v{1,2,3};
  s21::vector<int>::const_iterator it = v.begin();
  it++;

  EXPECT_EQ(*it, 2);
}

// Test for const iterator's operator--
TEST(VectorConstIteratorTest2, ConstIteratorOperatorMinusMinusTest1) {
  const s21::vector<int> v{1,2,3};
  s21::vector<int>::const_iterator it = v.end();
  it--;

  EXPECT_EQ(*it, 3);
}

// Test for const iterator's operator-
TEST(VectorConstIteratorTest2, ConstIteratorOperatorMinusTest2) {
  const s21::vector<int> v{1,2,3};

  s21::vector<int>::const_iterator it1 = v.begin();
  s21::vector<int>::const_iterator it2 = v.end();

  ptrdiff_t result = it2 - it1;

  EXPECT_EQ(result, 3);
}


//==================================================================================
// VectorBonus
//==================================================================================

TEST(VectorTest, EmplaceTest0) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v2.emplace(v2.begin(), 42);
  v1.emplace(v1.begin(), 42);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceTest1) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.emplace(v1.begin() + 1, 42);
  v2.emplace(v2.begin() + 1, 42);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceTest12) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.emplace(v1.begin() + 1, 4);
  v2.emplace(v2.begin() + 1, 4);
  v1.emplace(v1.begin() + 1, 5);
  v2.emplace(v2.begin() + 1, 5);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceTest2) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.emplace(v1.begin(), 42);
  v2.emplace(v2.begin(), 42);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceTest3) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.emplace(v1.end(), 42);
  v2.emplace(v2.end(), 42);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceTest4) {
  s21::vector<std::string> v1{"one", "two", "three"};
  std::vector<std::string> v2{"one", "two", "three"};

  v1.emplace(v1.begin() + 1, "four");
  v2.emplace(v2.begin() + 1, "four");

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest1) {
  s21::vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};

  v1.emplace_back(42);
  v2.emplace_back(42);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest2) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v1.emplace_back(42);
  v2.emplace_back(42);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest3) {
  s21::vector<std::string> v1{"one", "two", "three"};
  std::vector<std::string> v2{"one", "two", "three"};

  v1.emplace_back("four");
  v2.emplace_back("four");

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest5) {
  s21::vector<int> v1;
  std::vector<int> v2;

  for (int i = 0; i < 10; ++i) {
    v1.emplace_back(i);
    v2.emplace_back(i);
  }

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest6) {
  s21::vector<double> v1{1.1, 2.2, 3.3};
  std::vector<double> v2{1.1, 2.2, 3.3};

  v1.emplace_back(4.4);
  v2.emplace_back(4.4);

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest7) {
  s21::vector<std::string> v1;
  std::vector<std::string> v2;

  v1.emplace_back("test");
  v2.emplace_back("test");

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest9) {
  s21::vector<int> v1;
  std::vector<int> v2;

  for (int i = 0; i < 1000; ++i) {
    v1.emplace_back(i);
    v2.emplace_back(i);
  }

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, EmplaceBackTest10) {
  s21::vector<int> v1;
  std::vector<int> v2;

  v1.reserve(100);
  v2.reserve(100);

  for (int i = 0; i < 100; ++i) {
    v1.emplace_back(i);
    v2.emplace_back(i);
  }

  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, BracketOutOfRange) {
  s21::vector<int> v1{1,2,4};
  EXPECT_THROW(v1[5], std::out_of_range);
}



//


TEST(VectorTest, OperatorBracketThrowTest) {
  s21::vector<int> v;
  std::cout << v.size() << std::endl;
  EXPECT_THROW(v[0], std::out_of_range);
  EXPECT_THROW(v[5], std::out_of_range);

  v.push_back(42);
  EXPECT_NO_THROW(v[0]);
  EXPECT_THROW(v[1], std::out_of_range);
}

TEST(VectorTest, FrontThrowTest) {
  s21::vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);

  v.push_back(42);
  EXPECT_NO_THROW(v.front());

  v.clear();
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(VectorTest, BackThrowTest) {
  s21::vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);

  v.push_back(42);
  EXPECT_NO_THROW(v.back());

  v.clear();
  EXPECT_THROW(v.back(), std::out_of_range);
}


TEST(VectorTest, InsertThrowTest) {
  s21::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // Insert at valid position
  EXPECT_NO_THROW(v.insert(v.begin() + 1, 42));

  // Insert at invalid position
  EXPECT_THROW(v.insert(v.begin() + 5, 42), std::out_of_range);
}

TEST(VectorTest, EraseThrowTest) {
  s21::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // Erase at valid position
  EXPECT_NO_THROW(v.erase(v.begin() + 1));

  // Erase at invalid position
  EXPECT_THROW(v.erase(v.begin() + 5), std::out_of_range);
}


// Test for throw in operator[]
TEST(VectorTest, OperatorIndexOutOfRangeTest) {
  const s21::vector<int> v{1,2,3};

  EXPECT_THROW({ int value = v[3]; }, std::out_of_range);
  EXPECT_THROW({ int value = v[4]; }, std::out_of_range);
  EXPECT_THROW({ int value = v[-1]; }, std::out_of_range);
}

// Test for throw in reserve
TEST(VectorTest, ReserveExceedsMaxSizeTest) {
  s21::vector<int> v;

  EXPECT_THROW({ v.reserve(v.max_size() + 1); }, std::length_error);
}

