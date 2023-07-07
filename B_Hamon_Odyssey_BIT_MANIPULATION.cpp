#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define lld long long double
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const ll MOD = 1000000007;	

bool isPrime(ll n)
{if(n==1) return false; else {for(ll i = 2;i*i<=n;i++) {if(n%i==0)return false;} return true;}}
vector<ll> sieve(int n) {int arr[n];for(int i = 0; i < n; i++)arr[i] = 0; vector<ll> vect; for (int i = 2; i * i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll Powermod(ll base, ll power, ll x){ll res = 1;while(power){if(power % 2 == 0){base = (base * base) % x;power/=2;}else{res = (res * base) % x; power--;}}return res;}
ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}

/*****  ( _ &_ & _ & _)& _ & _)   */
            //  a   >=   b

void solve()
{
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  ll X = (1LL << 30) - 1;
  ll Y = X;
  for(int i = 0; i < N; i++){
    Y &= A[i];
  }
  if(Y > 0){
    cout << "1\n";
  }
  else{
    int ans = 0;
    for(int i = 0; i < N; i++){
      X &= A[i];
      if(X == 0){
        ans++;
        X = (1LL << 30) - 1;
      }
    }
    cout << ans << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
}

  
