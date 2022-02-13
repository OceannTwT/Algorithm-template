template<class T>
class MaxflowDinic{
public:
    struct edge {
        T v;
        T w;
        T rev;
        T dir;
    };
    T n,s,t;
    vector<vector<edge>>e;
    vector<T>dis,iter;
    void add(T u,T v, T w){
        e[u].push_back(edge{ v, w, (int)e[v].size(), 1});
        e[v].push_back(edge{ u, 0, (int)e[u].size() - 1 ,-1});
    }
    void bfs(){
        queue<T>q;
        for(auto &c:dis)c = -1;
        dis[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            for (auto G : e[u])
            {
                if (dis[G.v] == -1 && G.w)
                {
                    dis[G.v] = dis[u] + 1;
                    q.push(G.v);
                }
            }
        }
    }
    T dfs(int x, ll f){
        if (x == t)
            return f;
        for (T &v = iter[x]; v < e[x].size(); v++)
        {
            edge &G = e[x][v];
            if (dis[G.v] == dis[x] + 1 && G.w)
            {
                ll d = dfs(G.v, min(G.w, f));
                if (d > 0)
                {
                    G.w -= d;
                    e[G.v][G.rev].w += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T Dinic(){
        T ans = 0;
        while (1)
        {
            bfs();
            if (dis[t] == -1) break;
            T d;
            for(auto &c :iter) c = 0;
            while ((d = dfs(s, INF)) > 0)
                ans += d;
        }
        return ans;
    }
    auto getFlowWay(){
        vector<pair<pair<T,T>,T> > Flow;
        for(int i=1;i<=n;i++)
        {
            for(auto c:e[i])
            {
                if(c.dir == -1)
                {
                    Flow.push_back({{c.v,i},c.w});
                }
            }
        }
        sort(Flow.begin(),Flow.end());
        return Flow;
    };
    MaxflowDinic(T _n,T _s, T _t):n(_n),s(_s),t(_t){
        e.resize(n+5);
        dis.resize(n+5);
        iter.resize(n+5);
    }
};
