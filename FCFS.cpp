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

        int ttat =0 ;
        int twt =0 ;
        ct[0]=bt[0] ;
        twt = wt[0] ;

        tat[0]=ct[0]-at[0] ;
         ttat = tat[0] ;
    for(int i=1;i<n;i++){
        ct[i] = ct[i-1] + bt[i] ;
        tat[i] = ct[i] - at[i] ;
         ttat+=tat[i] ;
        wt[i] = tat[i]- bt[i] ;


         twt+=wt[i] ;

    }

    cout<<"CT"<<" TAT "<<" WT "<<" RT "<<endl ;
        for(int i=0;i<n;i++){
            cout<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<" "<<wt[i]<<endl ;
        }

        cout<<" avg TAT "<<" avg WT "<<" avg RT "<<endl ;
         cout<<" "<< (float)ttat/n<<"   "<<(float)twt/n<<"   "<<(float)twt/n<<endl ;

return 0;
}
