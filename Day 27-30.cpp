/* I've learned about data structures like heap,AVL,BST et cetra */
/* Resources : 6.006 MIT OCW */
/* GFG */

/* Tree (BST) Using Node Structure */

struct Node{
    ll val;
    Node* left;
    Node* right;
};
struct Tree{
    Node* head;
    void init(){
        head = new Node();
        head->val=INT_MAX;
        head->left=NULL;
        head->right=NULL;
    }
    void newNode(Node* &h,ll val){
        h = new Node();
        h->val=val;
        h->left=NULL;
        h->right=NULL;
        return ;
    }
    void CreateNode(Node* head,ll val){
        if(head->val>val){
            if(head->left==NULL){
                newNode(head->left,val);
            }else
                CreateNode(head->left,val);
        }else{
            if(head->right==NULL){
                newNode(head->right,val);
            }else
                CreateNode(head->right,val);
        }
    }
    void CreateNode(ll val){
        if(head->val==INT_MAX){
            head->val=val;
            return ;
        }
        CreateNode(head,val);
    }
    arr BFSTraversal(){
        arr ans;
        queue<Node*>q;
        q.push(head);
        while(!q.empty()){
            Node* x=q.front();
            ans.pb(x->val);
            q.pop();
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
        }
        return ans;
    }
    void InorderTraversal(Node* head,arr& ans){
        if(head->left){
            InorderTraversal(head->left,ans);
        }
        ans.pb(head->val);
        if(head->right){
            InorderTraversal(head->right,ans);
        }
    }
    arr InorderTraversal(){
        arr ans;
        InorderTraversal(head,ans);
        return ans;
    }
    void PreorderTraversal(Node* head,arr& ans){
        ans.pb(head->val);
        if(head->left){
            PreorderTraversal(head->left,ans);
        }
        if(head->right){
            PreorderTraversal(head->right,ans);
        }
    }
    arr PreorderTraversal(){
        arr ans;
        PreorderTraversal(head,ans);
        return ans;
    }
    void PostorderTraversal(Node* head,arr& ans){
        if(head->left){
            PostorderTraversal(head->left,ans);
        }
        if(head->right){
            PostorderTraversal(head->right,ans);
        }
        ans.pb(head->val);
    }
    arr PostorderTraversal(){
        arr ans;
        PostorderTraversal(head,ans);
        return ans;
    }
    
};


/* AVL Tree (Self Balancing BST) */

struct Node{
    ll val;
    Node* left;
    Node* right;
    ll height;
};
struct AVL{
    Node* head;
    void newNode(Node* &head,ll val){
        head = new Node();
        head->val=val;
        head->left=NULL;
        head->right=NULL;
        head->height=1;
    }
    void init(){
        newNode(head,INT_MAX);
    }
    ll getHeight(Node* head){
        if(head==NULL)
            return 0;
        return head->height;
    }
    ll getBalance(Node* head){
        if(head==NULL)
            return 0;
        return getHeight(head->left)-getHeight(head->right);
    }
    Node* left(Node* x){
        Node* y=x->right;
        Node* a=y->left;
        y->left=x;
        x->right=a;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        return y;
    }
    Node* right(Node* x){
        Node* y=x->left;
        Node* a=y->right;
        y->right=x;
        x->left=a;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;
        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        return y;
    }
    Node* CreateNode(Node* head,ll val){
        if(head==NULL){
            newNode(head,val);
            return head;
        }
        if(head->val > val){
            head->left=CreateNode(head->left,val);
        }else{
            head->right=CreateNode(head->right,val);
        }
        head->height = 1+max(getHeight(head->left),getHeight(head->right));
        ll bal=getBalance(head);
        //bal > 1  left is heavy otherwise right is heavy
        if(bal>1){
            if(val>head->left->val){
                //left
                head->left=left(head->left);
                //right
                return right(head);
            }else{
                return right(head);
                //right
            }
        }else if(bal<-1){
            if(val>head->right->val){
                //left
                return left(head);
            }else{
                //right
                head->right=right(head->right);
                //left
                return left(head);
            }
        }
        return head;
    }
    void CreateNode(ll val){
        if(head->val==INT_MAX){
            head->val=val;
            return ;
        }
        head=CreateNode(head,val);
    }
    arr BFSTraversal(){
        arr ans;
        queue<Node*>q;
        q.push(head);
        while(!q.empty()){
            Node* x=q.front();
            ans.pb(x->val);
            q.pop();
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
        }
        return ans;
    }
};

/* Heap */

struct Heap{
    arr heap;
    ll h_size;
    void init(ll n){
        h_size=0;
        heap.assign(n+1,0);
    }
    ll parent(ll n){
        return n>>1;
    }
    ll left(ll n){
        return 2*n;
    }
    ll right(ll n){
        return 2*n+1;
    }
    void insert(ll val){
        h_size++;
        heap[h_size]=val;
        ll i=h_size;
        while(i>1 and heap[parent(i)] < heap[i]){
            swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }
    //what is heapify : iff both of i'th child is heap but i'th node is violet rules than we have to do heapify
    //heapify takes : O(logN)
    //building heap takes O(N) **using some arithmetic progression**
    void max_heapify(ll i){
        ll l=left(i);
        ll r=right(i);
        ll big=i;
        if(l<h_size and heap[l]>heap[big]){
            big=l;
        }
        if(r<h_size and heap[r]>heap[big]){
            big=r;
        }
        if(big!=i){
            swap(heap[i],heap[big]);
            max_heapify(big);
        }
    }
    //return max element and delete it 
    ll extract_max(){
        ll st=heap[1];
        heap[1]=heap[h_size];
        h_size--;
        max_heapify(1);
        return st; 
    }
    void showArr(){
        for(int i=1;i<=h_size;i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }
    arr heap_sort(){
        arr ans;
        while(h_size>=1){
            ans.pb(extract_max());
        }
        return ans;
    }
};

/* Problems 
1. https://www.hackerrank.com/challenges/tree-preorder-traversal  : https://www.hackerrank.com/challenges/tree-preorder-traversal/submissions/code/182616523
2. https://www.hackerrank.com/challenges/tree-postorder-traversal : https://www.hackerrank.com/challenges/tree-postorder-traversal/submissions/code/182616690
3. https://www.hackerrank.com/challenges/tree-inorder-traversal : https://www.hackerrank.com/challenges/tree-inorder-traversal/submissions/code/182616782
4. https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree : https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/submissions/code/182617040
5. https://www.hackerrank.com/challenges/tree-top-view : https://www.hackerrank.com/challenges/tree-top-view/submissions/code/182618199
6. https://www.hackerrank.com/challenges/tree-level-order-traversal : https://www.hackerrank.com/challenges/tree-level-order-traversal/submissions/code/182618390
7. https://www.hackerrank.com/challenges/binary-search-tree-insertion : https://www.hackerrank.com/challenges/binary-search-tree-insertion/submissions/code/182619192
8. https://www.hackerrank.com/challenges/tree-huffman-decoding : https://www.hackerrank.com/challenges/tree-huffman-decoding/submissions/code/182627650
9. https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor : https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/submissions/code/182625943
10. https://www.hackerrank.com/challenges/is-binary-search-tree : https://www.hackerrank.com/challenges/is-binary-search-tree/submissions/code/182799852
11. https://www.hackerrank.com/challenges/self-balancing-tree : https://www.hackerrank.com/challenges/self-balancing-tree/submissions/code/182801870
12. https://www.hackerrank.com/challenges/median  : https://www.hackerrank.com/challenges/median/submissions/code/183059594

*/
