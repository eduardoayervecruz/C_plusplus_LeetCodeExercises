/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* finalmerged = nullptr;
    ListNode* finalcurrentmerged = nullptr;

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2; // If list1 is empty, return list2
    }

    if (list2 == nullptr) {
        return list1; // If list2 is empty, return list1
    }

    ListNode dummy(0);  // Create a dummy node to simplify list construction
    ListNode* currentMerged = &dummy;

    ListNode* current1 = list1;
    ListNode* current2 = list2;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->val <= current2->val) {
            currentMerged->next = current1;
            current1 = current1->next;
        } else {
            currentMerged->next = current2;
            current2 = current2->next;
        }
        currentMerged = currentMerged->next;
    }

    // If one of the lists is not exhausted, append its remaining elements to the merged list
    if (current1 != nullptr) {
        currentMerged->next = current1;
    } else {
        currentMerged->next = current2;
    }

    return dummy.next;  // Return the merged list starting from the next node of the dummy
}


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* finalmerged = nullptr;
        // ListNode* finalcurrentmerged = nullptr;
        for(unsigned int i = 0; i < lists.size(); i++){
            finalmerged = mergeTwoLists(finalmerged, lists[i]);
        }
        return finalmerged;
    }
};
