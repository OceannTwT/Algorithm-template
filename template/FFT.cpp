template<class T>
class FFT{
public:
    struct cp{
        double x,y;
        cp operator +(const cp &e)const{return {x+e.x,y+e.y};};
        cp operator -(const cp &e)const{return {x-e.x,y-e.y};};
        cp operator *(const cp &e)const{return {x*e.x-y*e.y,x*e.y+y*e.x};};
    };
    
    vector<T>rev,res;
    vector<cp>a,b;
    int n,m,tot,len;
    const double PI = acos(-1);
    explicit FFT(vector<T>x,vector<T>y){
        n=x.size()-1;m=y.size()-1;tot = 0;len = n+m;
        a.resize(4*max(n,m)+10);
        b.resize(4*max(n,m)+10);
        rev.resize(4*max(n,m)+10);
        res.resize(4*max(n,m)+10);
        for(int i=0;i<=n;i++)a[i].x=x[i];
        for(int i=0;i<=m;i++)b[i].x=y[i];
    }
    void make_FFT(vector<cp>&ra,int inv)
    {
        for(int i=0;i<tot;i++)
        {
            if(i<rev[i])swap(ra[i],ra[rev[i]]);
        }
        for(int mid = 1;mid < tot ;mid<<=1)
        {
            auto w1 = cp({cos(PI/mid),inv*sin(PI/mid)});
            for (int i = 0; i < tot; i+=mid*2) {
                auto wk = cp({1,0});
                for(int j=0;j<mid;j++,wk=wk*w1)
                {
                    auto x = ra[i+j],y=wk*ra[i+j+mid];
                    ra[i+j]=x+y;ra[i+j+mid]=x-y;
                }
            }
        }
    }
    void fft()
    {
        int bit = 0;
        while((1<<bit)<n+m+1)++bit;
        tot = 1<<bit;
        for(int i=0;i<=tot-1;i++)
        {
            rev[i]=rev[i>>1]>>1 | ((i&1)<<(bit-1)) ;
        }
        make_FFT(a,1);make_FFT(b,1);
        for(int i=0;i<tot;i++)a[i]=a[i]*b[i];
        make_FFT(a,-1);
        for(int i=0;i<=len;i++)res[i] = (int)(a[i].x/tot+0.5);
    }
};
