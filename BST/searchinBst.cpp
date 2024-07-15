
#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


//Approach 1 Recursive manner
bool searchinBst(Node* root,int x){
  if(root==NULL)
    return false;
  if(root->data==x)
      return true;
  if(root->data > x){
    //left part
    return searchinBst(root->right,x);
  }
  if(root->data < x){
    //right part
    return searchinBst(root->left,x);
  }
}

//Approach 2 in iterative manner


bool searchinBstinIterative(Node* root,int x){
  Node* temp=root;
  while(temp!=NULL){
    if(temp->data==x){
        cout<<"found";
        return temp;
    }    
    if(temp->data > x)
        temp=temp->left;
    else{
      temp=temp->right;
    }
  }
return NULL;
}

Node* insertintobst(Node* root,int d){
    //base class
    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d>root->data){
        root->right=insertintobst(root->right,d);
    }
    else{
        root->left=insertintobst(root->left,d);
    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertintobst(root,data);
        cin>>data;
    }
}

int main(){
    Node* root=NULL;
    cout<<"enter data to create bst"<<endl;
    takeinput(root);
    int s;
    cin>>s;
    searchinBstinIterative(root,s);
}
