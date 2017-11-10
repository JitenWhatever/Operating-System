#include<bits/stdc++.h>
using namespace std ;
struct ReadyQueue {
     int  pid , at, bt, ct, wt, tat, pr;
      int tag;
}q[10];
int n;
int  main() {
 cout<<"enter number of processes : " ;
          int n ;	 cin>>n;
          int temp=0;	  int time  = 0; 		 int TotalTat = 0;	 int TotalWt =0 ;
          int maxp ;
          cout<<"enter processes id's : \n";
          	  for(int i=0;i<n;i++)   cin>>q[i].pid ;
          cout<<"enter arrival time of processes : \n";
            	for(int i=0;i<n;i++)  cin>>q[i].at;
          cout<<"enter burst time  of processes : \n";
          for(int i=0;i<n;i++)  {
             cin>>q[i].bt ;	 temp+=q[i].bt ; 	 q[i].tag=0; 	}
         cout<<"enter priorities of processes : \n";
         	for(int i=0;i<n;i++)  cin>>q[i].pr ;
for(int i=0;i<n-1;i++) {
       	for(int j=i+1;j<n;j++) {
       		   if(q[i].at>q[j].at) {	 struct  ReadyQueue temp ;
     		temp=q[i] ;    	q[i]=q[j] ;	  q[j]=temp ;
}
		}
		}
      q[9].pr = -9999;
//cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"PRI\n";
       for(time =q[0].at; time < temp;)  {
            maxp = 9;     for(int i = 0; i < n; i++) {
                  if(q[i].at <= time && q[i].tag != 1 && q[i].pr > q[maxp].pr)
                  			maxp = i ;
  }
            time = time + q[maxp].bt;
            q[maxp].ct = time;
             q[maxp].tat = q[maxp].ct - q[maxp].at;
            q[maxp].wt = q[maxp].tat - q[maxp].bt;

            q[maxp].tag = 1;
            TotalWt+=q[maxp].wt;
            TotalTat+=q[maxp].tat;
 //cout<<q[maxp].pid<<"\t"<<q[maxp].at<<"\t"<<q[maxp].bt<<"\t"<<q[maxp].ct<<"\t"<<q[maxp].tat<<"\t"<<q[maxp].wt<<"\t"<<q[maxp].pr<<endl ;
      }
      cout<<"\n" ;
         cout<<"average waiting time : "<<(float)TotalWt/n<<endl ;
         cout<<"average turn around time : "<<(float)TotalTat/n<<endl;
         return 0;

}

