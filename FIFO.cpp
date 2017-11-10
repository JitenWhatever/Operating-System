 #include<bits/stdc++.h>

 using namespace std ;

int main(){

	int frame,j,pgFault =0;
      string page;
      int avail ;
      cout<<"enter the page string :\n";
          cin>>page ;
		int len = page.length();
            cout<<"\n enter number of frames :";
            			cin>>frame;

            	int frm[frame];
		for(int i=0;i<frame;i++)
                frm[i]= -1;

                        j=0;
                        cout<<"\t ref string" <<"\tpage frames\n";
                for(int i=0;i<len;i++)
                        {
                                   cout<<"\t\t"<<page[i];
                                    avail=0;
                                    for(int k=0;k<frame;k++)
					if(frm[k]==page[i])
                                                avail=1;
                                    if (avail==0)
                                    {
                                                frm[j]=page[i];
                                                j=(j+1)%frame;
                                                pgFault++;
                                                for(int k=0;k<frame;k++)
                                               cout<<"\t"<<frm[k];
}
                                    cout<<"\n";
}
                          cout<<"\ntotal page fault :\n"<<pgFault<<endl;
                        return 0;
                        }

