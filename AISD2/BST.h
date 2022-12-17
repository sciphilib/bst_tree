#pragma once

template<typename Tk, typename Td>
class BST {
public:
	class Node;
	class Iterator;
	class Reverse_iterator;

	BST();
	BST(const BST& tree);
	~BST();
	bool insert(Tk key, Td data = 0);
	bool is_empty();
	bool remove(Tk key);
	Td* get_data(Tk key);
	void postorder_print();
	void inorder_print();
	void print();
	void clear();
	int get_size() const;
	int bal(Node* node);
	Reverse_iterator rbegin();
	Reverse_iterator rend();
	Iterator begin();
	Iterator end();

protected:
	class Node {
	public:
		Tk key;
		Td data;
		Node* left;
		Node* right;
		Node(Tk k, Td d) : key(k), data(d), left(nullptr), right(nullptr) {};
	};
public:
	class Iterator {
		friend class BST;
	public:
		Iterator(BST* tree);
		Iterator(const Iterator &iter);
		Iterator operator++(int);
		void operator++();
		bool operator==(const Iterator& iter) const;
		bool operator!=(const Iterator& iter) const;
		Td& operator*();
	public:
		BST* tree;
		Node* cur;
	};
	class Reverse_iterator {
		friend class BST;
	public:
		Reverse_iterator(BST* tree);
		Reverse_iterator(const Reverse_iterator& iter);
		Reverse_iterator operator++(int);
		Reverse_iterator operator--(int);
		void operator++();
		bool operator==(const Reverse_iterator& iter) const;
		bool operator!=(const Reverse_iterator& iter) const;
		Td& operator*();
	public:
		BST* tree;
		Node* cur;
	};

private:
	Node* insert(Node* root, Tk key, Td data, bool& is_inserted);
	Node* create_node(Tk key, Td data);
	void inorder_print(Node* root);
	void postorder_print(Node* root);
	void delete_tree(Node* node);
	Node* search(Node* root, Tk key);
	Node* remove(Node* node, Tk key, bool& is_deleted);
	Node* del(Node* t, Node* t0);
	int height(Node* node);
	void print(Node* root, int level);
	void inorder_insert(Node* node);

	// reverse iterator 
	Node* bst_predecessor(Node* root, Node* node);
	Node* max(Node* node);
	Node* r_parent(Node* root, Node* node);
	// iterator
	Node* bst_succsessor(Node* root, Node* node);
	Node* min(Node* node);
	Node* l_parent(Node* root, Node* node);

	int size; // count of elements with data
	Node* root; // root of BST
};

template<typename Tk, typename Td>
BST<Tk, Td>::BST()
	: size(0), root(nullptr)
{
}


// todo
template<typename Tk, typename Td>
BST<Tk, Td>::BST(const BST& tree)
{
	inorder_insert(tree.root);
}

template<typename Tk, typename Td>
void BST<Tk, Td>::inorder_insert(Node* node)
{
	if (node != nullptr)
	{
		inorder_insert(node->left);
		insert(node->key, node->data);
		inorder_insert(node->right);
	}
}

template<typename Tk, typename Td>
BST<Tk, Td>::~BST()
{
	delete_tree(root);
}

