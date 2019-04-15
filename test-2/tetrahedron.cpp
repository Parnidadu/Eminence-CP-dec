typedef long long ll;
#define MOD 1000000007
ll solve(int n)
{
	// Write your code here.
     if(n == 1) return 0;

    ll *power = new ll[n];
    power[0] = 1;
    for(ll i = 1; i < n; i++) power[i] = (3*power[i-1])%MOD;

    ll answer = power[n-1];
    bool add = false;
    for(ll i = n-2; i >= 1; i--){
        if(add) answer = (answer+power[i])%MOD;
        else answer = (answer-power[i])%MOD;

        add = !add;
    }

    return (answer+MOD)%MOD;

}
