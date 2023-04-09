#include<bits/stdc++.h>

using namespace std;

int main()
{
    char S[256];
    char SO[33],Base_1,Base_2,Base_3,Base_4;
    int S_O[300],Mbinary[300],base[256];
    int mlen=0;
    cout<<"Enter 32 characters from the given state table and output table in 0,1,2 and 3: ";
    cin>>SO;
    cout<<"32 Characters are: \n";
    cout<<SO;
    cout<<endl;
    cout<<"The ASCII values of 32 characters:"<<endl;
    for (int i = 0; i <strlen(SO); i++)              // converting to ascii value
	{
		S_O[i] = int(SO[i]);
        cout<<S_O[i]<<" ";
    }
    int binaryNum[50];
    for(int i=0;i<strlen(SO);i++)
	{
        {
	       if(S_O[i] >= 0 || S_O[i]<= 255)
	        {
	        	int j=0;
            	while (S_O[i] > 0) 
	        	{    
	     	        // storing remainder in binary array
		            binaryNum[j] = S_O[i] % 2;
		            S_O[i] = S_O[i] / 2;
		            //cout<<binaryNum[j];
		            j++;
	            }
	            int l=8-j;
	            int j2= j;
	            // printing binary array in reverse order
	            for (int k = j - 1; k >= 0; k--)
	            {
		
	            	if(j2!=8)
	            	{
	                	for(int m= 0;m<l;m++)
	     	            {
		                	Mbinary[mlen] = 0;
		                    mlen++;
		                    j2++;
	                	}
    	            }
	                Mbinary[mlen]=binaryNum[k];
		            mlen++;
            	}
            }
        }
   }
   cout<<endl;
   for(int i = 0;i<mlen;i++)
    {
	     cout<<Mbinary[i];
    }
    cout<<endl;
    cout<<"total bit of binary :"<<mlen<<endl;
    cout<<"Choose the dna base for 00,01,10 and 11 from the table"<<endl;
    cout<<"00: ";
    cin>>Base_1;

    cout<<"01: ";
    cin>>Base_2;

    cout<<"10: ";
    cin>>Base_3;

    cout<<"11: ";
    cin>>Base_4;

    int k=0, j=1;
    for(int i=0;i<256;i=i+2)
    {
        if(Mbinary[i]==0 && Mbinary[j]==0)
        {
            S[k]=Base_1;
        }
        else if(Mbinary[i]==0 && Mbinary[j]==1)
        {
            S[k] = Base_2;
        } 
        else if(Mbinary[i]==1 && Mbinary[j]==0)
        {
            S[k] = Base_3;
        }  
        else if(Mbinary[i]==1 && Mbinary[j]==1)
        {
            S[k] = Base_4;
        }
        k++;
        j =j+2;
    }
    cout<<"Replacing two bits of the binary number obtained in DNA base as per the row number of given in table :"<<endl;
    cout<<S<<endl;
    return 0;
}