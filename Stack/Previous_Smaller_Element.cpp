#include <iostream>
using namespace std;

    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack <int> st ;
        int n = arr.size();
        vector<int> ans( n , 0 );
        
        for( int i = 0; i< arr.size() ; i++){
            while( !st.empty() && st.top() >= arr[i]){
                
                st.pop();
                
            }
            if( st.empty()){
                ans[i]= -1;
                st.push(arr[i]);
            }else{
            ans[i] = st.top();
            st.push( arr[i]);
                
            }
        }
        return ans;
    }
