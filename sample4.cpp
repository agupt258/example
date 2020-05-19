	#include<bits/stdc++.h>
	using namespace std;
	//STL shortcuts
	#define pf push_front
	#define pob pop_back
	#define pof pop_front
	#define F first
	#define S second
	#define MP make_pair
	#define ll long long int 
	#define pb push_back
	#define pqbig priority_queue<ll>
	#define pqsmall priority_queue<ll,vector<ll>,greater<ll> >
	#define mp make_pair
	#define MAX 100000
	typedef pair<ll,ll> pii;
	typedef vector<ll> vi;
	typedef vector<vector<ll>> vvi;
// my code is good
	void sorted(vector<ll> &arr)
	{
		sort(arr.begin(),arr.end());
	}
	void coutarr(vector<ll> arr)
	{	
		ll n = arr.size();
		for(ll i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	void coutarr2(vector<vector<ll>> arr)
	{	
		ll n = arr.size();
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<arr[i].size();j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
	}
	string binary(ll n)
	{
	    string s;
	    while(n>0)
	    {
	        s.push_back(n%2+'0');
	        n/=2;
	    }
	    return s;
	}
 
ll multiply(ll x, ll res[], ll res_size) 
{ 
    ll carry = 0; 
    for (ll i = 0; i < res_size; i++) 
    { 
    	ll prod = res[i] * x + carry; 
    	res[i] = prod % 10; 
    	carry = prod / 10; 
    } 
    while (carry) { 
    	res[res_size] = carry % 10; 
    	carry = carry / 10; 
    	res_size++; 
    } 
    return res_size; 
} 

string power(ll x, ll n) 
{ 
    if(n == 0 )
    	return "1";
    	
    ll res[MAX]; 
    ll res_size = 0; 
    ll temp = x; 
    
    while (temp != 0) 
    { 
    	res[res_size++] = temp % 10; 
    	temp = temp / 10; 
    } 
    for (ll i = 2; i <= n; i++) 
    	res_size = multiply(x, res, res_size);
    string ans;
    for (ll i = res_size - 1; i >= 0; i--) 
    	ans.push_back(res[i]+'0');
    return ans;
}

string findSum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
        
    string str;  
    ll n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    ll carry = 0; 
    for (ll i=0; i<n1; i++) 
    { 
        ll sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        carry = sum/10; 
    } 
  
    for (ll i=n1; i<n2; i++) 
    { 
        ll sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0'); 
  
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
	string binll(string s)
	{   
	    string ans = "0";
	    ll n = s.size();
	    for(ll i=0;i<n;i++)
	    {   
	       string str;
	        if(s[i]=='1')
	            str = power(2,i);
	        else
	            str = "0";
	        ans = findSum(ans,str);
	    }
	    return ans;
	}
	int main()
	{
		ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
		//----------------------mycode-----------------------------------------------------------------------------------------
	   	ll u;
	   	cin>>u;
	   	while(u--)
	   	{
	   	    ll a,b,d,e;
	   	    cin>>a>>b>>d>>e;
	   	    string str_e = binary(e);
	   	    string temp1(60,'1');
	   	    bool flag=0;
	   	    for(ll i=0;i<str_e.size();i++)
	   	        if(str_e[i]=='1')
	   	            temp1[i]='0';
	        string str_d = binary(d);
	        string temp2(60,'1');
	   	    for(ll i=0;i<str_d.size();i++)
	   	        if((temp1[i]=='1' and str_d[i]=='1') or (temp1[i]=='0' and str_d[i]=='0'))
	   	            temp2[i]='0';
	   	    for(ll i=str_d.size();i<60;i++)
	   	        if(temp1[i]=='0')
	   	            temp2[i]='0';
	   	    string ans(60,1);
	   	    string str_ab = binary(a^b);
	   	   // cout<<str_ab<<endl;
	   	    for(ll i=0;i<str_ab.size();i++)
	   	        if((temp2[i]=='0' and str_ab[i]=='0') or (temp2[i]=='1' and str_ab[i]=='1'))
	   	            ans[i]='0';
	   	
	   	    for(ll i=str_ab.size();i<60;i++)
	   	        ans[i]=temp2[i];
	   	   // cout<<ans<<endl;
	   	    cout<<binll(ans)<<endl;
	   	}
	   return 0;
	}
