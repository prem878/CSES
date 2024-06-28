#include <bits/stdc++.h>
#define MOD 100000007
#define ll long long
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define all(a) (a).begin(),(a).end()
using namespace std;
const int pinf=INT_MAX;
const int ninf=INT_MIN;
const ll mod=1e9+7;
template <typename T> 
T max2(T x,T y){
	return x>y ? x: y;
}
template <typename T>
T max3(T x,T y,T z){
	T mx=Max(x,y);
	mx=Max(mx,z);
	return mx;
}
template <typename T>
T min2(T x,T y){
	return x>y ? y:x;
}
template <typename T>
T min3(T x,T y,T z){
	T mn=Min(x,y);
	mn=Min(mn,z);
	return mn;
}

/* 便利な方法 */
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll pow(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) { res = res * a; } a = a * a; b >>= 1; } return res; }
bool sq(ll n) { return (sqrt(n) == floor(sqrt(n))); }
bool cb(ll n) { return (cbrt(n) == floor(cbrt(n))); }
bool isPrime(int n) { if (n <= 1) { return false; } for (int i = 2; i * i <= n; ++i) { if (n % i == 0) { return false; } } return true; }
bool isSubstr(const string& t,const string& s){ return t.find(s)!=string::npos;}
void solve();
void timeTaken(){
	auto start=chrono::high_resolution_clock::now();
	solve();
	cout<<"\n";
	auto end=chrono::high_resolution_clock::now();
	auto time=chrono::duration_cast<chrono::microseconds>(end-start);
	cout<<"Time: "<<time.count()<<"\n";
}

//入力する前に問題を 回よく読んでください
//解決する
int n,m;
char a[2003][2003];
bool vis[2003][2003];
void dfs(int i,int j){
	if(vis[i][j]==true || i<0 || i>=n || j<0 || j>=m || a[i][j]=='#')return;
	vis[i][j]=true;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j-1);
	dfs(i,j+1);
}
void solve(){
	cin>>n>>m;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>a[i][j];
	int fk=0;int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='.' && vis[i][j]==false){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;	
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tt;	tt=1;
	//cin>>tt;
    while (tt--) {
        solve();
		//timeTaken();
        cout << "\n";
    }
    return 0;
}