template<typename Tk, typename Td>
void BST<Tk, Td>::delete_tree(Node* node)
{
	if (node != nullptr)
	{
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
	}
}
template<typename Tk, typename Td>
typename BST<Tk, Td>::Node* BST<Tk, Td>::insert(Node* t, Tk key, Td data, bool &is_inserted)
{
	bool is_ins;

	if (t == nullptr)
	{
		is_ins = true;
		size++;
		return create_node(key, data);
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
bool BST<Tk, Td>::insert(Tk key, Td data)
{
	bool is_inserted = false;

	//if (size == 0)
	//	root = insert(root, key, data, is_inserted);
	//else
	//	insert(root, key, data, is_inserted);
	root = insert(root, key, data, is_inserted);
	return is_inserted;
}

template<typename Tk, typename Td>
inline bool BST<Tk, Td>::is_empty()
{
	return root == nullptr && size == 0 ? true : false;
}

template<typename Tk, typename Td>
inline bool BST<Tk, Td>::remove(Tk key)
{
	bool is_inserted;
	remove(root, key, is_inserted);
	return is_inserted;
}

template<typename Tk, typename Td>
int BST<Tk, Td>::get_size() const
{
	return size;
}

template<typename Tk, typename Td>
typename BST<Tk, Td>::Node* BST<Tk, Td>::create_node(Tk key, Td data)
{
	return new Node(key, data);
}

template<typename Tk, typename Td>
void BST<Tk, Td>::inorder_print()
{
	inorder_print(root);
}

template<typename Tk, typename Td>
void BST<Tk, Td>::inorder_print(Node* node)
{
	if (node != nullptr)
	{
		inorder_print(node->left);
		std::cout << node->key << ' ';
		inorder_print(node->right);
	}
}

template<typename Tk, typename Td>
void BST<Tk, Td>::postorder_print()
{
	postorder_print(root);
}

template<typename Tk, typename Td>
void BST<Tk, Td>::postorder_print(Node* node)
{
	if (node != nullptr)
	{
		postorder_print(node->left);
		postorder_print(node->right);
		std::cout << node->key << ' ';
	}
}

template<typename Tk, typename Td>
inline void BST<Tk, Td>::print()
{
	print(root, 0);
}

template<typename Tk, typename Td>
inline int BST<Tk, Td>::bal(Node* node)
{
	return height(node->right) - height(node->left);
}

template<typename Tk, typename Td>
inline void BST<Tk, Td>::clear()
{
	size = 0;
	delete_tree(root);
	root = nullptr;
}

template<typename Tk, typename Td>
typename BST<Tk, Td>::Iterator BST<Tk, Td>::begin()
{
	auto first_element = root;
	while (first_element->left != nullptr)
		first_element = first_element->left;

	Iterator iter(this);
	iter.cur = first_element;
	return iter;
}

template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Iterator BST<Tk, Td>::end()
{
    Iterator iter(this);
	iter.cur = nullptr;
	return iter;
}

template<typename Tk, typename Td>
typename BST<Tk, Td>::Reverse_iterator BST<Tk, Td>::rbegin()
{
	auto first_element = root;
	while (first_element->right != nullptr)
		first_element = first_element->right;

	Reverse_iterator iter(this);
	iter.cur = first_element;
	return iter;
}

template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Reverse_iterator BST<Tk, Td>::rend()
{
	Reverse_iterator iter(this);
	iter.cur = nullptr;
	return iter;
}

template<typename Tk, typename Td>
typename BST<Tk, Td>::Node* BST<Tk, Td>::search(Node* root, Tk key)
{
	if (root != nullptr)
	{
		if (key == root->key)
			return root;
		if (key <= root->key)
			return search(root->left, key);
		else
			return search(root->right, key);
	}
	return nullptr;
}

template<typename Tk, typename Td>
Td* BST<Tk, Td>::get_data(Tk key)
{
	auto desired = search(root, key);
	if (desired != nullptr)
		return &desired->data;
	else
		return nullptr;
}

template<typename Tk, typename Td>
typename BST<Tk, Td>::Node* BST<Tk, Td>::remove(Node* node, Tk key, bool &is_deleted)
{
	bool is_del = false;

	if (node == nullptr)
	{
		is_del = false;
		return nullptr;
	}
	if (key < node->key)
	{
		node->left = remove(node->left, key, is_del);
		is_deleted = is_del;
		return node;
	}
	if (key > node->key)
	{
		node->right = remove(node->right, key, is_del);
		is_deleted = is_del;
		return node;
	}

	is_deleted = true;

	// 1. no sons
	if (node->left == nullptr && node->right == nullptr)
	{
		delete node;
		return nullptr;
	}
	// 2. one right son
	if (node->left == nullptr)
	{
		auto temp = node->right;
		delete node;
		return temp;
	}
	// 2.one left son
	if (node->right == nullptr)
	{
		auto temp = node->left;
		delete node;
		return temp;
	}
	// 3. else two sons
	node->right = del(node->right, node);
	return node;
}

template<typename Tk, typename Td>
typename BST<Tk, Td>::Node* BST<Tk, Td>::del(Node* t, Node* t0)
{
	if (t->left != nullptr)
	{
		t->left = del(t->left, t0);
		return t;
	}
	t0->key = t->key;
	t0->data = t->data;
	auto temp = t->right;
	delete t;
	return temp;
}

template<typename Tk, typename Td>
inline int BST<Tk, Td>::height(Node* node)
{
	//int left = 0, right = 0;
	//if (node == nullptr)
	//	return 0;

	//if (node->left != nullptr)
	//	left = 1 + height(node->left);
	//if (node->right != nullptr)
	//	right = 1 + height(node->right);

	//return std::max(left, right);
	
	
	// базовый случай: пустое дерево имеет высоту 0
	if (node == nullptr) {
		return 0;
	}

	return 1 + std::max(height(node->left), height(node->right));
}

template<typename Tk, typename Td>
inline void BST<Tk, Td>::print(Node* root, int level)
{
	if (root == nullptr)
		return;

	print(root->right, level + 1);
	for (int i = 0; i < level; ++i)
		std::cout << "    ";
	std::cout << root->key << ',' << root->data << '\n';
	print(root->left, level + 1);
	return;
}

// =======================================================================
// 
// 
// Iterator
// 
// 
// =======================================================================

template<typename Tk, typename Td>
inline BST<Tk, Td>::Iterator::Iterator(BST* tree)
{
	this->tree = tree;
	cur = nullptr;
}

template<typename Tk, typename Td>
inline BST<Tk, Td>::Iterator::Iterator(const Iterator& iter)
{
	tree = iter.tree;
	cur = iter.cur;
}

template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Iterator BST<Tk, Td>::Iterator::operator++(int)
{
	Iterator iter(*this);
	++(*this);
	return iter;
}

template<typename Tk, typename Td>
inline void BST<Tk, Td>::Iterator::operator++()
{
	if (cur != nullptr)
		cur = tree->bst_succsessor(tree->root, cur);
}

template<typename Tk, typename Td>
inline bool BST<Tk, Td>::Iterator::operator==(const Iterator& iter) const
{
	return tree == iter.tree && cur == iter.cur;
}

template<typename Tk, typename Td>
inline bool BST<Tk, Td>::Iterator::operator!=(const Iterator& iter) const
{
	return tree != iter.tree || cur != iter.cur;
}

template<typename Tk, typename Td>
inline Td& BST<Tk, Td>::Iterator::operator*()
{
	if (cur == nullptr)
		throw std::exception();
	else
		return cur->key;
}

template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Node* BST<Tk, Td>::bst_succsessor(Node* root, Node* node)
{
	if (node->right != nullptr)
		return min(node->right);
	else
		return l_parent(root, node);
}


// поиск максимального по ключу узла в левом поддереве 
template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Node* BST<Tk, Td>::min(Node* node)
{
	if (node->left == nullptr)
		return node;
	else
		min(node->left);
}

// поиск ближайшего правого родителя для заданного узла дерева
template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Node* BST<Tk, Td>::l_parent(Node* root, Node* node)
{
	if (root == node)
		return nullptr;

	if (node->key < root->key)
	{
		auto left_parent = l_parent(root->left, node);
		if (left_parent == nullptr)
			return root;
		else
			return left_parent;
	}
	else
		l_parent(root->right, node);
}

// =======================================================================
// 
// 
// Reverse iterator
// 
// 
// =======================================================================

template<typename Tk, typename Td>
inline BST<Tk, Td>::Reverse_iterator::Reverse_iterator(BST<Tk, Td>* tree)
{
	this->tree = tree;
	cur = nullptr;
}

template<typename Tk, typename Td>
inline BST<Tk, Td>::Reverse_iterator::Reverse_iterator(const Reverse_iterator& iter)
{
	tree = iter.tree;
	cur = iter.cur;
}

template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Reverse_iterator BST<Tk, Td>::Reverse_iterator::operator--(int)
{
	return Reverse_iterator();
}

// todo обработка nullptr
template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Reverse_iterator BST<Tk, Td>::Reverse_iterator::operator++(int)
{
	Reverse_iterator iter(*this);
	++(*this);
	return iter;
}

// todo обработка nullptr
template<typename Tk, typename Td>
inline void BST<Tk, Td>::Reverse_iterator::operator++()
{
	if (cur != nullptr)
		cur = tree->bst_predecessor(tree->root, cur);
}

template<typename Tk, typename Td>
inline bool BST<Tk, Td>::Reverse_iterator::operator==(const Reverse_iterator& iter) const
{
	return tree == iter.tree && cur == iter.cur;
}

template<typename Tk, typename Td>
inline bool BST<Tk, Td>::Reverse_iterator::operator!=(const Reverse_iterator& iter) const
{
	return tree != iter.tree || cur != iter.cur;
}

template<typename Tk, typename Td>
inline Td& BST<Tk, Td>::Reverse_iterator::operator*()
{
	if (cur == nullptr)
		throw std::exception();
	else
		return cur->key;
}

template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Node* BST<Tk, Td>::bst_predecessor(Node* root, Node* node)
{
	if (node->left != nullptr)
		return max(node->left);
	else
		return r_parent(root, node);
}


// поиск максимального по ключу узла в левом поддереве 
template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Node* BST<Tk, Td>::max(Node* node)
{
	if (node->right == nullptr)
		return node;
	else
		max(node->right);
}

// поиск ближайшего правого родителя для заданного узла дерева
template<typename Tk, typename Td>
inline typename BST<Tk, Td>::Node* BST<Tk, Td>::r_parent(Node* root, Node* node)
{
	if (root == node)
		return nullptr;

	if (node->key > root->key)
	{
		auto right_parent = r_parent(root->right, node);
		if (right_parent == nullptr)
			return root;
		else
			return right_parent;
	}
	else
		r_parent(root->left, node);
}
