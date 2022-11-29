#pragma once

template<typename Tk, typename Td>
class BST
{
public:
	class Node;
	BST();
	BST(const BST& tree);
	~BST();
	Node* insert(Node* root, Tk key, Td data, bool &is_inserted);
	Node* create_node(Tk key, Td data);
	int get_size() const;

protected:
	class Node {
	public:
		Tk item;
		Td data;
		Node* left;
		Node* right;
		Node(Tk k, Td d) : item(k), data(d), left(nullptr), right(nullptr) {};
	};

	class Iterator {
	public:
		Iterator();
		Iterator(Node* node);
	private:
		BST* tree;
		Node* cur;
	};

	class ReverseIterator {
	public:
		Reverse_iterator();
		Reverse_iterator(Node* node);
	private:
		BST* tree;
		Node* cur;
	};
private:
	int size; // count of elements with data
	Node* root; // root of BST
};

template<typename Tk, typename Td>
BST<Tk, Td>::BST()
	: size(0), root(nullptr)
{
}

template<typename Tk, typename Td>
BST<Tk, Td>::BST(const BST& tree)
	: size(tree.size)
{
	//todo
}

template<typename Tk, typename Td>
BST<Tk, Td>::Node* BST<Tk, Td>::insert(Node* t, Tk key, Td data, bool &is_inserted)
{
	bool is_ins;

	if (t == nullptr)
	{
		is_ins = true;
		size++;
		return create_node();
	}
	if (key == t->key)
	{
		is_ins = false;
		return t;
	}

	if (key < t->key)
		t->left = insert(t->left, key, data, is_ins);
	else
		t->right = insert(t->right, key, data, is_ins);

	is_inserted = is_ins;
	return t;
}

template<typename Tk, typename Td>
int BST<Tk, Td>::get_size() const
{
	return size;
}

template<typename Tk, typename Td>
BST<Tk, Td>::Node* BST<Tk, Td>::create_node(Tk key, Td data)
{
	return new Node(key, data);
}