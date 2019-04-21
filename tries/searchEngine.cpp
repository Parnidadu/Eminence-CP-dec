#include<bits/stdc++.h>
using namespace std;
struct trieNode{
    trieNode *next[26];
    int weight;
    bool isEnd;
};
 
trieNode *create_node()
{
    trieNode *temp = new trieNode;
    temp->weight = -1;
    temp->isEnd = false;
    for(int i=0;i<26;i++)
        temp->next[i] = NULL;
    return temp;
}
 
void create(trieNode *root,string s,int w)
{
    int char_id;
    trieNode *cur = root;
    for(int i=0;i<s.length();i++)
    {
        char_id = s[i] - 'a';
        if(cur->next[char_id]==NULL)
        {
            cur->next[char_id] = create_node();
        }
        cur = cur->next[char_id];
        cur->weight = max(cur->weight,w);
    }
    cur->isEnd = true;
}
 
int get_max(trieNode *root,string s)
{
    trieNode *cur = root;
    int ans = cur->weight;
    int char_id;
    for(int i=0;i<s.size() && cur!=NULL;i++)
    {
        char_id = s[i]-'a';
        if(cur->next[char_id] == NULL)
        {
            ans = -1;
            break;
        }
        cur = cur->next[char_id];
        ans = cur->weight;
    }
    return ans;
}
 
int main()
{
    int n,q;
    cin >> n >> q;
    trieNode *root = create_node();
    for(int i=0;i<n;i++)
    {
        string s; int w;
        cin >> s >> w;
        create(root,s,w);
    }
    while(q--)
    {
        string s;
        cin >> s;
        cout << get_max(root,s) << endl;
    }
}
