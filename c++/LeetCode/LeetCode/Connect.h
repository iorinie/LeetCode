#include <iostream>

using namespace std;

#ifndef CONNECT_H

#define CONNECT_H

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	Node(int x, Node* l, Node* r, Node* n) : val(x), left(l), right(r), next(n) {}
};

Node* connect(Node* root);

void help(Node*& pre, Node*& cur, Node*& nextStart);

#endif // !CONNECT_H
