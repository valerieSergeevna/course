#pragma once
#include "Iterator.h"
#include <iostream>



using namespace std;


template <class item> class stack
{
	item *Stack; int size_;
public:
	stack(int maxt) : Stack(new item[maxt]), size_(0) {};
	~stack();
	bool empty() const { return size_ == 0; }
	int size() const { return size_; }
	void push(item & item) { Stack[size_++] = item; }
	item top() const { return Stack[size_ - 1]; }
	void pop() { if (size_) --size_; }
};



template <class item>
stack<item>::~stack()
{
	free(Stack);
}

template <class item> class queue
{
	item *Queue; int head, tail, size_, Max;
public:
	queue(int maxQ) : head(0), tail(0), Max(maxQ), size_(0), Queue(new item[maxQ + 1]) {}
	~queue();
	bool empty() const { return (head % Max) == tail; }
	int size() const { return size_; }
	void push(item & item) { Queue[tail++] = item; tail %= Max; ++size_; }
	item front() const { return Queue[head % Max]; }
	void pop() { head++; head %= Max; --size_; }
};

template <class item>
queue<item>::~queue()
{
	free(Queue);
}

template <typename T >
class map
{
private:

	class node
	{

	public:
		node(T key, int id, node * next1 = nullptr, node * next2 = nullptr) {
			this->next_left = next1;
			this->next_right = next2;
			this->key = key;
			this->parent = nullptr;
			this->color = 1;
			this->id = id;
			this->code = {};

		};
		bool color;
		size_t id;
		string code;
		T key;
		node * next_right, *next_left, *parent;
		//unsigned int height;
		void Del();
		~node();

	};

	node * root;
	size_t size;
public:
	map();
	~map();


	class TreeIterator : public Iterator<T> {
	protected:
		node *current;
		TreeIterator(node* root) : current(root) { }

	public:
		bool operator==(const nullptr_t) const override { return current == nullptr; }
		bool operator!=(const nullptr_t) const override { return !operator==(nullptr); }
		size_t operator*() const override
		{
			return 1;
			//return current->frequancy;
		}
		T current_key()
		{
			return current->key;
		}
		bool current_color() { return current->color; }
		T current_code()
		{
			return current->code;
		}
		node *get_cur() { return current; }
		int current_id() { return current->id; }
	};



	class BftIterator : public TreeIterator {
	private:
		queue<node*> nodes;
	public:
		BftIterator(node *root, size_t size) : TreeIterator(root), nodes(size) {}
		void operator++(int) override;
	};


	void reset_list();


	node *get_successor(node *);


	void add_first(T);
	void remove(T);
	void delfix(node*);
	T find_city(int);
	int find_id(T);
	size_t get_size() { return size; }
	T get_colors();
	void get_value();
	void clear();
	bool insert(T, int);
	void insertfix(node *&t);
	void leftrotate(node *);
	void rightrotate(node *);
	BftIterator create_bft_iterator() { return BftIterator(root, size); }
};



template<typename T>
void map<T>::BftIterator::operator++(int)
{
	if (this->current->next_left != nullptr)
		nodes.push(this->current->next_left);
	if (this->current->next_right != nullptr)
		nodes.push(this->current->next_right);
	if (nodes.size() > 0) {
		this->current = nodes.front();
		nodes.pop();
	}
	else
		this->current = nullptr;
}