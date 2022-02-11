#include<iostream>
#include<cstring>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define rev(i,n,a) for(int i=n;i>=a;i--)
using namespace std;
typedef long long ll;

template<class T>
inline void read(T &x)
{
    char c=getchar();x=0;T f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-48;
    x=x*f;
}
