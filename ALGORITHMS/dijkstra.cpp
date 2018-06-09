#include <iostream>
#include <vector>
#include <fstream>
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep(i,n) for(int i=0;i<n;i++);
using namespace std;
const int Max=100,maxc=100000;

typedef pair <int,int> ii;

vector <ii> adj[Max];

int n,m,s,f,trace[Max],d[Max];
bool stop,Free[100];
void Enter(){
    freopen("dijkstra.inp","r",stdin);
    cin>>n>>m>>s>>f;
    rep(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(ii(w,v));
        adj[v].push_back(ii(w,u));
    }
}
void Init(){
    rep1(i,n) d[i]=maxc;
    d[s]=0;
    stop=true; //necessary?
}
void Dijkstra(){
    while (stop==false){
        int u=0,min=maxc;
        rep1(i,n) if (Free[i]&&d[i]<min){
            min=d[i];
            u=i;
        }
        if ((u==0)||(u==f)) break;
        Free[u]=false;
        int j;
        rep(j,adj[u].size()){
            int v=adj[u][j].second;
            if ((Free[v])&&(d[v]>d[u]+adj[u][j].first)){
                d[v]=d[u]+adj[u][j].first;
                trace[v]=u;
            }
        }
    }
}
void PrintResult(){
    freopen("dijkstra.out","w",stdout);int j;
    rep1(u,n) {rep(j,adj[u].size()) cout<<adj[u][j].second<<" "; cout<<endl;}
    if (trace[f]==0) cout<<"Path not found";
    else {
        cout<<"Cost: "<<d[f];
        while(f!=s){
            cout<<f<<"<-";
            f=trace[f];
        }
        cout<<s;
    }
}
int main(){
    Enter();
    Init();
    Dijkstra();
    PrintResult();
}
