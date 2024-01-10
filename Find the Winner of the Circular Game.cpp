class LListNode{   
  public:
    
    int val;
    LListNode* next;
    LListNode* pre;
    
    LListNode(int x)
    {
        val=x;
        next= NULL;
        pre = NULL;
    }
    
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1)
            return n;
        LListNode* head = new LListNode(1); 
        LListNode* tail = head; 
        
        for(int i=2;i<=n;i++)  
        {
            LListNode* temp = new LListNode(i);
            
            tail->next = temp;
            temp->pre = tail;
            
            tail = tail->next;
        }
        
        head->pre = tail;
        tail->next = head; 
     
        LListNode* temp = head;  
        LListNode* p = head;

		while(temp->next != temp) 
        {
            for(int i=1;i<k-1;i++) 
            {
                temp = temp->next;
            }
			
            p = temp->next->next;
            p->pre = temp;
            temp->next = p;
            
            
            temp = temp->next;
            
        }
        
        return temp->val;
    }
};
