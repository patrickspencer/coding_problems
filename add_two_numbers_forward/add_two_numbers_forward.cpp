#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next = NULL;
    ListNode(int x) : val(x) {};
};

class Solution {
public:
    ListNode* add(ListNode* l1, ListNode* l2) {
	stack <int> s1;
	stack <int> s2;

	while (l1) {
	    s1.push(l1->val);
	    l1 = l1->next;
	}
	while (l2) {
	    s2.push(l2->val);
	    l2 = l2->next;
	}

	int carry = 0;
	int sum = 0;

	ListNode* cur = new ListNode(0);
	while (!s1.empty() || !s2.empty() || carry) {
	    sum = 0;
	    if (!s1.empty()) {
		sum += s1.top();
		s1.pop();
	    }
	    if (!s2.empty()) {
		sum += s2.top();
		s2.pop();
	    }
	    sum += carry;
	    cur->val = sum % 10;
	    ListNode* head = new ListNode(0);
	    head->next = cur;
	    cur = head;
	    carry = sum / 10;
	}
	return cur == 0 ? cur->next : cur;
    };
};

int main()
{
    // Solution soln;
    ListNode a1 = ListNode(2);
    ListNode a2 = ListNode(0);
    ListNode a3 = ListNode(1);
    a1.next = &a2;
    a2.next = &a3;

    ListNode b1 = ListNode(1);
    ListNode b2 = ListNode(0);
    ListNode b3 = ListNode(9);
    b1.next = &b2;
    b2.next = &b3;

    // Solution soln;
    ListNode* cur = Solution().add(&a1, &b1);
    cout << cur->val;
    while (cur) {
	cout << cur->val;
	cur = cur->next;
    }
    cout << "\n";

    // stack <int> s1;
    // stack <int> s2;
    // ListNode* x;
    // ListNode* y;
    // x = &a1;
    // y = &b1;
    // while (x) {
	// s1.push(x->val);
	// x = x->next;
    // }
    // while (!s1.empty()) {
	// cout << '\t' << s1.top();
	// s1.pop();
    // }
    // while (y) {
	// s2.push(y->val);
	// y = y->next;
    // }
    return 0;

}
