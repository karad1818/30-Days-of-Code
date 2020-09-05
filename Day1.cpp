/* This File contains all the resources that i've used for learn Trie Data structure ,
my code for Trie and also solution of Some of the question that I've solved today using Trie. */

/* Learning Trie :
  https://youtu.be/NinWEPPrkDQ
  https://www.youtube.com/watch?v=0yemVXDBbyg&t=3730s   //don't watch whole video just copy this link
*/

/* My snippet for Trie : */

//  1. using map or you can replace map with array for speeding your algo. (I prefer this one because it's little bit fast):

struct Trie{
    map<pair<ll,char>,ll>mp;  // it will store pointer of this location and data and it will give next node
    set<ll>end;
    ll last;
    void init(){
        last=0;
        mp.clear();
        end.clear();
    }
    void Create(string s){
        ll me=0;
        for(auto i : s){
            if(mp.count({me,i})){
                me=mp[{me,i}];
            }else{
                mp[{me,i}]=++last;
                me=last;
            }
        }
        end.I(me);
        return ;
    }
    bool Search(string s){
        ll me=0;
        for(auto i : s){
            if(mp.count({me,i})){
                me=mp[{me,i}];
            }else{
                return false;
            }
        }
        return end.count(me);
    }
};

// 2. Using Node Pointer :  

class Node{
    public :
        char data;
        unordered_map<char,Node*>link;
        bool IsEnd;
        Node(char x){
	IsEnd=false;
            data=x;
        }
};
class Trie{
    Node* root;
  public :
    Trie(){
        root= new Node('\0');
    }
    void Addword(string s){
        Node* temp=root;
        for(auto i : s){
            if(temp->link.count(i)){
                temp=temp->link[i];
            }else{
                Node* in = new Node(i);
                temp->link[i]=in;
                temp=in;
            }
        }
        temp->IsEnd=1;
    }
    bool IsPresent(string s){
        Node* temp=root;
        for(auto i : s){
            if(temp->link.count(i)){
                temp=temp->link[i];
            }else{
                return false;
            }
        }
        return temp->IsEnd;
    }
};


/*  Problems for Trie :
      1.https://leetcode.com/problems/longest-common-prefix/
              solution : https://ideone.com/R31rSP
      2.https://www.interviewbit.com/problems/shortest-unique-prefix/#
              solution : https://ideone.com/L6bwh0
      3.https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
              solution : https://ideone.com/1ySv0P   //worst solution ever (haha)
	      		 https://ideone.com/E0UNhK  //Optimal one
*/


