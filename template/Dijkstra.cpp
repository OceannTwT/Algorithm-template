template<class T>
class Dijkstra{
public:
    vector<vector<pair<T,T>>>a;
    vector<ll>dis,vis;
    T n,s;
    const ll INF = 1e15;
    explicit Dijkstra(vector<vector<pair<T,T>>>x,int s):a(x),s(s){
        n = x.size();
        x.resize(n+10);
        dis.resize(n+10);
        vis.resize(n+10);
        for(int i=1;i<=n;i++)dis[i]=INF;
        priority_queue<pair<T,T>,vector<pair<T,T>>,greater<pair<T,T>> >q;
        q.push({0,s});dis[s]=0;
        while(!q.empty())
        {
            auto u = q.top().y;q.pop();
            if(vis[u])continue;
            vis[u]=1;
            for(auto [v,w]:a[u])
            {
                if(dis[u]+w<dis[v])
                {
                    dis[v]=dis[u]+w;
                    q.push({dis[v],v});
                }
            }
        }
    }
};
