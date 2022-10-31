#include <iostream> 
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

vector<int> nsel(int * arr,int n){

stack<int> st;
vector<int> nselarr(n);

nselarr[0]=-1;
st.push(0);
for(int i=1;i<n;i++){
    while(!st.empty() && arr[i]<=arr[st.top()]){
        st.pop();
    }
    if(st.empty()){
        nselarr[i]=-1;
    }
    else{
        nselarr[i]=st.top();
    }
    st.push(i);
}
return nselarr;
}

vector<int> nser(int * arr,int n){

stack<int> str;

vector<int> nserarr(n);

nserarr[n-1]=n;
str.push(n-1);
for(int i=n-2;i>=0;i--){
    while(!str.empty() && arr[i]<=arr[str.top()]){
        str.pop();
    }
    if(str.empty()){
        nserarr[i]=n;
    }
    else{
        nserarr[i]=str.top();
    }
    str.push(i);
}
return nserarr;
}
int main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

        vector<int> leftb=nsel(a,n);
       vector<int> rightb=nser(a,n);
        int max=0;

        for(int i=0;i<n;i++){
            // if(i==0){
            //     cout<<leftb[i]<<" "<<rightb[i];
            // }
            int p=rightb[i]-leftb[i]-1;
            int areaa=p*a[i];
            if(areaa>max){
                max=areaa;
            }
        }
        cout<<max;
    return 0;
}
