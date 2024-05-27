#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "WorkButton.h"
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;
using namespace sf;
template <class T>
class Tree {
private:
	Tree* left;
	Tree* right;
	Tree* parent;
	char data;
	int radius;
public:
	Tree(T); // ����������� � �������
	Tree(); // ����������� �� ���������
	~Tree(); // ����������
	T getData(); // ��������� ������
	void deleteLeft(); // �������� ����� �����
	void deleteRight(); // �������� ������ �����
	void insertLeft(T); // ������� ������ ���� � ����� ����� � ��������� ���������
	void insertRight(T); // ������� ������ ���� � ������ ����� � ��������� ���������
	vector<T> reorder(Tree<T>*, vector<T>&); // ������ ����� ������
	vector<T> inOrder(Tree<T>*, vector<T>&); // ������������ ����� ������
	vector<T> postOrder(Tree<T>*, vector<T>&); // �������� ����� ������
	void delete_tree() { delete this; }; // �������� ������
	void insert(T); // ������� ���� � ������ �����
	void erase(T); // ������ �������� ���� � ��������� ���������
	void addLeft(Tree<T>* temp) { left = temp; }; // ��������� ����� �����
	void addRight(Tree<T>* temp) { right = temp; }; // ��������� ������ �����
	void printVTree(int);// ������������ ������
	Tree<T>* replaceNullForEmpty(); // ������������ ������ �� �������� ���������
	int getHeight(); // ������ ������
	int amountNodes(); // ���������� ����� � ������
	Tree<T>* replaceHelp(Tree<T>* node, int H, int cur_level); // �������������� ������ �� ��������� � ������
	int getPos(int index, int width, int cur_level, int max_lelel); // ���������� �������� ��� ������� ����
	void ascendingOrder(vector<T>& result); // ����� ������ � ������� ����������� � ���������� �������� � �������
	Tree<T>* getLeft(); // ��������� �� ����� �����
	Tree<T>* getRight(); // ��������� �� ����� �����
	Tree<T>* getParent(); // ��������� �� ��������
	Tree<T>* copeTree(); // ����������� �������� ������
	Tree<T>* searchByKey(T); // ����� �������� �� �����
	Tree<T>* find(T); // ���������� ���� � ��������� ���������
	Tree<T>* prev(); // ��������� �� ���������� ����
	Tree<T>* next(); // ��������� �� ��������� ����
	Tree<T>* findMin(); // ����������� �������� �� ������
	Tree<T>* findMax(); // ������������ �������� �� ������
	Tree<T>* balancedTree(int); // ���������������� ������ �������� ������
};
template <class T>
Tree<T>::Tree(T data) { // ����������� �� ���������
	this->data = data;
	left = right = parent = nullptr;
}
template <class T>
Tree<T>::Tree() { // ����������� �� ���������
	left = right = parent = nullptr;
}
template <class T>
Tree<T>::~Tree() { // ����������
	deleteLeft();
	deleteRight();
}
template <class T>
T Tree<T>::getData() {
	return data;
}
template <class T>
Tree<T>* Tree<T>::getLeft() {
	return left;
}
template <class T>
Tree<T>* Tree<T>::getRight() {
	return right;
}
template <class T>
Tree<T>* Tree<T>::getParent() {
	return parent;
}
template <class T>
Tree<T>* Tree<T>::next() { // ��������� �� ��������� ����
	Tree<T>* current = this; // ��������� �� ������� ����
	if (current->right != nullptr) { // ���� ������ ����� ����������
		return current->right->findMin();
	}
	Tree<T>* tmp = current->parent;
	while (tmp != nullptr && current == tmp->right) {
		current = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}
template <class T>
Tree<T>* Tree<T>::prev() { // ��������� �� ���������� ����
	if (left != nullptr) { // ���� ����� ����� ����������
		Tree<T>* tmp = left; // ��������� �� ����� �����
		while (tmp->right != nullptr) { // ���� ������ ����� ����������
			tmp = tmp->right;
		}
		return tmp;
	}
	else {
		Tree<T>* tmp = this; // ��������� �� ������� ����
		while (tmp->parent != nullptr && tmp->parent->left == tmp) {
			tmp = tmp->parent;
		}
		return tmp->parent;
	}
}
template <class T>
void Tree<T>::insert(T data) {
	Tree<T>* current = this; // ������� ����
	while (current != nullptr) { // ���� ���� ����������
		if (data > current->data) { // ���� ������ ������ ������ � ������� ����
			if (current->right != nullptr) {
				current = current->right;
			}
			else { // ���� ������ ����� ���
				current->insertRight(data);
				return;
			}
		}
		else if (data < current->data) { // ���� ������ ������ ������ � ������� ����
			if (current->left != nullptr) {
				current = current->left;
			}
			else {
				current->insertRight(data);
				return;
			}
		}
	}
}
template <class T>
void Tree<T>::insertRight(T data) { // ������� ������ ���� � ������ ����� � ��������� ���������
	Tree<T>* new_node = new Tree(data); // ����� ������ � �������
	if (this->right != nullptr) {
		this->right->parent = new_node;
		new_node->right = this->right; // ������ ����� ������������� ����� ���������
	}
	this->right = new_node;
	new_node->parent = this;
}
template <class T>
void Tree<T>::insertLeft(T data) { // ������� ������ ���� � ������ ����� � ��������� ���������
	Tree<T>* new_node = new Tree<T>(data); // ����� ������ � �������
	if (this->left != nullptr) {
		this->left->parent = new_node;
		new_node->left = this->left; // ������ ����� ������������� ����� ���������
	}
	this->left = new_node;
	new_node->parent = this;
}
template <class T>
vector<T> Tree<T>::reorder(Tree<T>* current, vector<T>& vect) { // ������ �����
	if (current == nullptr) {
		return vect;
	}
	else {
		vect.push_back(current->getData());
		reorder(current->getLeft(), vect);
		reorder(current->getRight(), vect);
	}
	return vect;
}
template <class T>
vector<T> Tree<T>::inOrder(Tree<T>* tree, vector<T>& vect) { // ������������ �����
	if (tree != nullptr) {
		inOrder(tree->left, vect);
		vect.push_back(tree->getData());
		inOrder(tree->right, vect);
	}
	return vect;
}
template <class T>
vector<T> Tree<T>::postOrder(Tree<T>* tree, vector<T>& vect) { // �������� �����
	if (tree != nullptr) {
		postOrder(tree->left, vect);
		postOrder(tree->right, vect);
		vect.push_back(tree->getData());
	}
	return vect;
}
template <class T>
int Tree<T>::getHeight() { // ������ ������
	int h1 = 0, h2 = 0;
	if (this == NULL) { // ���� ������ ������
		return 0;
	}
	if (this->left != NULL) { // ���� ����� ����� �� ������
		h1 = this->left->getHeight();
	}
	if (this->right != NULL) { // ���� ����� ����� �� ������
		h2 = this->right->getHeight();
	}
	if (h1 >= h2) {
		return h1 + 1;
	}
	return h2 + 1;
}
template <class T>
int Tree<T>::amountNodes() { // ���������� ����� � ������
	if (this == NULL) {
		return 0;
	}
	if ((this->left == NULL) && (this->right == NULL)) {
		return 1;
	}
	int left_branch = 0, right_branch = 0;
	if (this->left != NULL) { // ���� ����� ����� ����������
		left_branch = this->left->amountNodes();
	}
	if (this->right != NULL) { // ���� ������ ����� ����������
		right_branch = this->right->amountNodes();
	}
	return (left_branch + right_branch + 1);
}
template <class T>
Tree<T>* Tree<T>::replaceNullForEmpty() { // �������������� ������ �� ��������� � ������
	Tree<T>* node = this->copeTree();
	int H = node->getHeight(); // ���������� ������ ������
	node = replaceHelp(node, H, 0); // ���������� ������ ������� ������
	return node;
}

template <class T>
Tree<T>* Tree<T>::replaceHelp(Tree<T>* node, int H, int cur_level) {
	if ((node->getLeft() == NULL) && (cur_level != H - 1)) { // ���� ����� ������ � ������ �� ��������
		node->insertLeft(NULL);
	}
	if ((node->getRight() == NULL) && (cur_level != H - 1)) {
		node->insertRight(NULL);
	}
	if (node->getLeft() != NULL) { // ���� ����� ����� ����������
		node->addLeft(replaceHelp(node->getLeft(), H, cur_level + 1));
	}
	if (node->getRight() != NULL) { // ���� ������ ����� ����������
		node->addRight(replaceHelp(node->getRight(), H, cur_level + 1));
	}
	return node;
}

template <class T>
int Tree<T>::getPos(int index, int width, int cur_level, int max_level) {
	int x1 = 0, x2 = pow(2, cur_level) - 1;
	int y1 = width / pow(2, cur_level + 1), y2 = width - pow(2, max_level - cur_level);
	if (x1 == x2) {
		return y1;
	}
	double k = (y1 - y2) / (x1 - x2);
	double m = -x1 * k + y1;
	int y = (int)(k * index + m);
	return y;
}
template <class T>
Tree<T>* Tree<T>::balancedTree(int count) { // �������� ����������������� ������
	if (count <= 0) {
		return nullptr;
	}
	T data;
	cout << "������� ������ ��� ����������������� ������: ";
	cin >> data;
	Tree<T>* tmp = new Tree<T>(data);
	tmp->addLeft(balancedTree(count / 2));
	tmp->addRight(balancedTree(count - count / 2 - 1));
	return tmp;
}
template <class T>
void Tree<T>::erase(T data) { // �������� ���� �� ������
	Tree<T>* to_erase = this->find(data);
	Tree<T>* to_parent = to_erase->parent;
	if (to_erase->left == nullptr && to_erase->right == nullptr) {
		if (to_parent->left == to_erase) {
			to_parent->left = nullptr;
		}
		else {
			to_parent->right = nullptr;
		}
		delete to_erase;
	}
	else if ((to_erase->left != nullptr && to_erase->right == nullptr) || (to_erase->left == nullptr && to_erase->right
		!= nullptr)) {
		if (to_erase->left == nullptr) {
			if (to_erase == to_parent->left) {
				to_parent->left = to_erase->right; // ������������� ����� ����� �����
			}
			else {
				to_parent->right = to_erase->right; // ������������� ����� ������ �����
			}
			to_parent->right->parent = to_parent; // ������������� ������ �������� ��� ������ �����
		}
		else {
			if (to_erase == to_parent->left) {
				to_parent->left = to_erase->left; // ������������� ����� ����� �����
			}
			else {
				to_parent->right = to_erase->left; // ������������� ����� ������ �����
			}
			to_parent->left->parent = to_parent; // ������������� ������ �������� ��� ����� �����
		}
	}
	else {
		Tree<T>* next = to_erase->next(); // ��������� ���������� �����
		to_erase->data = next->data;
		if (next == next->parent->left) {
			next->parent->left = next->right;
			if (next->right != nullptr) {
				next->right->parent = next->parent;
			}
		}
		else {
			next->parent->right = next->right;
			if (next->right != nullptr) {
				next->right->parent = next->parent; // ������������� ������ �������� ��� ������ �����
			}
		}
		delete next;
	}
}
template <class T>
void Tree<T>::deleteLeft() { // �������� ������ ����
	if (left != NULL) {
		left->deleteLeft();
		left->deleteRight();
		delete left;
	}
}
template <class T>
void Tree<T>::deleteRight() { // �������� ������� ����
	if (right != NULL) {
		right->deleteLeft();
		right->deleteRight();
		delete right;
	}
}

template <class T>
Tree<T>* Tree<T>::searchByKey(T key) { // ����� �� �����
	if (data == key) {
		return this;
	}
	if (left != nullptr) {
		Tree<T>* result = left->searchByKey(key);
		if (result != nullptr) {
			return result; // ����������� ���������
		}
	}
	if (right != nullptr) {
		Tree<T>* result = right->searchByKey(key);
		if (result != nullptr) {
			return result;// ����������� ���������
		}
	}
	return nullptr;// ����������� ���������
}
template <class T>
Tree<T>* Tree<T>::find(T data) { // ����� ���� �� ������
	if (this == nullptr || this->data == data) {
		return this;
	}
	else if (data > this->data) {
		return this->right->find(data);
	}
	else {
		return this->left->find(data);
	}
}
template <class T>
Tree<T>* Tree<T>::findMax() { // ����� ������������� ��������
	if (this->right == nullptr) { // ���� ������ ��� ������ �����
		return this;
	}
	return this->right->findMax();
}
template <class T>
Tree<T>* Tree<T>::findMin() { // ����� ������������ ��������
	Tree<T>* min_node = this;
	while (min_node->left != nullptr) { // ���� ������ ��� ����� �����
		min_node = min_node->left;
	}
	return min_node;
}
template <class T>
void Tree<T>::ascendingOrder(vector<T>& result) { // ����� ������ � ������� ����������� � ���������� �������� � �������
	if (left != nullptr) {
		left->ascendingOrder(result);
	}
	result.push_back(data);
	if (right != nullptr) {
		right->ascendingOrder(result);
	}
}

template <class T>
Tree<T>* Tree<T>::copeTree() { // ����� ������
	Tree<T>* new_tree = new Tree<T>(data);
	if (left != nullptr) {
		new_tree->left = left->copeTree();
		new_tree->left->parent = new_tree;
	}
	if (right != nullptr) {
		new_tree->right = right->copeTree();
		new_tree->right->parent = new_tree;
	}
	return new_tree;
}
struct pos {
	int column;
	int row; 
};
void printSpaces(int start, int end) {
	for (int j = start; j < end; j++) { // ������� �� ����
		cout << " ";
	}
}
template <class T>
void Tree<T>::printVTree(int k) {
	int height = this->getHeight();
	int max_leafs = pow(2, height - 1);
	int width = 2 * max_leafs - 1; // ����������� ������ ������
	int cur_level = 0;
	int index = 0;
	int fact_spaces = getPos(index, width, cur_level, height - 1); // ����� �������� ����� ������
	pos node; // ����������� ��������� ��� �������� ������� ����
	vector<Tree<T>*> vect_1;
	vector<pos> vect_2;
	Tree<T>* tree_2 = this->copeTree();
	tree_2 = tree_2->replaceNullForEmpty(); // ������������ ������ �� ���������
	Tree<T>* tree_3 = tree_2;
	vect_1.push_back(tree_3);
	node.column = fact_spaces; // ����� �������� ����� ������
	node.row = cur_level;
	vect_2.push_back(node);
	for (int i = 0; i < tree_2->amountNodes(); i++) { // ������� ���� ����� ������
		if (pow(2, cur_level) <= index + 1) {
			index = 0;
			cur_level++;
		}
		if (vect_1.at(i)->left != NULL) { // �������� ������� ������ �������
			vect_1.push_back(vect_1.at(i)->left);
			fact_spaces = getPos(index, width, cur_level, height - 1); // ���������� ���������� �������� ����� ����� ������
			node.column = fact_spaces; // ���������� ������� ������ ����
			node.row = cur_level;
			vect_2.push_back(node);
			index++;
		}
		if (vect_1.at(i)->right != NULL) { // �������� ������� ������� �������
			vect_1.push_back(vect_1.at(i)->right); // ���������� ������� � ������
			fact_spaces = getPos(index, width, cur_level, height - 1); // ���������� ���������� �������� ����� ����� �����
			node.column = fact_spaces; // ���������� ������� ������ ����
			node.row = cur_level;
			vect_2.push_back(node);
			index++;
		}
	}
	for (int i = vect_1.size() - 1; i >= 0; i--) {
		if (i != 0) {
			if (vect_2.at(i - 1).row == vect_2.at(i).row) {
				vect_2.at(i).column = vect_2.at(i).column - vect_2.at(i - 1).column - 1;
			}
		}
	}
	int flag = 0;
	for (int i = 0; i < vect_1.size(); i++) {
		node = vect_2.at(i);
		cur_level = node.row;
		if (flag < cur_level) {
			flag = cur_level;
			cout << endl; // ������� �� ����� ������
		}
		fact_spaces = node.column; // ����� �������� ����� �����
		int real_spaces = k * fact_spaces;
		printSpaces(0, real_spaces);
		if (vect_1.at(i)->getData() == NULL) {
			cout << " ";
		}
		else {
			cout << vect_1.at(i)->getData(); // ����� ����
		}
		printSpaces(0, k);
	}
	cout << endl;
}
void printInConsol() { // ������� ������ ������ ����������� � �������
	Tree<char>* tree = new Tree<char>('k');
	tree->insertLeft('u');
	tree->getLeft()->insertLeft('l');
	tree->getLeft()->insertRight('c');
	tree->insertRight('!');
	tree->getRight()->insertRight('!');
	tree->getRight()->insertLeft('y');
	cout << "������������ ������" << endl; 
	tree->printVTree(2);
}