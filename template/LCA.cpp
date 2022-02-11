template<class T>
class LCA{
public:
    vector<vector<pair<T,T>>>a;
    vector<vector<T>>fa;
    vector<T>f,dis;
    int rt,n;
    void dfs(int u,int last)
    {
        fa[0][u]=last;f[u]=f[last]+1;
        for(int i=1;(1<<i)<=f[u];i++)
            fa[i][u]=fa[i-1][fa[i-1][u]];
        for(auto [v,w]:a[u])
            if(v!=last){dis[v]=dis[u]+w;dfs(v,u);}
    }
    LCA(vector<vector<pair<T,T>> >x,T rt):a(x),rt(rt){
        n = 1 + x.size();
        a.resize(n+10);
        dis.resize(n+10);
        fa.resize(25);
        for(int i=0;i<=24;i++)
            fa[i].resize(n+10);
        f.resize(n+10);
        dfs(rt,0);
    }
    int lca(int u,int v)
    {
        if(f[u]>f[v])swap(u,v);
        for(int i=24;i>=0;i--)
        {
            if(u==v)break;
            if(f[fa[i][v]]>=f[u])v=fa[i][v];
        }
        if(u==v)return u;
        for(int i=24;i>=0;i--)
        {
            if(fa[i][u]!=fa[i][v])
            {
                u=fa[i][u];v=fa[i][v];
            }
        }
        return fa[0][u];
    }
    T getdis(int u,int v)
    {
        return dis[u]+dis[v]-2*dis[lca(u,v)];
    }
};
