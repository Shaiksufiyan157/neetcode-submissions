class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL,prev=NULL;
    }
};
class LRUCache {
private:
 void deleteNode(Node* node){
    node->prev->next=node->next;
    node->next->prev=node->prev;
    node->next=NULL;
    node->prev=NULL;
 }
 void insertAfter(Node* node){
    node->next=head->next;
    head->next->prev=node;
    head->next=node;
    node->prev=head;
 }
public:
    int size;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        head->prev=NULL;
        tail->prev=head;
        tail->next=NULL;
        mp.clear(); 
    }

    int get(int key) {
        if(!mp.contains(key)) return -1;
        Node* node=mp[key];
        deleteNode(node);
        insertAfter(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)){
            Node* node=mp[key];
            node->val=value;
            deleteNode(node);
            insertAfter(node);
        }
        else{
            if(mp.size()==size){
                Node* node=tail->prev;
                deleteNode(node);
                mp.erase(node->key);
            }
            Node* node=new Node(key,value);
            mp[key]=node;
            insertAfter(node);
        }
            
        }
};
