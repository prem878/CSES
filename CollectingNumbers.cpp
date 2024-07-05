#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arr array
int main(){
  int n;
  cin>>n;
  vector<arr<int,2>> a;
  for(int i=1;i<=n;++i){
    int x;
    cin>>x;
    a.push_back({x,i});
  }
  sort(a.begin(),a.end());
  ll res=0;
  for(int i=1;i<n;++i){
    if(a[i-1][1]>a[i][1]){
      res++;
    }else{
      continue;
    }
  }
  cout<<res+1;
  return 0;
