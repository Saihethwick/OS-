#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int memsize;
    int allocp=-1;
    int pos;
    int allocSize;
}m[200];
bool posSort(node a,node b){
    return a.pos < b.pos; 
}
bool memSort(node a,node b){
    return a.memsize > b.memsize; 
}
int main(){
    int nm,np,choice, i, j, p[200];
    cout<<"Enter number of blocks\n";
    cin>>nm;
    cout<<"Enter block size\n";
    for(i=0;i<nm;i++){
        cin>>m[i].memsize;
        m[i].pos=i;
    }
    cout<<"Enter number of processes\n";
    cin>>np;
    cout<<"Enter process size\n";
    for(i=0;i<np;i++){
        cin>>p[i];
    }
    cout<<"\n\n";
    sort(m,m+nm,memSort);
    int globalFlag=0;
    for(i=0;i<np;i++){
        int flag=0;
        for(j=0;j<nm;j++){
            if(p[i]<=m[j].memsize && m[j].allocp==-1){
                m[j].allocp=i;
                m[j].allocSize=p[i];
                flag=1;
                break;
            }
        }
        if(flag==0){
                cout<<"Unallocated Process P"<<i+1<<"\n";
                globalFlag=1;    
            }
        }
    sort(m,m+nm,posSort);
}
