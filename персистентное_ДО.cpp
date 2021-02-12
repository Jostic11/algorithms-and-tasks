#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
//typedef long long ll;
typedef double db;
const int inf = 1000000000;
 
struct node {
    int l, r, sum;
    node *left, *right;
};
 
node *build(int l, int r){
    node *res = new node;
    res->l = l; res->r = r;
    if(l == r){
        res->left = res->right = nullptr;
        res->sum = 0;
    }
    else {
        int mid = (l+r) / 2;
        res->left = build(l, mid);
        res->right = build(mid+1, r);
        res->sum = 0;
    }
    return res;
}
 
node *update(node *root1, int pos, int l, int r){
    if(r < pos || l > pos)return root1;
    node *res = new node;
    res->l = l, res->r = r;
    if(l == r){
        res->left = res->right = nullptr;
        res->sum = 1;
    }
    else {
        int mid = (l+r) / 2;
        res->left = update(root1->left, pos, l, mid);
        res->right = update(root1->right, pos, mid+1, r);
        res->sum = res->left->sum + res->right->sum;
    }
    return res;
}
 
node *upd(node *root, int pos){
    if(root->l > pos || root->r < pos)return root;
    node *res = new node;
    res->l = root->l;
    res->r = root->r;
    if(res->l == res->r){
        res->left = res->right = nullptr;
        res->sum = 0;
    }
    else {
        res->left = upd(root->left, pos);
        res->right = upd(root->right, pos);
        res->sum = res->left->sum + res->right->sum;
    }
    return res;
}
 
int query(node *root, int l, int r){
    if(root->l > r || root->r < l)return 0;
    if(root->l >= l && root->r <= r){
        return root->sum;
    }
    return query(root->left, l, r) + query(root->right, l, r);
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int kol_vo;
    cin >> kol_vo;
    vector<int> v(kol_vo);
    for(int c=0; c<kol_vo; c++)
        cin >> v[c];
    map<int, int> m;
 
    vector<node *> root(kol_vo+1);
    root[0] = build(1, kol_vo);
    //cout << query(root[0], 1, 4) << endl;
    for(int c=1; c<=kol_vo; c++){
        root[c] = update(root[c-1], c, 1, kol_vo);
        if(m[v[c-1]] != 0)root[c] = upd(root[c], m[v[c-1]]);
        m[v[c-1]] = c;
        //cout << query(root[c], 2, 3) << endl;
    }
 
    int q;
    cin >> q;
    for(int c=0; c<q; c++){
        int e, e1;
        cin >> e >> e1;
        cout << query(root[e1], e, e1) << '\n';
    }
    return 0;
}