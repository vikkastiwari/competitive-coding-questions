#include <bits/stdc++.h>
using namespace std;

template <int MOD_>
struct modnum
{
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;

    int v;

    static int minv(int a, int m)
    {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD))
    {
        if (v < 0)
            v += MOD;
    }
    explicit operator int() const { return v; }
    friend std::ostream &operator<<(std::ostream &out, const modnum &n) { return out << int(n); }
    friend std::istream &operator>>(std::istream &in, modnum &n)
    {
        ll v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator==(const modnum &a, const modnum &b) { return a.v == b.v; }
    friend bool operator!=(const modnum &a, const modnum &b) { return a.v != b.v; }

    modnum inv() const
    {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum &m) { return m.inv(); }
    modnum neg() const
    {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum &m) { return m.neg(); }

    modnum operator-() const
    {
        return neg();
    }
    modnum operator+() const
    {
        return modnum(*this);
    }

    modnum &operator++()
    {
        v++;
        if (v == MOD)
            v = 0;
        return *this;
    }
    modnum &operator--()
    {
        if (v == 0)
            v = MOD;
        v--;
        return *this;
    }
    modnum &operator+=(const modnum &o)
    {
        v += o.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    modnum &operator-=(const modnum &o)
    {
        v -= o.v;
        if (v < 0)
            v += MOD;
        return *this;
    }
    modnum &operator*=(const modnum &o)
    {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum &operator/=(const modnum &o)
    {
        return *this *= o.inv();
    }

    friend modnum operator++(modnum &a, int)
    {
        modnum r = a;
        ++a;
        return r;
    }
    friend modnum operator--(modnum &a, int)
    {
        modnum r = a;
        --a;
        return r;
    }
    friend modnum operator+(const modnum &a, const modnum &b) { return modnum(a) += b; }
    friend modnum operator-(const modnum &a, const modnum &b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum &a, const modnum &b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum &a, const modnum &b) { return modnum(a) /= b; }
};

template <typename T>
T pow(T a, long long b)
{
    assert(b >= 0);
    T r = 1;
    while (b)
    {
        if (b & 1)
            r *= a;
        b >>= 1;
        a *= a;
    }
    return r;
}

using num = modnum<998244353>;

vector<num> fact, ifact;

void init()
{
    int N = 2100000;
    fact = {1};
    for (int i = 1; i < N; i++)
        fact.push_back(i * fact[i - 1]);
    ifact.resize(N);
    ifact.back() = 1 / fact.back();
    for (int i = N - 1; i > 0; i--)
        ifact[i - 1] = i * ifact[i];
}

num ncr(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * ifact[k] * ifact[n - k];
}

num dp[11][11][3][51];
num ndp[11][11][3][51];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    init();
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n - 1);
    for (int &s : a)
        cin >> s;
    // stones taken
    // number paths
    // ends
    for (int f = 0; f <= 10; f++)
        for (int g = 0; g <= 10; g++)
            for (int h = 0; h <= 2; h++)
                for (int res = 0; res <= 50; res++)
                    dp[f][g][h][res] = 0;
    dp[0][0][0][0] += 1;
    num ans = 0;
    for (int j = 0; j < n; j++)
    {
        for (int f = 0; f <= 10; f++)
            for (int g = 0; g <= 10; g++)
                for (int h = 0; h <= 2; h++)
                    for (int res = 0; res <= 50; res++)
                        ndp[f][g][h][res] = 0;
        for (int taken = 0; taken <= y; taken++)
        {
            for (int paths = 0; paths <= y; paths++)
            {
                for (int ends = 0; ends <= 2; ends++)
                {
                    // don't take
                    for (int res = 0; res < x; res++)
                    {
                        ndp[taken][paths][ends][res] += dp[taken][paths][ends][res];
                    }
                    // take end
                    if (taken + 1 <= y && ends <= 1)
                    {
                        // nothing
                        for (int res = 0; res < x; res++)
                        {
                            ndp[taken + 1][paths][ends + 1][res] += dp[taken][paths][ends][res];
                        }
                        // path
                        if (paths >= 1)
                        {
                            for (int res = 0; res < x; res++)
                            {
                                ndp[taken + 1][paths - 1][ends + 1][res] += dp[taken][paths][ends][res] * paths;
                            }
                        }
                        if (ends == 1 && paths == 0 && taken + 1 == y)
                        {
                            ans += dp[taken][paths][ends][0];
                        }
                    }
                    // take middle
                    if (taken + 1 <= y)
                    {
                        // nothing
                        if (paths + 1 <= y)
                        {
                            for (int res = 0; res < x; res++)
                            {
                                ndp[taken + 1][paths + 1][ends][res] += dp[taken][paths][ends][res];
                            }
                        }
                        // one path
                        if (paths)
                        {
                            for (int res = 0; res < x; res++)
                            {
                                ndp[taken + 1][paths][ends][res] += dp[taken][paths][ends][res] * 2 * paths;
                            }
                        }
                        // two path
                        if (paths >= 2)
                        {
                            for (int res = 0; res < x; res++)
                            {
                                ndp[taken + 1][paths - 1][ends][res] += dp[taken][paths][ends][res] * paths * (paths - 1);
                            }
                        }
                        // end
                        if (ends)
                        {
                            for (int res = 0; res < x; res++)
                            {
                                ndp[taken + 1][paths][ends][res] += dp[taken][paths][ends][res] * ends;
                            }
                        }
                        // end path
                        if (ends && paths)
                        {
                            for (int res = 0; res < x; res++)
                            {
                                ndp[taken + 1][paths - 1][ends][res] += dp[taken][paths][ends][res] * ends * paths;
                            }
                        }
                        // ends
                        if (taken + 1 == y && paths == 0 && ends == 2)
                        {
                            ans += dp[taken][paths][ends][0];
                        }
                    }
                }
            }
        }
        for (int f = 0; f <= 10; f++)
            for (int g = 0; g <= 10; g++)
                for (int h = 0; h <= 2; h++)
                    for (int res = 0; res <= 50; res++)
                        dp[f][g][h][res] = ndp[f][g][h][res];
        // for(int f = 0; f <= 10; f++) for(int g = 0; g <= 10; g++) for(int h = 0; h <= 2; h++) for(int res = 0; res <= 50; res++){
        // 	if(dp[f][g][h][res] != 0){
        // 		cerr << f << ' ' << g << ' ' << h << ' ' << res << ' ' << dp[f][g][h][res] << '\n';
        // 	}
        // }
        // cerr << '\n';
        if (j < n - 1)
        {
            for (int f = 0; f <= 10; f++)
                for (int g = 0; g <= 10; g++)
                    for (int h = 0; h <= 2; h++)
                        for (int res = 0; res <= 50; res++)
                            ndp[f][g][h][res] = 0;
            for (int taken = 0; taken <= y; taken++)
            {
                for (int paths = 0; paths <= y; paths++)
                {
                    for (int ends = 0; ends <= 2; ends++)
                    {
                        int gain = (a[j] * (ends + 2 * paths)) % x;
                        for (int res = 0; res < x; res++)
                        {
                            ndp[taken][paths][ends][(gain + res) % x] += dp[taken][paths][ends][res];
                        }
                    }
                }
            }
            for (int f = 0; f <= 10; f++)
                for (int g = 0; g <= 10; g++)
                    for (int h = 0; h <= 2; h++)
                        for (int res = 0; res <= 50; res++)
                            dp[f][g][h][res] = ndp[f][g][h][res];
        }
    }
    cout << (2 * ans) << '\n';
}