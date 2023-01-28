#include <iostream>
#include <string>
using namespace std;

// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};


string formatDigits(ListNode<int> *node){
    string number = to_string(node->value);
    while (number.length() < 4) {
        string cero = "0";
        number = cero + number;
    }
    if (node->next != NULL) {
        return number + formatDigits(node->next);
    }
}

ListNode<int> * unformat(string number){
    ListNode<int>* tmp;
    ListNode<int>* ret;
    string fourDigits = "";
    while (number.length() < 1)
    {   
        fourDigits = number.substr(number.length()-4, number.length());
        tmp = new ListNode<int>(stoi(fourDigits));
        ret->next = tmp;
    }
}

ListNode<int> * solution(ListNode<int> * a, ListNode<int> * b) {
    cout<<stoull(formatDigits(a));
    // unsigned long long sum = stoull(formatDigits(a)) + stoull(formatDigits(b));
    // ListNode<int>* res;
    // res = unformat(to_string(sum));
    // return res;
}


int main(){
    ListNode<int>* a;
    int va = 9876;
    a->value = va;
    ListNode<int>* b;
    int vb = 5432;
    b->value = vb;
    ListNode<int>* c;
    int vc = 1999;
    c->value = vc;

    ListNode<int>* d;
    int vd = 1;
    d->value = vd;
    ListNode<int>* e;
    int ve = 8001;
    e->value = ve;

    d->next = e;

    b->next = c;
    a->next = b;

    solution(a,d);

}