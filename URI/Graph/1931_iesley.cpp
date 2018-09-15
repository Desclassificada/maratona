#include <iostream>
#include <vector>
#include <queue>

#define MAXN 10100
#define INF 900000001

using namespace std;

typedef pair< long int,int > pii;
typedef pair< pii,pii > pv;

int processado[MAXN],n,destino;
vector<pii> vizinho[MAXN];
pv distancia[MAXN];

//esquerda -> distancia par
//direita -> distancia impar

void dijkstra(int v){
    int dist,davez,atual;
    for(int i=0;i<=n;i++){
        processado[i]=0;
        distancia[i]=pv(pii(INF,0),pii(INF,0));
    }
    distancia[v]=pv(pii(0,0),pii(0,0));
    priority_queue< pii,vector<pii>,greater<pii> > fila;
    fila.push(pii(0,v));
    while(1){
        davez=-1;
        while(!fila.empty()){
            atual=fila.top().second;
            fila.pop();
            if(!processado[davez]){
                davez=atual;
                break;
            }
        }
        if(davez==-1) break;
        processado[davez]=1;
        for(int i=0;i<vizinho[davez].size();i++){
            atual=vizinho[davez][i].second;
            dist=vizinho[davez][i].first;
            /*if(distancia[atual].first>dist+distancia[davez].first){
                if(atual==destino and (distancia[davez].second+1)%2==0){
                    distancia[atual].second=1+distancia[davez].second;
                    distancia[atual].first=dist+distancia[davez].first;
                    fila.push(pii(distancia[atual].first,atual));
                }else if(atual!=destino){
                    distancia[atual].first=dist+distancia[davez].first;
                    fila.push(pii(distancia[atual].first,atual));
                    distancia[atual].second=1+distancia[davez].second;
                }
            }*/
            //first -> distancia
            //second -> num vertices
            // first -> par
            // second -> impar
            if((distancia[davez].second.second+1)%2==0 and distancia[atual].first.first>distancia[davez].second.first+dist){
                distancia[atual].first.first=distancia[davez].second.first+dist;
                distancia[atual].first.second=distancia[davez].second.second+1;
                fila.push(pii(min(distancia[atual].first.first,distancia[atual].second.first),atual));
            }
            if((distancia[davez].first.second+1)%2!=0 and distancia[atual].second.first>distancia[davez].first.first+dist){
                distancia[atual].second.first=distancia[davez].first.first+dist;
                distancia[atual].second.second=distancia[davez].first.second+1;
                fila.push(pii(min(distancia[atual].first.first,distancia[atual].second.first),atual));
            }
        }
    }
}

int main(){
    int v,x,y,d;
    cin>>n>>v;
    destino=n;
    for(int i=0;i<v;i++){
        cin>>x>>y>>d;
        vizinho[x].push_back(pii(d,y));
        vizinho[y].push_back(pii(d,x));
    }
    dijkstra(1);
    if(distancia[destino].first.first==INF) cout<<"-1"<<endl;
    else cout<<distancia[destino].first.first<<endl;
    /*for(int i=1;i<=n;i++){
        cout<<i<<" par-> "<<distancia[i].first.first<<" "<<distancia[i].first.second<<endl;
        cout<<i<<" impar-> "<<distancia[i].second.first<<" "<<distancia[i].second.second<<endl;
    }*/
    return 0;
}

