template <class T>
class Tarjan{
public:
    vector<vector<T>>a;
    vector<vector<T>>b;
    vector<vector<T>>belong;
    vector<map<T,T>>mp;
    vector<T>aval,dfn,low,scc;
    vector<T>bval;
    T n , num , cnt;
    stack<T>s;
    void init()
    {
        b.resize(n+10);
        bval.resize(n+10);
        dfn.resize(n+10);
        low.resize(n+10);
        scc.resize(n+10);
        mp.resize(n+10);
        belong.resize(n+10);
        for(int i=1;i<=n;i++)
            if(!dfn[i])tarjan(i);
        for(int x=1;x<=n;x++)
        {
            for(auto v:a[x])
            {
                if(scc[x]!=scc[v] && mp[scc[x]].count(scc[v]) == 0)
                {
                    b[scc[x]].push_back(scc[v]);
                    mp[scc[x]][scc[v]]=1;
                }
            }
        }
    }
    Tarjan(vector<vector<T>>x,vector<T>val,int _n):a(x),aval(val),n(_n),num(0),cnt(0)
    {
        init();
    }
    Tarjan(vector<vector<T>>x,int _n):a(x),n(_n),num(0),cnt(0)
    {
        aval.resize(n+10);
        for(int i=1;i<=n;i++)aval[i]=1;
        init();
    }
    void tarjan(int x)
    {
        dfn[x]=low[x]=++num;
        s.push(x);
        for(auto v:a[x])
        {
            if(!dfn[v])
            {
                tarjan(v);
                low[x]=min(low[x],low[v]);
            }
            else if(!scc[v])
            {
                low[x] = min(low[x],dfn[v]);
            }
        }
        if(dfn[x] == low[x])
        {
            ++cnt;T y;
            do{
                y = s.top();
                scc[y]=cnt;
                bval[cnt]+=aval[y];
                belong[cnt].push_back(y);
                s.pop();
            }while(x!=y);
        }
    }
};
