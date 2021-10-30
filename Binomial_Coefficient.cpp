#include<bits/stdc++.h>

using namespace std;
#define MOD 1e9
typedef long long ll;

int n, k;

int binom(int n, int k){
  int res = 1;
  if(k > n - k) k = n - k; //C(n, k) != C(n, n - k)
  for (int i = 0; i < k; i++) { // n * (n-1) * (n-2) ... (n - k - 1) / k!
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

main(){
  cin>>n>>k;
  cout<<binom(n, k)<<endl;
}
