#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

void Push(ListNode** head, int A)
{
	ListNode* n = (ListNode*)malloc(sizeof(ListNode));
	n->val = A;
	n->next = *head;
	*head = n;
}

void printList(ListNode* head)
{
	while (head) {
		if (head->next == NULL)
			cout << "[" << head->val << "] "
				<< "[" << head << "]->"
				<< "(nil)" << endl;
		else
			cout << "[" << head->val << "] "
				<< "[" << head << "]->" << head->next
				<< endl;
		head = head->next;
	}
	cout << endl << endl;
}

/**
 * @brief Delete node without head pointer
 * make current node next and delete next node
 * 
 * @param node 
 */
void deleteNode(ListNode* node) {
    ListNode *nextNodePtr = node->next;
    node->val = nextNodePtr->val;
    node->next = nextNodePtr->next;
    nextNodePtr->next = nullptr;
    delete(nextNodePtr);
}

// Driver code
int main()
{
	ListNode* list = (ListNode*)malloc(sizeof(ListNode));
	list->next = NULL;
	Push(&list, 1);
	Push(&list, 2);
	Push(&list, 3);

	printList(list);

	// Delete any position from list
	deleteNode(list->next);
	printList(list);
	return 0;
}
