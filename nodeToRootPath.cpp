#include<iostream>
#include <stack>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    
    Node(int d,Node* left, Node * right){
        data=d;
        left=left;
        right=right;
    }
};
void display(Node * root){
    if(root==NULL){
        cout<<" NULl  ";
        return;
    }
    cout<<root->data<<"  ";
    display(root->left);
    display(root->right);
}
string ans;

bool NodeToroot(Node * root,int d){
    if(root==NULL){
        return false;
    }
    
    if(root->data==d){
       ans+=to_string(root->data)+" ";
            return true ;
    }
    bool left=NodeToroot(root->left,d);
    if(left){
         ans+=to_string(root->data)+" ";
        return true;
    }
    bool right=NodeToroot(root->right,d);
    if(right){
         ans+=to_string(root->data)+" ";
        return true;
    }
    

return false;


}


int main(){
    int arr[]={ 10, 20, 30,-1,-1,1,-1,-1,11,-1,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> vect(arr, arr + n);

    stack <pair<Node *,int> > st;
    Node * rp=new Node(arr[0],NULL,NULL);

    pair<Node *,int> rpair=make_pair(rp,1);
    st.push(rpair);
    int i=0;
    while(!st.empty()){

        pair<Node *,int> topp=st.top();
            st.pop();
        if(topp.second==1){
            topp=make_pair(topp.first,topp.second+1);
            st.push(topp);
            i++;
            if(arr[i]!=-1){
            Node * newnode= new Node(arr[i],NULL,NULL);
            topp.first->left=newnode;
            pair<Node * ,int> pp=make_pair(newnode,1);
        
            
                st.push(pp);
            }
            else{
                topp.first->left=NULL;
            }
                //top.second++;
        }
        else if(topp.second==2){
            topp=make_pair(topp.first,topp.second+1);
            st.push(topp);
             i++;
            if(arr[i]!=-1){
            Node * rnewnode= new Node(arr[i],NULL,NULL);
            topp.first->right=rnewnode;
            pair<Node * ,int> pp=make_pair(rnewnode,1);
        
            
                st.push(pp);
            }
            else{
                
                topp.first->right=NULL;
            }
           
        }
        else{
            st.pop();
        }

    }

display(rp);
NodeToroot(rp,1);
//cout<<ans;
return 0;
}
