#include<bits/stdc++.h>

using namespace std;

bool ismobvalid(string s)
{
  const regex pattern("(0|91)?[6-9][0-9]{9}");
  if(regex_match(s, pattern))
  {
    return true;
  }
  else
  {
    cout<<"Wrong mobile number: ";
    return false;
  }
}
//*********************************************************************************DOB
const int MAX_VALID_YR = 2015;
const int MIN_VALID_YR = 1930;
 
bool isLeap(int year){
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool isValidDate(int d, int m, int y){
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
    if (m == 2)
    {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
 
    return true;
}
//***********************************************************************************************************************************

int main()
{
    string PT,PDNA,DNA2;
    int n,plen=0,klen=0,keyb[256];
    cout<<"Enter the plaintext : ";
    getline(cin,PT);
    cout<<"The plaintext is : ";
    cout<<PT;
    n= PT.size();
    char plaintext[n],key_binary[256],B1,B2,B3,B4,MS[32],mo[17],ST_0,ST_1,
    ST_2,ST_3,input1,input2,input3,input4;
    int P_A[n],pbinary[n*8],xor_p[n*8],xnor_p[n*8],xor_po[n*4],xnor_pe[n*4],
    oe[n*8],rev_oe[n*8],bl=0,initial,inl,ms[16];
    for(int i=0; i<n;i++){
        P_A[i]= int(PT[i]);
        cout<<P_A[i]<<" ";
    }
    int binaryNum[50];
    for(int i=0;i<n;i++){
        {
	       if(P_A[i] >= 0 || P_A[i]<= 255)
	        {
	        	int j=0;
            	while (P_A[i] > 0) {    
	     	        // storing remainder in binary array
		            binaryNum[j] = P_A[i] % 2;
		            P_A[i] = P_A[i] / 2;
		            //cout<<binaryNum[j];
		            j++;
	            }
	            int l=8-j;
	            int j2= j;
	            // printing binary array in reverse order
	            for (int k = j - 1; k >= 0; k--){
	            	if(j2!=8)
	            	{
	                	for(int m= 0;m<l;m++)
	     	            {
		                	pbinary[plen] = 0;
		                    plen++;
		                    j2++;
	                	}
    	            }
	                pbinary[plen]=binaryNum[k];
		            plen++;
            	}
            }
        }
    }    
    cout<<endl;
    cout<<plen<<endl;
    for(int i=0;i<plen;i++)
    {
        cout<<pbinary[i];
    }
    cout<<endl;
    int temp;
    for(int i=0;i<5;i++)
    {
        temp=pbinary[plen-1];
        for(int j=plen;j>0;j--)
        {
            pbinary[j]=pbinary[j-1];
        }
        pbinary[0]=temp;
    }
    cout<<"After right shifting string 5 times: "<<endl;
    for(int i=0;i<plen;i++){
        cout<<pbinary[i];
    }
    int podd[plen/2],peven[plen/2];
    int o=0,e=0;
    for(int i=0;i<plen;i++){
        if(i%2==0){
            podd[o]=pbinary[i];
            o++;
        }
        else{
            peven[e]=pbinary[i];
            e++;
        }
    }
    cout<<endl;
    cout<<"Odd blocks: \n";
    for(int i=0;i<plen/2;i++){
        cout<<podd[i];
    }
    cout<<endl;
    cout<<"Even blocks: \n";
    for(int i=0;i<plen/2;i++){
        cout<<peven[i];
    }
    cout<<endl<<"Enter the mobile number: \n";
    string mob,dob,dy,dob1;
    int mob1[8],day,month,year,DOB[8],mdob[16],mdob_binary[128],mobdob_binary[256];
    getline(cin,mob);
    cout<<"Enter the Date of birth: \n";
    cout<<"Day: ";
    cin>>day;
    cout<<"month: ";
    cin>>month;
    cout<<"year: ";
    cin>>year;
    stringstream day1,month1,year1;
    int mobvalid = ismobvalid(mob);
    int dobvalid = isValidDate(day, month, year);
    if(mobvalid == dobvalid == 1)
    {
        for(int i=0;i<8;i++){
            mob1[i]=int(mob[i]);
        }
        day1<<day;
        day1>>dob1;
        if(dob1.size()==1){
            dy="0";
            dy.append(dob1);
        }
        else{
            dy.append(dob1);
        }
        month1<<month;
        month1>>dob1;
        if(dob1.size()==1){
            dob="0";
            dob.append(dob1);
        }
        else{
            dob.append(dob1);
        }
        year1<<year;
        year1>>dob1;
        dob.append(dob1);
        dy.append(dob);
        // cout<<dy<<endl;
        for(int i=0;i<8;i++)
        {
            DOB[i]=int(dy[i]);
        }
        int j=0;
        for(int i=0;i<8;i++){
            mdob[j]=mob1[i];
            j++;
        }
        for(int i=0;i<8;i++){
            mdob[j]=DOB[i];
            j++;
        }
        cout<<"The ASCII value: \n";
        for(int i=0;i<16;i++){
            cout<<mdob[i]<<" ";
        }
        int pl=0;
        binaryNum[50];
        for(int i=0;i<16;i++){
	        j=0;
            while (mdob[i] > 0) {    
	     	    // storing remainder in binary array
		        binaryNum[j] = mdob[i] % 2;
		        mdob[i] = mdob[i] / 2;
		        //cout<<binaryNum[j];
		        j++;
	        }
	        int l=8-j;
	        int j2= j;
	        for (int k = j - 1; k >= 0; k--)            	        // printing binary array in reverse order
	        {
                if(j2!=8)
	            {
	                for(int m= 0;m<l;m++)
	     	        {
		                mdob_binary[pl] = 0;
		                pl++;
		                j2++;
	                }
    	        }
	            mdob_binary[pl]=binaryNum[k];
		        pl++;
            }
        }   
        j=0;
        for(int i=0;i<pl*2;i++){
            mobdob_binary[i]=mdob_binary[j];
            if(j==128){
                j=0;
            }
            j++;
        }
        cout<<endl;
        cout<<"Binary value is: "<<endl;
        for(int i=0;i<pl*2;i++){
            cout<<mobdob_binary[i];
        }
        cout<<endl<<"Enter the key : \n";         //*******************************************
        cin>>key_binary;
        for(int i=0;i<256;i++){
            keyb[i]=key_binary[i];
        }
        //********************************************************************(key binary)
        for (int i = 0; i<256; i++){      
		keyb[i] = keyb[i]-48;
        }
        for(int i=0;i<pl*2;i++){
    	xor_p[i] = (keyb[i]^mobdob_binary[i]);
	    }
        cout<<"xor:"<<endl;
	    for(int i=0;i<pl*2;i++){
    	    cout<<xor_p[i];
	    }
	    cout<<endl;
	    for(int i=0;i<pl*2;i++){
		    if(xor_p[i]==1){
			    xnor_p[i]=0;
		    }
		    else{
			    xnor_p[i]=1;
		    } 
	    }
        cout<<"Xnor: "<<endl;
	    for(int i=0;i<pl*2;i++){
    	    cout<<xnor_p[i];
	    }
//*********************************************************************************************xor and xnor operations
        cout<<endl<<"XOR operation of odd blocks: ";
        if(plen>=256){
            int k=0;
            for(j=0;j<plen/2;j++){
                xor_po[j]=(podd[j]^xnor_p[k]);
                k++;
                if(k>=256){
                    k=0;
                }
                cout<<xor_po[j];    
            }       
        }
        else{
            j=0;
            int k=0;
            k=256-plen/2;
            for(int i=k;i<256;i++)
            {
                xor_po[j]=(podd[j]^xnor_p[i]);   
                cout<<xor_po[j];     
                j++;
            }
        }
        cout<<endl<<"XNOR operation of even blocks: ";
        if(plen>=256){
            int k=0;
            for(j=0;j<plen/2;j++)
            {
                xnor_pe[j]=(peven[j]^xor_p[k]);
                k++;
                if(k>=256)
                {
                    k=0;
                }
                if(xnor_pe[j]==0){
                    xnor_pe[j]=1;
                }
                else{
                    xnor_pe[j]=0;
                }
                cout<<xnor_pe[j];    
            }       
        }
        else
        {
            j=0;
            int k=0;
            k=256-plen/2;
            for(int i=k;i<256;i++)
            {
                xnor_pe[j]=(peven[j]^xor_p[i]);   
                if(xnor_pe[j]==0){
                    xnor_pe[j]=1;
                }
                else{
                    xnor_pe[j]=0;
                }
                cout<<xnor_pe[j];     
                j++;
            }
        }
        j=0;
        for(int i=0;i<plen/2;i++){
            oe[j]=xor_po[i];
            j++;
        }
        for(int i=0;i<plen/2;i++){
            oe[j]=xnor_pe[i];
            j++;
        }
        cout<<endl<<"Concatenate of odd and even blocks: \n";
        for(int i=0;i<plen;i++){
            cout<<oe[i];
        }
        cout<<endl<<"Reverse of the merged binary: \n";
        j=0;
        for(int i=plen-1;i>=0;i--){
            rev_oe[j]=oe[i];
            cout<<rev_oe[j];
            j++;
        }
        char DNA1[plen/2];
        cout<<endl;
        cout<<"Give the row 0 character for 00,01,10 and 11 from the table"<<endl;
        cout<<"00: ";
        cin>>B1;
        cout<<"01: ";
        cin>>B2;
        cout<<"10: ";
        cin>>B3;
        cout<<"11: ";
        cin>>B4;
        j=1;
        for(int i=0;i<plen;i=i+2){
            if(rev_oe[i]==0 && rev_oe[j]==0){
                DNA1[bl]=B1;
            }
            else if(rev_oe[i]==0 && rev_oe[j]==1){
                DNA1[bl] = B2;
            } 
            else if(rev_oe[i]==1 && rev_oe[j]==0){
                DNA1[bl] = B3;
            }  
            else if(rev_oe[i]==1 && rev_oe[j]==1){
                DNA1[bl] = B4;
            }
            bl++;
            j =j+2;
        }
        cout<<endl<<"Replacing two bits of the binary number obtained in DNA base as per the row 0 number given in table :"<<endl;
        for(int i=0;i<bl;i++){
            cout<<DNA1[i];
        }        
        cout<<endl;
//****************************************************************************************************************************Mealy machine

        cout<<"Enter 32 characters from the given state table and output table in 0,1,2 and 3: ";
        cin>>MS;
        cout<<"32 Characters are: \n";
        cout<<MS<<endl;
        int k=0;
        for(j=0;j<32;j++)
        {
            if(j<16)
            {
                ms[j]=MS[j];
                ms[j]=ms[j]-48;
            }
            else{
                mo[k]=MS[j];
                k++;
            }
        }
        for(int j =0;j<16;j++)
        {
            cout<<ms[j];
        }    
        cout<<endl;
        cout<<"Give the DNA base for 0,1,2 and 3"<<endl;
        cout<<"0: ";
        cin>>ST_0;
        cout<<"1: ";
        cin>>ST_1;
        cout<<"2: ";
        cin>>ST_2;
        cout<<"3: ";
        cin>>ST_3;
        for(int j=0;j<16;j++){
            if(mo[j] == '0'){
                mo[j]= ST_0;
            }
            else if(mo[j] == '1'){
                mo[j] = ST_1;
            } 
            else if(mo[j] =='2'){
                mo[j] = ST_2;
            }  
            else if(mo[j] == '3'){
                mo[j] = ST_3;
            }
        }
        cout<<"Enter the initial state: ";
        cin>>initial;
        cout<<endl<<"Enter the input(A,T,C and G) sequentially: \n";
        cout<<"Input1: ";
        cin>>input1;
        cout<<"Input2: ";
        cin>>input2;
        cout<<"Input3: ";
        cin>>input3;
        cout<<"Input4: ";
        cin>>input4;
        for(int i=0;i<bl;i++){
            if(initial == 0){
                if(DNA1[i]==input1){
                    inl=ms[0];
                    DNA2[i]=mo[0];
                }
                else if(DNA1[i]==input2){
                    inl=ms[4];
                    DNA2[i]=mo[4];
                }
                else if(DNA1[i]==input3){
                    inl=ms[8];
                    DNA2[i]=mo[8];
                }
                else if(DNA1[i]==input4){
                    inl=ms[12];
                    DNA2[i]=mo[12];
                }
            }
            else if(initial == 1){
                if(DNA1[i]==input1){
                    inl=ms[1];
                    DNA2[i]=mo[1];
                }
                else if(DNA1[i]==input2){
                    inl=ms[5];
                    DNA2[i]=mo[5];
                }
                else if(DNA1[i]==input3){
                    inl=ms[9];
                    DNA2[i]=mo[9];
                }
                else if(DNA1[i]==input4){
                    inl=ms[13];
                    DNA2[i]=mo[13];
                }
            }
            else if(initial == 2)
            {
                if(DNA1[i]==input1){
                    inl=ms[2];
                    DNA2[i]=mo[2];
                }
                else if(DNA1[i]==input2){
                    inl=ms[6];
                    DNA2[i]=mo[6];
                }
                else if(DNA1[i]==input3){
                    inl=ms[10];
                    DNA2[i]=mo[10];
                }
                else if(DNA1[i]==input4){
                    inl=ms[14];
                    DNA2[i]=mo[14];
                }
            }
            else if(initial == 3)
            {
                if(DNA1[i]==input1){
                    inl=ms[3];
                    DNA2[i]=mo[3];
                }
                else if(DNA1[i]==input2){
                    inl=ms[7];
                    DNA2[i]=mo[7];
                }
                else if(DNA1[i]==input3){
                    inl=ms[11];
                    DNA2[i]=mo[11];
                }
                else if(DNA1[i]==input4){
                    inl=ms[15];
                    DNA2[i]=mo[15];
                }
            }
            initial=inl;
        }
        cout<<endl<<"The cipher text: ";
        for(int i=0;i<bl;i++){
             cout<<DNA2[i];
        }         
    }
    return 0;
}    