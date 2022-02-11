template<class T>
class Sieve{
public:
    vector<T>pri,npri,phi,mu;
    T n,cnt;
    explicit Sieve(T _n):n(_n),cnt(0){
        pri.resize(n+10);
        npri.resize(n+10);
        phi.resize(n+10);
        mu.resize(n+10);
        phi[1]=1;npri[1]=1;mu[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(!npri[i])
            {pri[++cnt]=i;phi[i]=i-1;mu[i]=-1;}
            for(int j=1;j<=cnt && i*pri[j]<=n;j++)
            {
                npri[i*pri[j]]=1;
                if(i%pri[j]==0)
                {
                    phi[i*pri[j]]=phi[i]*pri[j];
                    break;
                }
                else {
                    phi[i * pri[j]] = phi[i] * phi[pri[j]];
                    mu[i * pri[j]] = -mu[i];
                }
            }
        }
    }
};
