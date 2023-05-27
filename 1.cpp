
// 1.	Consider telephone book database of N clients. 
//     Make use of a hash table implementation to quickly look up client‘s telephone number. 
//     Make use of two collision handling techniques and compare them using the number of 
//     comparisons required to find a set of telephone numbers.


#include<iostream>
using namespace std;

#define TABLESIZE 20

class linearProbing{
    int hash[TABLESIZE], flag[TABLESIZE];
    int count;
    public:
    linearProbing();
    void insert(int);
    void create();
    int find(int);
    void search();
    int getComparisons();
};

linearProbing :: linearProbing(){
    count = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        flag[i] = 0;   
    }
}

void linearProbing :: insert(int x){
    int loc = x % TABLESIZE;
    for (int i = 0; i < TABLESIZE; i++)
    {
        if (flag[loc] == 0)
        {
            hash[loc] = x;
            flag[loc] = 1;
            break;
        }else{
            loc = (loc + 1) % TABLESIZE;
        }
    }
}

void linearProbing :: create(){
    bool t = true;
    int key;
    do{
        char ans;
        cout<<"Enter the Phone Number : ";
        cin>>key;
        insert(key);
        cout<<"Do you want to add more numbers ? (y/n) : ";
        cin>>ans;
        if(ans == 'n'){ t = false; }
    }while(t);
}

int linearProbing :: find(int x){
    int loc = x % TABLESIZE;
    for (int i = 0; i < TABLESIZE; i++)
    {
        count++;
        if (flag[loc] == 1 && hash[loc] == x)
        {
            return loc;
        }else{
            loc = (loc + 1) % TABLESIZE;
        }
    }
    count = 0;
    return -1;
}

void linearProbing :: search(){
    int x,res;
    cout<<"Enter phone number to be searched : ";cin>>x;
    if((res = find(x)) == -1){
        cout << "\nPhone number is not found\n";
    }else{
        cout << "\nPhone number " << x << " is found at " << res << "th location\n\n";
    }
}

int linearProbing :: getComparisons(){
    return count;
}

struct node{
    node * next;
    int phone;
};

class Chaining {
    node *hash[TABLESIZE];
    int count;
    public :
    Chaining();
    void create();
    void insert(int);
};

Chaining :: Chaining(){
    count = 0;
    for (int i = 0; i < TABLESIZE; i++)
    {
        hash[i] = NULL;
    }
    
}

void Chaining :: create(){
    int x,n;
    cout<<"Enter number of numbers to be inserted : ";cin>>n;
    cout<<"Enter the phone numbers to be inserted : ";
    for (int i = 0; i < TABLESIZE; i++)
    {
        cin>>x;
        insert(x);
    }
}

void Chaining :: insert(int x){
    int loc = x % TABLESIZE;
    node * p = new node;
    p->next = NULL;
    p->phone = x;
    if (hash[loc] == NULL)
    {
        hash[loc] = p;
    }else{
        node *q = hash[loc];
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

int main(int argc, char const *argv[])
{
    linearProbing l;
    l.create();
    return 0;
}
