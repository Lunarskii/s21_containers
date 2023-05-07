#ifndef CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_MAP_H_
#define CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_MAP_H_

#include "../binaryTree/binary_tree.h"

namespace s21 {
template<typename Key, typename T>
class map {
	public:
		class MapIterator;

		using key_type = Key;
		using mapped_type = T;
		using value_type = std::pair<const key_type, mapped_type>;
		using reference = T&;
		using const_reference = const Key&;
		using iterator = map<Key, T>::MapIterator;
		// using const_iterator = BinaryTree::const_iterator;
		using size_type = std::size_t;

		map();
		map(std::initializer_list<value_type> const &items);
		map(const map &other);
		map(map &&other);
		~map() = default; // спросить Даню

		iterator begin();
		iterator end();

		bool empty();
		size_type size();
		size_type max_size();

		void clear();
		std::pair<iterator, bool> insert(const value_type& value);
		std::pair<iterator, bool> insert(const Key& key, const T& obj);
		std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
		void erase(iterator pos);
		void swap(map& other);
		void merge(map& other);

		bool contains(const_reference key);

		T& at(const Key& key);

		map& operator=(map &other);
		map& operator=(map &&other);
		T& operator[](const Key& key);
	
	private:
        BinaryTree<value_type> tree;

};

template<typename Key, typename T>
class map<Key, T>::MapIterator {
    public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = std::pair<const key_type, mapped_type>;

        MapIterator() = default;
       	MapIterator(typename BinaryTree<value_type>::iterator it);
        
        // Операторы инкремента и декремента
        MapIterator& operator++();
        MapIterator& operator--();
        MapIterator operator++(int);
        MapIterator operator--(int);

        // Операторы сравнения
        bool operator==(const MapIterator& other) const;
        bool operator!=(const MapIterator& other) const;

        // Операторы перемещения/сложения
        // SetIterator operator+(size_type n) const;
        // SetIterator operator-(size_type n) const;

        // Операторы доступа к элементам
        const_reference operator*() const;
    private:
        typename BinaryTree<value_type>::BinaryTreeIterator it_;
};

}  // namespace s21

#include "map.tpp"
#include "iterators.tpp"

#endif  // CPP2_S21_CONTAINERS_S21_CONTAINERS_MAP_MAP_H_
