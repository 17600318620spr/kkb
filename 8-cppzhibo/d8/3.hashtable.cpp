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

class Node{
private:
    string key;
    Node *next;
public:
    Node(string s):key(s), next(nullptr){}

    friend List;
};

class List{
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

    bool insert(string s){
        Node *nn = new Node(s);
        nn->next = head;
        head = nn;
        return true;
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
        Node *p = head;
        while(p)
        {
            if(p->key == s)
                return true;
            p = p->next;
        }
        return false;
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

class HashTable{
    typedef function<int(string)> HASHFUNC;
private:
    HASHFUNC func;
    int size;
    vector<List> data;
public:
    HashTable(HASHFUNC f, int s = 10000):func(f), size(s), data(s){}
    int str2idx(string s)
    {
        return func(s) % size;
    }

    bool insert(string s)
    {
        return data[str2idx(s)].insert(s);
    }

    bool erase(string s)
    {
        return data[str2idx(s)].erase(s);
    }

    bool find(string s)
    {
        return data[str2idx(s)].find(s);
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
    HashTable h1(BKDHash);
    HashTable h2(ap);

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

    return 0;
}
