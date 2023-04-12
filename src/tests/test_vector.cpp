#include <vector>

#include "test_core.h"

template <typename value_type>
bool compare_vectors(const s21::Vector<value_type>& v1,
                     const std::vector<value_type>& v2) {
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
  s21::Vector<int> v1;
  std::vector<int> v2;
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, SizeConstructor) {
  s21::Vector<int> v1(5);
  std::vector<int> v2(5);
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, InitializerListConstructor) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, CopyConstructor) {
  s21::Vector<int> v1{1, 2, 3};
  s21::Vector<int> v1_copy(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_copy(v2);
  EXPECT_TRUE(compare_vectors(v1_copy, v2_copy));
}

TEST(VectorTest, MoveConstructor) {
  s21::Vector<int> v1{1, 2, 3};
  s21::Vector<int> v1_moved(std::move(v1));
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved(std::move(v2));
  EXPECT_TRUE(compare_vectors(v1_moved, v2_moved));
}

TEST(VectorTest, MoveAssignment) {
  s21::Vector<int> v1{1, 2, 3};
  s21::Vector<int> v1_moved;
  v1_moved = std::move(v1);
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_moved;
  v2_moved = std::move(v2);
  EXPECT_TRUE(compare_vectors(v1_moved, v2_moved));
}

TEST(VectorTest, At) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  for (std::size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v1.at(i), v2.at(i));
  }
}

TEST(VectorTest, FrontAndBack) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.front(), v2.front());
}

TEST(VectorTest, Data) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(*v1.data(), *v2.data());
}

// TEST(VectorTest, Iterators) {
//   s21::Vector<int> v1{1, 2, 3};
//   std::vector<int> v2{1, 2, 3};
//   EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin(), v2.end()));
//   EXPECT_TRUE(std::equal(v1.begin(), v1.end(), v2.begin(), v2.end()));
// }

TEST(VectorTest, Empty) {
  s21::Vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.empty(), v2.empty());
}

TEST(VectorTest, Size) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(VectorTest, MaxSize) {
  s21::Vector<int> v1;
  std::vector<int> v2;
  EXPECT_EQ(v1.max_size(), v2.max_size());
}

TEST(VectorTest, ReserveAndCapacity) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.reserve(100);
  v2.reserve(100);
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTest, ShrinkToFit) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.shrink_to_fit();
  v2.shrink_to_fit();
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(VectorTest, Clear) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.clear();
  v2.clear();
  EXPECT_TRUE(compare_vectors(v1, v2));
}

// TEST(VectorTest, Insert) {
//   s21::Vector<int> v1{1, 2, 3};
//   std::vector<int> v2{1, 2, 3};
//   v1.insert(v1.begin() + 1, 42);
//   v2.insert(v2.begin() + 1, 42);
//   EXPECT_TRUE(compare_vectors(v1, v2));
// }

// TEST(VectorTest, Erase) {
//   s21::Vector<int> v1{1, 2, 3};
//   std::vector<int> v2{1, 2, 3};
//   v1.erase(v1.begin() + 1);
//   v2.erase(v2.begin() + 1);
//   EXPECT_TRUE(compare_vectors(v1, v2));
// }

TEST(VectorTest, PushBack) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.push_back(4);
  v2.push_back(4);
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, PopBack) {
  s21::Vector<int> v1{1, 2, 3};
  std::vector<int> v2{1, 2, 3};
  v1.pop_back();
  v2.pop_back();
  EXPECT_TRUE(compare_vectors(v1, v2));
}

TEST(VectorTest, Swap) {
  s21::Vector<int> v1{1, 2, 3};
  s21::Vector<int> v1_swap{4, 5, 6};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v2_swap{4, 5, 6};
  v1.swap(v1_swap);
  v2.swap(v2_swap);

  EXPECT_TRUE(compare_vectors(v1, v2));
  EXPECT_TRUE(compare_vectors(v1_swap, v2_swap));
}

// int main(int argc, char** argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }