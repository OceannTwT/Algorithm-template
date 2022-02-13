template<class T>
class Persistent_Segment{
public:
    vector<pair<T,T>>p;
    vector<T>val,a,rt,aa,sum;
    int n , cnt ;
    void build(T pre,T &pos,int l,int r,T v)
    {
        pos=++cnt;
        p[pos]=p[pre];
        val[pos]=val[pre];val[pos]++;
        sum[pos]=sum[pre];sum[pos]+=aa[v];
        if(l == r)return;
        int mid = l+r >> 1;
        if(v <= mid) build(p[pre].x,p[pos].x,l,mid,v);
        else build(p[pre].y,p[pos].y,mid+1,r,v);
    }
    T querypos(int lp,int rp,int l,int r,int k)
    {
        if(l==r)return l;
        T v = val[p[rp].x] - val[p[lp].x];
        int mid = (l+r) >> 1;
        if(k <= v) return querypos(p[lp].x,p[rp].x,l,mid,k);
        else return querypos(p[lp].y,p[rp].y,mid+1,r,k-v);
    }
    T queryk(int l,int r,int k) // l to r make kth
    {
        return aa[querypos(rt[l-1],rt[r],1,n,k)];
    }
    T queryHighk(int l,int r,int k) // l to r make best kth
    {
        return aa[querypos(rt[l-1],rt[r],1,n,r-l+2-k)];
    }
    T querysum(int lp,int rp,int l,int r,T k) //
    {
        if(l==1&&r==n)k= lower_bound(aa.begin(),aa.end(),k)-aa.begin();
        if(k>r)return 0;
        if(l == r)return sum[rp]-sum[lp];
        int mid = l+r >> 1;
        if(k > mid)return querysum(p[lp].y,p[rp].y,mid+1,r,k);
        else return querysum(p[lp].x,p[rp].x,l,mid,k)+sum[p[rp].y]-sum[p[lp].y];
    }
    T getNotLowerSum(int l,int r,T k)
    {
        return querysum(rt[l-1],rt[r],1,n,k);
    }
    T getUpperSum(int l,int r,T k)
    {
        return querysum(rt[l-1],rt[r],1,n,k+1);
    }
    T getLowerSum(int l,int r,T k)
    {
        return querysum(rt[l-1],rt[r],1,n,-1e9) - querysum(rt[l-1],rt[r],1,n,k);
    }
    T getNotUpperSum(int l,int r,T k)
    {
        return querysum(rt[l-1],rt[r],1,n,-1e9) - querysum(rt[l-1],rt[r],1,n,k+1);
    }
    explicit Persistent_Segment(vector<T>x):a(x),cnt(0){
        n = (int)x.size()-1;
        aa = a;
        p.resize((n<<5)+10);
        val.resize((n<<5)+10);
        rt.resize((n<<5)+10);
        sum.resize((n<<5)+10);
        sort(aa.begin(),aa.end());
        for(int i=1;i<=n;i++) {
            a[i]  = lower_bound(aa.begin(), aa.end(), a[i]) - aa.begin();
        }
        for(int i=1;i<=n;i++)
        {
            build(rt[i - 1], rt[i], 1, n, a[i]);
        }
    }
};
