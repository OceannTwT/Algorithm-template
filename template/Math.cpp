template<class T>
class Math{
public:
    void exgcd(ll a, ll b, T &x, T &y) {
        if (!b) {
            x = 1;
            y = 0;
            return;
        }
        exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    T inv(T a, T p) {
        T x, y;
        exgcd(a, p, x, y);
        return (x % p + p) % p;
    }
    T fpow(T a,T b,T m)
    {
        if(!b)return 1;
        T res = a;
        if(b&1){--b;res=a;}
        b>>=1;a=(a%m*a%m)%m;
        return res*fpow(a,b,m)%m;
    }
};
