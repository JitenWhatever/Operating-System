#include<bits/stdc++.h>

using namespace std ;


int main(){

    int n;
    cin>>n;

    vector<int>pid(n,0);
    vector<int>at(n,0);
    vector<int>bt(n,0);
    vector<int>ct(n,0);
    vector<int>tat(n,0);
    vector<int>wt(n,0) ;
    cout<<"enter the processes id :\n";
        for(int i=0;i<n;i++){
                cin>>pid[i];
        }
    cout<<"enter the arival times of processes :\n";
            for(int i=0;i<n;i++){
                cin>>at[i];
        }
    cout<<"enter the burst times of proceses :\n" ;
        for(int i=0;i<n;i++){
                cin>>bt[i];
        }

        for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(at[i]>at[j]){
                        swap(at[i],at[j]);
                        swap(bt[i],bt[j]);
                        swap(pid[i],pid[j]);

                    }
                }

        }
        int btsf =0 ;
        int k=1 ;
         int ttat =0 ;
        int twt =0;
        for(int i=0;i<n;i++){

        btsf+=bt[i] ;
        for(int j=k;j<n;j++){
            if(btsf>=at[j]&&bt[j]<bt[k]){
                swap(pid[j],pid[k]);
                swap(at[j],at[k]);
                swap(bt[j],bt[k]);
            }
        }
        k++ ;
        }
        ct[0]=bt[0]+ at[0] ;
        tat[0] = ct[0]-at[0] ;
        twt=wt[0];
        ttat= tat[0] ;
        for(int i=1;i<n;i++){
            ct[i] = ct[i-1]+ bt[i] ;
             tat[i] = ct[i]-at[i] ;
             wt[i] = tat[i]-bt[i] ;
             twt+=wt[i] ;
             ttat+=tat[i] ;
        }
        cout<<"\n"<<(double)ttat/n<<"\t"<<(double)twt/n<<endl;

return 0;
}
