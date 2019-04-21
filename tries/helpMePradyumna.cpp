#include<bits/stdc++.h>
using namespace std;
string str[32000];
struct Node{
  char data;
  Node* child[26];
  int index;
  Node(){
      for(int i=0;i<26;i++){
          child[i]=NULL;
      }
      index = -1;
  }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = newNode('$');
    }
    Node* newNode(char data){
        Node* p = new Node;
        p->data = data;
        return p;
    }
    Node* addString(string& s, int id){
        Node* curr = root;
        for(int i=0;i<(int)s.size();i++){
            s[i] = towlower(s[i]);
            if(curr->child[s[i]-'a']==NULL){
                curr->child[s[i]-'a'] = newNode(s[i]);
            }
            if((i+1) == (int)s.size()){
                curr->child[s[i]-'a']->index = id;
            }
            curr = curr->child[s[i]-'a'];
        }
    }
    void dfs(Node* curr){
        if(curr!=NULL){
            if(curr->index >=0)cout<<str[curr->index]<< "\n";
            for(int i=0;i<26;i++){
                if(curr->child[i]!=NULL){
                    dfs(curr->child[i]);
                }
            }
        }
    }
    void check(string tmp, int& id){
        Node* curr = root;
        for(int i=0;i<(int)tmp.size();i++){
            if(curr->child[tmp[i]-'a']==NULL){
                addString(tmp,id);
                str[id++] = tmp;
                cout<<"No suggestions\n";
                return;
            }
            curr = curr ->child[tmp[i]-'a'];
        }
        dfs(curr);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int i;
    Trie T;
    for(i=0;i<N;i++){
        cin>>str[i];
        T.addString(str[i],i);
    }
    int q;
    cin>>q;
    string tmp;
    while(q--){
        cin>>tmp;
        T.check(tmp,i);
    }
    return 0;
}
