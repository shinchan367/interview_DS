class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>nums_set(nums.begin() , nums.end());


        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;


        while(current->next != NULL){
            if(nums_set.find(current->next->val) != nums_set.end()){
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }
        ListNode* new_head = dummy->next;
        delete dummy;

        return new_head;
    }
};
