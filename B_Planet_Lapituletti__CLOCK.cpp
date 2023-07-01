#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define lld long long double
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int> vi;
typedef vector<ll> vll;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const ll MOD = 1000000007;	

bool isPrime(ll n)
{if(n==1) return false; else {for(ll i = 2;i*i<=n;i++) {if(n%i==0)return false;} return true;}}
vector<ll> sieve(int n) {int arr[n];for(int i = 0; i < n; i++)arr[i] = 0; vector<ll> vect; for (int i = 2; i * i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = i * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool isPowerofTwo(ll n){if(n == 0) return false; else return (ceil(log2(n)) == floor(log2(n)));}
ll Powermod(ll base, ll power, ll x){ll res = 1;while(power){if(power % 2 == 0){base = (base * base) % x;power/=2;}else{res = (res * base) % x; power--;}}return res;}
ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}

vector<int> arr(10, -1);
int H, M;
int check(int X, int Y){
  if(arr[X % 10] == -1 || arr[X / 10] == -1 || arr[Y % 10] == -1 || arr[Y / 10] == -1)
    return 0;
  
  int hr = arr[Y % 10] * 10 + arr[Y / 10];
  int min = arr[X % 10] * 10 + arr[X / 10];
  if(hr < H && min < M){
    return 1;
  }
  return 0;
}

void solve()
{

  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 5;
  arr[5] = 2;
  arr[8] = 8;

  cin >> H >> M;
  string S;
  cin >> S;

  int HH = (S[0] - '0') * 10 + S[1] - '0';
  int MM = (S[3] - '0') * 10 + S[4] - '0';

  while(!check(HH, MM)){
    MM++;
    if(MM == M) HH++;
    HH %= H;
    MM %= M;
  }
 
  printf("%02d:", HH);
  printf("%02d\n", MM);
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

  
