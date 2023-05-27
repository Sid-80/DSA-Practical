// 9.	A Dictionary stores keywords and its meanings.
//     Provide facility for adding new keywords, deleting keywords, updating values of any entry.
//     Provide facility to display whole data sorted in ascending/ Descending order.
//     Also find how many maximum comparisons may require for finding any keyword.
//     Use Height balance tree and find the complexity for finding a keyword.

#include <bits/stdc++.h>
using namespace std;

class avlNode
{
    string word, meaning;
    int height;
    avlNode *left;
    avlNode *right;

public:
    friend class Dictionary;
    avlNode()
    {
        left = right = NULL;
    }
};

class Dictionary
{
    avlNode *root;

public:
    Dictionary(){
        root = new avlNode();
    }
    void insert();
    avlNode* placeNode(avlNode *, avlNode *);
    int balance(avlNode *);
    avlNode* LL(avlNode *);
    avlNode* LR(avlNode *);
    avlNode* RR(avlNode *);
    avlNode* RL(avlNode *);
    int heightCalc(avlNode *);
    avlNode* rotateLeft(avlNode *);
    avlNode* rotateRight(avlNode *);
    void displayAsc();
    void inOrder(avlNode *);
};

int Dictionary ::heightCalc(avlNode *node)
{
    int lh, rh;

    if (node == NULL)
        return 0;

    if (node->left == NULL)
        lh = 0;
    else
        lh = (node->left->height) + 1;

    if (node->right == NULL)
        rh = 0;
    else
        rh = (node->right->height) + 1;

    if (lh > rh)
        return lh;
    else
        return rh;
}

int Dictionary ::balance(avlNode *node)
{
    int lh, rh;

    if (node == NULL)
        return 0;

    if (node->left == NULL)
        lh = 0;
    else
        lh = (node->left->height) + 1;

    if (node->right == NULL)
        rh = 0;
    else
        rh = (node->right->height) + 1;

    return (lh - rh);
}

avlNode* Dictionary ::placeNode(avlNode * start, avlNode *temp)
{
    if (start == NULL)
        start = temp;
    else if ((temp->word.compare(start->word)) < 0)
    {
        start->left = placeNode(start->left, temp);
        if (balance(start) == 2)
        {
            if ((temp->word.compare(start->word)) < 0)
                start = LL(start);
            else 
                start = LR(start);
        }
    }
    else if ((temp->word.compare(start->word)) > 0)
    {
        start->right = placeNode(start->right, temp);
        if (balance(start) == -2)
        {
            if ((temp->word.compare(start->word)) > 0)
                start = RR(start);
            else
                start = RL(start);
        }
    }
    start->height = heightCalc(start);
    return start;
}

void Dictionary ::insert()
{
    int n;
    cout << "Enter the number of words to be inserted : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        avlNode *temp = new avlNode();;
        // avlNode * start = root;
        cout << "Enter Word : ";   
        cin >> temp->word;
        cout << "Enter Meaning : ";
        cin >> temp->meaning;
        root = placeNode(root, temp);
    }
}

avlNode * Dictionary ::LL(avlNode * temp)
{
    temp = rotateRight(temp);
    return temp;
}
avlNode * Dictionary ::LR(avlNode * temp)
{
    temp->left =  rotateLeft(temp->left);
    temp = rotateRight(temp);
    return temp;
}
avlNode * Dictionary ::RR(avlNode * temp)
{
    temp = rotateLeft(temp);
    return temp;
}
avlNode * Dictionary ::RL(avlNode * temp)
{
    temp->right = rotateRight(temp->right);
    temp = rotateLeft(temp);
    return temp;
}

avlNode * Dictionary :: rotateLeft(avlNode * temp){
    avlNode * x;
    x = temp->right;
    temp->right = x->left;
    x->left = temp;
    temp->height = heightCalc(temp);
    x->height = heightCalc(x);
    return x;
}
avlNode * Dictionary :: rotateRight(avlNode * temp){
    avlNode * x;
    x = temp->left;
    temp->left = x->right;
    x->right = temp;
    temp->height = heightCalc(temp);
    x->height = heightCalc(x);
    return x;
}

void Dictionary :: displayAsc(){
    inOrder(this->root);
}

void Dictionary :: inOrder(avlNode * root){
    if (root == NULL)
        return;
    else{
        inOrder(root->left);
        cout<<root->word<<"\t"<<root->meaning<<endl;
        inOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Dictionary d;
    d.insert();
    cout<<"Displaying\n";
    d.displayAsc();
    return 0;
}