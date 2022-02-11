template<class T>
class Combine{
public:
    vector<T>inv,invp,pw;
    T n,m;
    Combine(T _n,T _m):n(_n),m(_m){
        inv.resize(n+10);
        invp.resize(n+10);
        pw.resize(n+10);
    }
    void getinv()
    {
        inv[0]=inv[1]=invp[1]=invp[0]=pw[1]=pw[0]=1;
        for(int i=2;i<=n;i++)
        {
            inv[i]=(ll)(m-m/i)*inv[m%i]%m;
            invp[i]=invp[i-1]*inv[i]%m;
            pw[i]=pw[i-1]*i%m;
        }
    }
    T C(T x,T y)
    {
        return pw[x]*invp[y]%m*invp[x-y]%m;
    }
};
