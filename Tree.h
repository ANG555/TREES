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
	Tree(T); // конструктор с данными
	Tree(); // конструктор по умолчанию
	~Tree(); // деструктор
	T getData(); // получение данных
	void deleteLeft(); // удаление левой ветки
	void deleteRight(); // удаление правой ветки
	void insertLeft(T); // вставка нового узла в левую ветвь с указанным значением
	void insertRight(T); // вставка нового узла в правую ветвь с указанным значением
	vector<T> reorder(Tree<T>*, vector<T>&); // прямой обход дерева
	vector<T> inOrder(Tree<T>*, vector<T>&); // симметричный обход дерева
	vector<T> postOrder(Tree<T>*, vector<T>&); // обратный обход дерева
	void delete_tree() { delete this; }; // удаление дерева
	void insert(T); // вставка узла в нужное место
	void erase(T); // полное удаление узла с указанным значением
	void addLeft(Tree<T>* temp) { left = temp; }; // установка левой ветви
	void addRight(Tree<T>* temp) { right = temp; }; // установка правой ветви
	void printVTree(int);// вертикальная печать
	Tree<T>* replaceNullForEmpty(); // достраивание дерева до идеально симметрии
	int getHeight(); // высота дерева
	int amountNodes(); // количество узлов в дереве
	Tree<T>* replaceHelp(Tree<T>* node, int H, int cur_level); // преобразование дерева из неполного в полное
	int getPos(int index, int width, int cur_level, int max_lelel); // количество пробелов для данного узла
	void ascendingOrder(vector<T>& result); // обход дерева в порядке возрастания и сохранение значений в векторе
	Tree<T>* getLeft(); // указатель на левую ветвь
	Tree<T>* getRight(); // указатель на левую ветвь
	Tree<T>* getParent(); // указатель на родителя
	Tree<T>* copeTree(); // копирование текущего дерева
	Tree<T>* searchByKey(T); // поиск элемента по ключу
	Tree<T>* find(T); // нахождение узла с указанным значением
	Tree<T>* prev(); // указатель на предыдущий узел
	Tree<T>* next(); // указатель на следующий узел
	Tree<T>* findMin(); // минимальное значение из дерева
	Tree<T>* findMax(); // максимальное значение из дерева
	Tree<T>* balancedTree(int); // сбалансированное дерево заданной высоты
};
template <class T>
Tree<T>::Tree(T data) { // конструктор со значением
	this->data = data;
	left = right = parent = nullptr;
}
template <class T>
Tree<T>::Tree() { // конструктор по умолчанию
	left = right = parent = nullptr;
}
template <class T>
Tree<T>::~Tree() { // деструктор
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
Tree<T>* Tree<T>::next() { // указатель на следующий узел
	Tree<T>* current = this; // указатель на текущий узел
	if (current->right != nullptr) { // если правая ветвь существует
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
Tree<T>* Tree<T>::prev() { // указатель на предыдущмй узел
	if (left != nullptr) { // если левая ветвь существует
		Tree<T>* tmp = left; // указатель на левую ветвь
		while (tmp->right != nullptr) { // пока правая ветвь существует
			tmp = tmp->right;
		}
		return tmp;
	}
	else {
		Tree<T>* tmp = this; // указатель на текущий узел
		while (tmp->parent != nullptr && tmp->parent->left == tmp) {
			tmp = tmp->parent;
		}
		return tmp->parent;
	}
}
template <class T>
void Tree<T>::insert(T data) {
	Tree<T>* current = this; // текущий узел
	while (current != nullptr) { // пока узел существует
		if (data > current->data) { // если данные больше данных в текущем узле
			if (current->right != nullptr) {
				current = current->right;
			}
			else { // если правой ветви нет
				current->insertRight(data);
				return;
			}
		}
		else if (data < current->data) { // если данные меньше данных в текущем узле
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
void Tree<T>::insertRight(T data) { // вставка нового узла в правую ветвь с указанным значением
	Tree<T>* new_node = new Tree(data); // новой дерево с данными
	if (this->right != nullptr) {
		this->right->parent = new_node;
		new_node->right = this->right; // правой ветви присваивается новое поддерево
	}
	this->right = new_node;
	new_node->parent = this;
}
template <class T>
void Tree<T>::insertLeft(T data) { // вставка нового узла в правую ветвь с указанным значением
	Tree<T>* new_node = new Tree<T>(data); // новое дерево с данными
	if (this->left != nullptr) {
		this->left->parent = new_node;
		new_node->left = this->left; // правой ветви присваивается новое поддерево
	}
	this->left = new_node;
	new_node->parent = this;
}
template <class T>
vector<T> Tree<T>::reorder(Tree<T>* current, vector<T>& vect) { // прямой обход
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
vector<T> Tree<T>::inOrder(Tree<T>* tree, vector<T>& vect) { // симметричный обход
	if (tree != nullptr) {
		inOrder(tree->left, vect);
		vect.push_back(tree->getData());
		inOrder(tree->right, vect);
	}
	return vect;
}
template <class T>
vector<T> Tree<T>::postOrder(Tree<T>* tree, vector<T>& vect) { // обратный обход
	if (tree != nullptr) {
		postOrder(tree->left, vect);
		postOrder(tree->right, vect);
		vect.push_back(tree->getData());
	}
	return vect;
}
template <class T>
int Tree<T>::getHeight() { // высота дерева
	int h1 = 0, h2 = 0;
	if (this == NULL) { // если дерево пустое
		return 0;
	}
	if (this->left != NULL) { // если левая ветвь не пустая
		h1 = this->left->getHeight();
	}
	if (this->right != NULL) { // если левая ветвь не пустая
		h2 = this->right->getHeight();
	}
	if (h1 >= h2) {
		return h1 + 1;
	}
	return h2 + 1;
}
template <class T>
int Tree<T>::amountNodes() { // количество узлов в дереве
	if (this == NULL) {
		return 0;
	}
	if ((this->left == NULL) && (this->right == NULL)) {
		return 1;
	}
	int left_branch = 0, right_branch = 0;
	if (this->left != NULL) { // если левая ветвь существует
		left_branch = this->left->amountNodes();
	}
	if (this->right != NULL) { // если правая ветвь существует
		right_branch = this->right->amountNodes();
	}
	return (left_branch + right_branch + 1);
}
template <class T>
Tree<T>* Tree<T>::replaceNullForEmpty() { // преобразование дерева из неполного в полное
	Tree<T>* node = this->copeTree();
	int H = node->getHeight(); // вычисление высоты дерева
	node = replaceHelp(node, H, 0); // дополнение дерева пустыми узлами
	return node;
}

template <class T>
Tree<T>* Tree<T>::replaceHelp(Tree<T>* node, int H, int cur_level) {
	if ((node->getLeft() == NULL) && (cur_level != H - 1)) { // если ветвь пустая и высота не конечная
		node->insertLeft(NULL);
	}
	if ((node->getRight() == NULL) && (cur_level != H - 1)) {
		node->insertRight(NULL);
	}
	if (node->getLeft() != NULL) { // если левая ветвь существует
		node->addLeft(replaceHelp(node->getLeft(), H, cur_level + 1));
	}
	if (node->getRight() != NULL) { // если правая ветвь существует
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
Tree<T>* Tree<T>::balancedTree(int count) { // создание сбалансированного дерева
	if (count <= 0) {
		return nullptr;
	}
	T data;
	cout << "Введите данные для сбалансированного дерева: ";
	cin >> data;
	Tree<T>* tmp = new Tree<T>(data);
	tmp->addLeft(balancedTree(count / 2));
	tmp->addRight(balancedTree(count - count / 2 - 1));
	return tmp;
}
template <class T>
void Tree<T>::erase(T data) { // удаление узла по данным
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
				to_parent->left = to_erase->right; // устанавливаем новую левую ветвь
			}
			else {
				to_parent->right = to_erase->right; // устанавливаем новую правую ветвь
			}
			to_parent->right->parent = to_parent; // устанавливаем нового родителя для правой ветви
		}
		else {
			if (to_erase == to_parent->left) {
				to_parent->left = to_erase->left; // устанавливаем новую левую ветвь
			}
			else {
				to_parent->right = to_erase->left; // устанавливаем новую правую ветвь
			}
			to_parent->left->parent = to_parent; // устанавливаем нового родителя для левой ветви
		}
	}
	else {
		Tree<T>* next = to_erase->next(); // получение следующего узела
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
				next->right->parent = next->parent; // устанавливаем нового родителя для правой ветви
			}
		}
		delete next;
	}
}
template <class T>
void Tree<T>::deleteLeft() { // удаление левого узла
	if (left != NULL) {
		left->deleteLeft();
		left->deleteRight();
		delete left;
	}
}
template <class T>
void Tree<T>::deleteRight() { // удаление правого узла
	if (right != NULL) {
		right->deleteLeft();
		right->deleteRight();
		delete right;
	}
}

template <class T>
Tree<T>* Tree<T>::searchByKey(T key) { // поиск по ключу
	if (data == key) {
		return this;
	}
	if (left != nullptr) {
		Tree<T>* result = left->searchByKey(key);
		if (result != nullptr) {
			return result; // возвращение поддерева
		}
	}
	if (right != nullptr) {
		Tree<T>* result = right->searchByKey(key);
		if (result != nullptr) {
			return result;// возвращение поддерева
		}
	}
	return nullptr;// возвращение поддерева
}
template <class T>
Tree<T>* Tree<T>::find(T data) { // поиск узла по данным
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
Tree<T>* Tree<T>::findMax() { // поиск максимального элемента
	if (this->right == nullptr) { // если больше нет правых узлов
		return this;
	}
	return this->right->findMax();
}
template <class T>
Tree<T>* Tree<T>::findMin() { // поиск минимального элемента
	Tree<T>* min_node = this;
	while (min_node->left != nullptr) { // если больше нет левых узлов
		min_node = min_node->left;
	}
	return min_node;
}
template <class T>
void Tree<T>::ascendingOrder(vector<T>& result) { // обход дерева в порядке возрастания и сохранение значений в векторе
	if (left != nullptr) {
		left->ascendingOrder(result);
	}
	result.push_back(data);
	if (right != nullptr) {
		right->ascendingOrder(result);
	}
}

template <class T>
Tree<T>* Tree<T>::copeTree() { // копия дерева
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
	for (int j = start; j < end; j++) { // пробелы до узла
		cout << " ";
	}
}
template <class T>
void Tree<T>::printVTree(int k) {
	int height = this->getHeight();
	int max_leafs = pow(2, height - 1);
	int width = 2 * max_leafs - 1; // минимальная ширина дерева
	int cur_level = 0;
	int index = 0;
	int fact_spaces = getPos(index, width, cur_level, height - 1); // число пробелов перед корнем
	pos node; // определение структуры для хранения позиции узла
	vector<Tree<T>*> vect_1;
	vector<pos> vect_2;
	Tree<T>* tree_2 = this->copeTree();
	tree_2 = tree_2->replaceNullForEmpty(); // достраивание дерева до симметрии
	Tree<T>* tree_3 = tree_2;
	vect_1.push_back(tree_3);
	node.column = fact_spaces; // число пробелов перед корнем
	node.row = cur_level;
	vect_2.push_back(node);
	for (int i = 0; i < tree_2->amountNodes(); i++) { // перебор всех узлов дерева
		if (pow(2, cur_level) <= index + 1) {
			index = 0;
			cur_level++;
		}
		if (vect_1.at(i)->left != NULL) { // проверка наличия левого потомка
			vect_1.push_back(vect_1.at(i)->left);
			fact_spaces = getPos(index, width, cur_level, height - 1); // вычисление количества пробелов перед новым корнем
			node.column = fact_spaces; // заполнение позиции нового узла
			node.row = cur_level;
			vect_2.push_back(node);
			index++;
		}
		if (vect_1.at(i)->right != NULL) { // проверка наличия правого потомка
			vect_1.push_back(vect_1.at(i)->right); // добавление потомка в вектор
			fact_spaces = getPos(index, width, cur_level, height - 1); // вычисление количества пробелов перед новым узлом
			node.column = fact_spaces; // заполнение позиции нового узла
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
			cout << endl; // переход на новую строку
		}
		fact_spaces = node.column; // число пробелов перед узлом
		int real_spaces = k * fact_spaces;
		printSpaces(0, real_spaces);
		if (vect_1.at(i)->getData() == NULL) {
			cout << " ";
		}
		else {
			cout << vect_1.at(i)->getData(); // вывод узла
		}
		printSpaces(0, k);
	}
	cout << endl;
}
void printInConsol() { // функция печати дерева вертикально в консоль
	Tree<char>* tree = new Tree<char>('k');
	tree->insertLeft('u');
	tree->getLeft()->insertLeft('l');
	tree->getLeft()->insertRight('c');
	tree->insertRight('!');
	tree->getRight()->insertRight('!');
	tree->getRight()->insertLeft('y');
	cout << "Вертикальная печать" << endl; 
	tree->printVTree(2);
}