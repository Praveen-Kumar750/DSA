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


void inorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelordertraversal(Node* root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);//as a separator
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            //PURana level complete traverse ho chuka h
            cout<<endl;
            if(!q.empty()){
                //queue still has some child
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

       
    }
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

Node* minval(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxval(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* deletefrombst(Node* root,int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }

        //1 child
            //left
            if(root->left!=NULL && root->right==NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            //right
            if(root->left==NULL && root->right!=NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }


        // 2 child

        if(root->left!=NULL && root->right!=NULL){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
            return root;
        }



    }
    else if(root->data > val){
        root->left=deletefrombst(root->left,val);
        return root;
    }
    else{
       root->right=deletefrombst(root->right,val);
        return root; 
    }
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
    cout<<"printing the bst"<<endl;
    levelordertraversal(root);

    cout<<"print inorder "<<endl;
    inorder(root);
    cout<<"\n print preorder "<<endl;
    preorder(root);
    cout<<"\nprint postorder "<<endl;
    postorder(root); 

    cout << "MIN val is"<<minval(root)->data<<endl;
    cout << "Max val is"<<maxval(root)->data<<endl;

    //deletion
    root=deletefrombst(root,30);  


     cout<<"printing the bst"<<endl;
    levelordertraversal(root);

    cout<<"print inorder "<<endl;
    inorder(root);
    cout<<"\n print preorder "<<endl;
    preorder(root);
    cout<<"\nprint postorder "<<endl;
    postorder(root); 

    cout << "MIN val is"<<minval(root)->data<<endl;
    cout << "Max val is"<<maxval(root)->data<<endl;
  
    return 0;

}
