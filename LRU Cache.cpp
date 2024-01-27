class LRUCache {
public: 
  class node {
      public:
      int val,key;
      node* next;
      node* prev;

      node(int _key,int _val){
            key = _key;
            val = _val;
      }
  };

  node* head = new node(-1,-1);
  node* tail = new node(-1,-1);

  int cap;
  unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode){
        node* tmp = head->next;
        newnode->next = tmp;
        head->next = newnode;
        newnode->prev = head;
        tmp->prev = newnode;
    }

    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    


    int get(int _key) {

        if(mp.find(_key)!=mp.end()){
              node* resnode = mp[_key];
              int res = resnode->val;
              mp.erase(_key);
              deletenode(resnode);
              addnode(resnode);
             mp[_key]= head->next;
             return res;
        }

        return -1;
    }
    
    void put(int _key, int value) {
        if(mp.find(_key)!=mp.end()){
            node* existingnode = mp[_key];
            mp.erase(_key);
            deletenode(existingnode);
        }

        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(_key,value));
        mp[_key]= head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
