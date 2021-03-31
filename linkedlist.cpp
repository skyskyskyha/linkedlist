#include<iostream>
using namespace std;
struct node {
	int val;
	int num;
	node* next;
	node(int val=0,int num=0,node *next=nullptr):
		val(val),num(num),next(next){}
};
node *head[10];
//push a edge from a to b weights value
void push(int a, int b, int value) {
	if (head[a] == nullptr)
		head[a] = new node{ value,b,nullptr };
	else {
		node *flag = head[a]->next;
		head[a]->next = new node{ value,b,flag };
	}
}
int main() {
	//create a weighed linked list
	int n, m, a, b, value;//n number of nodes m number of edges
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> value;//vertex a and vertex b has an edge weights value
		push(a, b, value);
		push(b, a, value);
	}
	for (int i = 0; i < n; i++) {
		cout << i;
		node* flag = head[i];
		while (flag) {
			cout << "->" << flag->num ;
			flag = flag->next;
		}
		cout << endl;
	}
}
//input case:
//5 6
//0 1 2
//0 3 5
//0 4 2
//1 5 3
//2 3 4
//3 4 1
//output case:
//0->1->4->3
//1->0->5
//2->3
//3->0->4->2
//4->0->3
