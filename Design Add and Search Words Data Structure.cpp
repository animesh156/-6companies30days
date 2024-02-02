struct Node{
    Node* links[26];
    bool flag;
    public:
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag=true;
    }
};
class WordDictionary 
{
    Node* root;
public:
    WordDictionary() 
    {
        root=new Node();
    }
    
    void addWord(string word) 
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool helper(Node* root,string word,int index)
    {
        if(index==word.size() && root->isEnd()==true)
            return true;
        if(index==word.size() && root->isEnd()==false)
            return false;
        if(word[index]=='.')
        {
            for(int i=0;i<26;i++)
            {
                bool a;
                if(root->links[i]!=NULL)
                    a=helper(root->links[i],word,index+1);
                    if(a==true)             
                    return true;
            }
            return false;
        }
        else
        {
            if(root->links[word[index]-'a']==NULL)
            return false;
            return helper(root->links[word[index]-'a'],word,index+1);
        }
    }
    bool search(string word) 
    {
        Node* node=root;
        return helper(node,word,0);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
