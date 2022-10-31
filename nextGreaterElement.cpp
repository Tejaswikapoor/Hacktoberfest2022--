#include <iostream> 
#include <stack>
#include <cstring>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int nge[n];

    stack<int> st;

    nge[n-1]=-1;
    st.push(a[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=a[i] ){
            st.pop();
        }
        if(st.empty()){
            nge[i]=-1;
        }else{
            nge[i]=st.top();
        }
        st.push(a[i]);
    }
    
    for(int i=0;i<n;i++){
        cout<<nge[i]<<endl;
    }
    return 0;
}
