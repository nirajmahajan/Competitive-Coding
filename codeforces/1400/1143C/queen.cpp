#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int id;
	vector <Node *> children;
	Node *parent;
	bool defiant;
	bool root;

	Node(){ root = false;}

	Node(int uid, Node *par) {
		id = uid;
		parent = par;
		defiant = false;
	}
	Node(int uid, Node *par, bool def) {
		id = uid;
		parent = par;
		defiant = def;
	}

	void addChild(Node *child) {
		children.push_back(child);
	}

	bool respectedByChildren() {
		for (auto child : children) {
			if (!child->defiant) {
				return true;
			}
		}
		return false;
	}

	void deletethis() {
		parent->children = children;
		for (auto child : children) {
			child->parent = parent;
		}
	}
};

Node *people[100005];
Node *root;
priority_queue <int> ans;

bool toDelete(Node *start) {
	return (start->defiant && !start->respectedByChildren());
}

void trimTree(Node *start) {
	for (auto child : start->children) {
		if (toDelete(child)) {
			ans.push(-child->id);
		}
	}
	for (auto child : start->children) {
		trimTree(child);
	}
}

int main() {
	int n; scanf("%d", &n);

	// initialize
	for (int i = 1; i <= n; i++){
		Node *temp = new Node;
		people[i] = temp;
	}

	// input relations
	for (int i = 1; i <= n; i++) {
		int p, def; scanf("%d %d", &p, &def);
		if (p == -1) {
			people[i]->id = i;
			people[i]->defiant = (bool) def;
			people[i]->root = true;
			root = people[i];
		} else {
			people[i]->id = i;
			people[i]->parent = people[p];
			people[i]->defiant = (bool) def;
			people[p]->addChild(people[i]);
		}
	}

	trimTree(root);

	if (ans.empty()) {
		printf("-1\n");
		return 0;
	}

	while(!ans.empty()) {
		printf("%d ", -ans.top());
		ans.pop();
	}
	printf("\n");
}