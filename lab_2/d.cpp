#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

struct LinkedList{
    Node *head,*tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void push_back(int data){
        Node *node = new Node(data);

        if(tail == NULL){
            tail = node;
            head = node;
        }
        else{
            tail -> next = node;
            node ->prev = tail;
            tail = node;
        }
    }
    void dProblem(){
        Node *current = head;
        map<int, int> m;
        while (current != NULL)
        {
            m[current->data]++;
            current = current -> next;
        }

        vector<int> v;
        int cnt = 0;
        for(const auto& pair : m){
            if(pair.second > cnt){
                v.clear();
                v.push_back(pair.first);
                cnt = pair.second;
            }
            else if(pair.second == cnt){
                v.push_back(pair.first);
            }
        }
        sort(v.begin(), v.end());
        for(int i = v.size()-1 ; i >= 0; i--){
            cout << v[i] << " ";
        }
    }
};

int main(){
    LinkedList *ll = new LinkedList();
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        ll -> push_back(x);
    }
    ll -> dProblem();
}