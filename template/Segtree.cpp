template <class T>
class Segtree{
public:
    vector<pair<T,T>>t;
    vector<T>sum,tag,a;
    function<T(T,T)>f;
    void build(int o,int l,int r)
    {
        t[o]={l,r};
        if(l==r){sum[o]= a[l];return;}
        auto mid = l+r >> 1;
        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);
        sum[o]=f(sum[o<<1],sum[o<<1|1]);
    }
    void push_down(int o)
    {
        if(tag[o])
        {
            Update_tag(o<<1,tag[o]);
            Update_tag(o<<1|1,tag[o]);
            tag[o]=0;
        }
    }
    T get(int o,int l,int r)
    {
        if(l<=t[o].x && r>=t[o].y)return sum[o];
        push_down(o);
        int mid = t[o].x+t[o].y >> 1;
        T v = 0;
        if(l<=mid)v=get(o<<1,l,r);
        if(r>mid)v=f(v,get(o<<1|1,l,r));
        return v;
    }
    void upd(int o,int l,int r,int v)
    {
        if(l<=t[o].x && r>=t[o].y)
        {
            Update_tag(o,v);
            return ;
        }
        push_down(o);
        int mid = t[o].x + t[o].y >> 1;
        if(l<=mid) upd(o<<1,l,r,v);
        if(r>mid) upd(o<<1|1,l,r,v);
        sum[o]=f(sum[o<<1],sum[o<<1|1]);
    }
    void Update_tag(ll o,ll v)  //important ! please change every time use template .
    {
        sum[o] += v*(t[o].y-t[o].x+1);
        tag[o] += v;
    }
    T query(int l,int r){return get(1,l,r);}
    void update(int l,int r,int v){upd(1,l,r,v);}
    explicit Segtree(vector<T>x,function<T(T,T)>_f):a(x),f(_f){
        int n = x.size()-1;
        t.resize((n<<2)+30);
        sum.resize((n<<2)+30);
        tag.resize((n<<2)+30);
        build(1,1,n);
    }
};
