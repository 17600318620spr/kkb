/*************************************************************************
	> File Name: 3.hashtable.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 May 2022 02:20:39 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class List;
class HashTable;

class Node{
private:
    string key;
    string value;
    Node *next;
public:
    Node(string s, string v):key(s), value(v), next(nullptr){}

    friend List;
    friend HashTable;
};

class List{
    friend HashTable;
    Node *head;
public:
    List(Node *h = nullptr):head(h){}
    ~List(){
        Node *k;
        while(head)
        {
            k = head;
            head = head->next;
            delete k;
        }
    }

    bool insert(string s, string v){
        return __insert(s, v) != nullptr;
    }
    Node *__insert(string s, string v){
        Node *nn = new Node(s, v);
        nn->next = head;
        head = nn;
        return nn;
    }

    bool erase(string s)
    {
        Node *find = head, *k;
        if(!find)
            return false;
        if(head->key == s){
            k = head;
            head  = head->next;
            delete k;
            return true;
        }

        while(find->next)
        {
            if(find->next->key == s)
            {
                k = find->next;
                find->next = k->next;
                delete k;
                return true;
            }
            find = find->next;
        }
        return false;
    }

    bool find(string s)
    {
        return __find(s) != nullptr;
    }

    Node *__find(string s)
    {
        Node *p = head;
        while(p)
        {
            if(p->key == s)
                return p;
            p = p->next;
        }
        return nullptr;
    }

    void trav()
    {
        Node *p = head;
        while(p)
        {
            cout<<p->key<<",";
            p = p->next;
        }
        cout<<endl;
    }
};

#if 0
int main1()
{
    List l;
    l.insert("haha");
    l.insert("good");
    l.insert("kkb");
    l.trav();
    l.erase("good");
    l.trav();
    l.erase("kkb");
    l.trav();
    l.erase("testtttt");

    return 0;
}
#endif

class HashTable{
    typedef function<int(string)> HASHFUNC;
private:
    HASHFUNC func;
    int size;
    int cnt;
    vector<List> data;
public:
    HashTable(HASHFUNC f, int s = 10000, int c = 0):func(f), size(s), data(s), cnt(c){}
    int getCnt()
    {
        return cnt;
    }
    int getSize()
    {
        return size;
    }
    int str2idx(string s)
    {
        return func(s) % size;
    }

    bool insert(string s, string v)
    {
        expand();
        cnt++;
        return data[str2idx(s)].insert(s ,v);
    }

    bool erase(string s)
    {
        int res = data[str2idx(s)].erase(s);
        cnt -= res;
        return res;
    }

    bool find(string s)
    {
        return data[str2idx(s)].find(s);
    }
    Node *__find(string s)
    {
        return data[str2idx(s)].__find(s);
    }

    string &operator[](string k){
        int idx = str2idx(k);
        Node *p;
        if(p = data[idx].__find(k))
        {
            return p->value;
        }
        else
        {
            expand();
            cnt++;
            return data[idx].__insert(k, "")->value;
        }
    }

    void expand()
    {
        if(cnt < size)
            return ;
        int newsize = size * 2;
        HashTable tmp_h(func, newsize);
        for(int i = 0; i < size; i++)
        {
            for(Node *p = data[i].head; p; p = p->next)
            {
                tmp_h[p->key] = p->value;
            }
        }

        swap(*this, tmp_h);

        return ;
    }
};

int BKDHash(string s)
{
    int seed = 31;
    int h = 0;
    for(int i = 0; s[i]; i++)
    {
        h = h*seed+s[i];
    }
    return h & 0x7fffffff;
}

class APHash{
public:
    int operator()(string s){
        int h = 0;
        for(int i = 0; s[i]; i++)
        {
            if(i % 2)
            {
                h = (h << 3) ^ s[i] ^ (h >> 5);
            }
            else
            {
                h = ~((h << 7) ^ s[i] ^ (h >> 11));
            }
        }
        return h && 0x7fffffff;
    }
};

int main()
{
    APHash ap;
    HashTable h1(BKDHash, 2);
    HashTable h2(ap);

    h1["name"] = "lxx";
    cout<<h1.getSize()<<endl;
    h1["age"] = "18";
    cout<<h1.getSize()<<endl;
    h1["marks"] = "3333";
    cout<<h1.getSize()<<endl;
    //h1.erase("age");
    //cout<<h1.getCnt()<<endl;

    cout<<h1["name"]<<","<<h1["age"]<<","<<h1["marks"]<<endl;

    /*
    int op;
    string s;
    while(cin>>op>>s)
    {
        switch(op)
        {
            case 1: //insert
                cout<<"insert "<<s<<" to hashtable 1=";
                cout<<h1.insert(s)<<endl;
                cout<<"insert "<<s<<" to hashtable 2=";
                cout<<h2.insert(s)<<endl;
                break;
            case 2: //erase
                cout<<"erase "<<s<<" from hashtable 1=";
                cout<<h1.erase(s)<<endl;
                cout<<"erase "<<s<<" from hashtable 2=";
                cout<<h2.erase(s)<<endl;
                break;
            case 3: //find
                cout<<"find "<<s<<" in hashtable 1=";
                cout<<h1.find(s)<<endl;
                cout<<"find "<<s<<" in hashtable 2=";
                cout<<h2.find(s)<<endl;
                break;
        }
    }
    */

    return 0;
}
