template <class T>
class DSU
{
    vector<T>f;
    T n;
public:
    explicit DSU(T _n):n(_n)
    {
        f.resize(n+10);
        for(int i=1;i<=n;i++)f[i]=i;
    }
    void Merge(T x,T y)
    {
        T u = find(x) , v = find(y);
        if (u != v)
        f[v] = u;
    }
    T find(T x)
    {
        return f[x]=((f[x]==x)?x:find(f[x]));
    }
};
