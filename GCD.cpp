#include<bits/stdc++.h>

using namespace std;
#define MOD 1e9
typedef long long ll;

int t, n, q;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--){
    cin>>n>>q;
    cout<<gcd(n, q);
  }
}
