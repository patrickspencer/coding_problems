#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next = NULL;
    ListNode(int x) : val(x) {};
};

class Solution {

public:
    ListNode* add(ListNode* l1, ListNode* l2) {
	ListNode preHead(0), *cur = &preHead;
	int carry = 0;
	while (l1 || l2 || carry) {
	    int x = (l1 ? l1->val : 0);
	    int y = (l2 ? l2->val : 0);
	    int sum = x + y + carry;
	    cur->next = new ListNode(sum % 10);
	    cur = cur->next;
	    carry = sum / 10;
	    l1 = l1 ? l1->next : 0;
	    l2 = l2 ? l2->next : 0;
	}
	return preHead.next;
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
    while (cur) {
	cout << cur->val;
	cur = cur->next;
    }
    cout << "\n";
    while (cur) {
	cout << cur->val;
	cur = cur->next;
    }
    return 0;

}
