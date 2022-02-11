template <class T>
class ST{
public:
    vector<vector<T>>st;
    vector<T>a;
    function<T(T,T)>f;
    int n;
    ST(vector<T>x,function<T(T,T)>func):a(x),f(func){
        n = a.size()-1;
        st.resize(22);
        for(int i=0;i<=21;i++)
            st[i].resize(n+10);
        for(int i=1;i<=n;i++)
            st[0][i]=a[i];
        for(int i=1;(1<<i) <= n;i++)
        {
            for(int j=1;j+(1<<(i-1))-1<=n;j++)
            {
                st[i][j] = f(st[i-1][j],st[i-1][j+(1<<(i-1))]);
            }
        }
    }
    T query(int l,int r)
    {
        int len = log2(r-l+1);
        return f(st[len][l],st[len][r-(1<<len)+1]);
    }
};
