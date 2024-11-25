#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,mini = INT_MAX;
    cout<<"Enter the no.of strings:";
    cin>>n;
    vector<string> box(n);
    cout<<"Enter strings:"<<endl;
    for(int i=0;i<n;i++) cin>>box[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cnt = 0;
            for(int k=0;k<box[i].size();k++){
                cnt += (box[i][k] != box[j][k]) ? 1 : 0;
            }
            cout<<cnt<<" ";
            mini = min(mini,cnt);
        }
    }
    cout<<endl;
    cout<<"Hamming distances:"<<mini<<endl;
    cout<<"No.of bits detected:"<<mini-1<<endl;
    cout<<"No.of bits corrected:"<<(mini-1)/2<<endl;
    return 0;
}
