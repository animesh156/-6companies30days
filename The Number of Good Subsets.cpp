typedef long long ll;

class Solution {

    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    ll mod = 1e9 + 7;
    ll dp[32][1025];

public:

    bool isFactor(ll n, ll f)
    {
        return n%f == 0;
    }

    ll power(ll n, ll r)
    {
        ll ans = 1;
        for(ll i=1; i<=r; i++)
            ans = (ans * n)%mod;
        return ans%mod;
    }
    
    ll help(ll id, vector<ll> &a, ll mask)      // id = curr num 
    {
        if(id == a.size())
            return mask != 0;                   // mask == 0 means empty subset

        if(dp[id][mask] != -1)
            return dp[id][mask];

        ll exl = help(id+1, a, mask)%mod;
        ll inc = 0, nm = 0;                     // nm = new mask

        bool canTake = 1;

        for(ll i=0; i<primes.size(); i++)
        {
            if(isFactor(id, primes[i]))
            {
                bool check = mask & (1<<i);
                if(isFactor(id/primes[i], primes[i]) || check)   
                {
                    canTake = 0;        // cam't take curr num if hv already taken a number with 
                    break;          // common prime factor or curr num has exponent > 1 for a num 
                }                   // in its prime factorization (e.g 8 = 2^3)
                nm = nm | (1<<i);   // updating the mask
            }
        }

        if(canTake)
        {
            inc = help(id+1, a, (nm | mask))%mod;
            ll x = (id == 1) ? (power(2ll, a[id])%mod)-1 : a[id]%mod;   // handling the 1's
            inc = ((inc * x))%mod;
        }

        return dp[id][mask] = (inc + exl)%mod;   
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<ll> a(31, 0);               // to store the frequency of each number
        for(auto i: nums)
            a[i]++;
        return help(1, a, 0)%mod;
    }
};
