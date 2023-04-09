#include<bits/stdc++.h>

using namespace std;

int main()
{
    string DNA2,bin_str,bin_app,plaintext;
    cout<<"Enter the Cipher Text: ";
    getline(cin,DNA2);
    char input1,input2,input3,input4,MS[32],mo[17],ST_0,ST_1,
    ST_2,ST_3,B1,B2,B3,B4;
    int dn,initial,inl,ms[16],keyb[256],intronb[128],intronb1[256];
    dn=DNA2.size();
    char DNA1[dn],key_binary[256],intron_binary[128];
    int cbinary[dn*2],rev_cbinary[dn*2],rev_cbinary1[dn],rev_cbinary2[dn],c_oe[dn*2]
    ,xor_c[256],xnor_c[256],xnor_ce[dn],xor_co[dn],CT[dn/2],CT1[dn/2];
    cout<<"Enter 32 characters from the given state table and output table in 0,1,2 and 3: ";
    cin>>MS;
    int k=0;
    for(int j=0;j<32;j++)
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
        for(int j=0;j<16;j++)
        {
            if(mo[j] == '0')
            {
                mo[j]= ST_0;
            }
            else if(mo[j] == '1')
            {
                mo[j] = ST_1;
            } 
            else if(mo[j] =='2')
            {
                mo[j] = ST_2;
            }  
            else if(mo[j] == '3')
            {
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
    cout<<endl;
    for(int i=0;i<dn;i++){
        if(initial == 0)
        {
            if(DNA2[i]==input1){
                DNA1[i]=mo[0];
            }
            else if(DNA2[i]==input2){
                DNA1[i]=mo[4];
            }
            else if(DNA2[i]==input3){
                DNA1[i]=mo[8];
            }
            else if(DNA2[i]==input4){
                DNA1[i]=mo[12];
            }
        }
        else if(initial == 1){
            if(DNA2[i]==input1){
                DNA1[i]=mo[1];
            }
            else if(DNA2[i]==input2){
                DNA1[i]=mo[5];
            }
            else if(DNA2[i]==input3){
                DNA1[i]=mo[9];
            }
            else if(DNA2[i]==input4){
                DNA1[i]=mo[13];
            }
        }
        else if(initial == 2)
        {
            if(DNA2[i]==input1){
                DNA1[i]=mo[2];
            }
            else if(DNA2[i]==input2){
                DNA1[i]=mo[6];
            }
            else if(DNA2[i]==input3){
                DNA1[i]=mo[10];
            }
            else if(DNA2[i]==input4){
                DNA1[i]=mo[14];
            }
        }
        else if(initial == 3){
            if(DNA2[i]==input1){
                DNA1[i]=mo[3];
            }
            else if(DNA2[i]==input2){
                DNA1[i]=mo[7];            
            }
            else if(DNA2[i]==input3){
                DNA1[i]=mo[11];
            }
            else if(DNA2[i]==input4){
                DNA1[i]=mo[15];
            }
        }
        //**********************************************************************************************************
        if(initial == 0){
            if(DNA1[i]==input1){
                inl=ms[0];
            }
            else if(DNA1[i]==input2){
                inl=ms[4];
            }
            else if(DNA1[i]==input3){
                inl=ms[8];
            }
            else if(DNA1[i]==input4){
                inl=ms[12];
            }
        }
        else if(initial == 1)
        {
            if(DNA1[i]==input1){
                inl=ms[1];
            }
            else if(DNA1[i]==input2){
                inl=ms[5];
            }
            else if(DNA1[i]==input3){
                inl=ms[9];
            }
            else if(DNA1[i]==input4){
                inl=ms[13];
            }
        }
        else if(initial == 2){
            if(DNA1[i]==input1){
                inl=ms[2];
            }
            else if(DNA1[i]==input2){
                inl=ms[6];
            }
            else if(DNA1[i]==input3){
                inl=ms[10];
            }
            else if(DNA1[i]==input4){
                inl=ms[14];
            }
        }
        else if(initial == 3)
        {
            if(DNA1[i]==input1){
                    inl=ms[3];
            }
        else if(DNA1[i]==input2){
                inl=ms[7];
            }
        else if(DNA1[i]==input3){
                inl=ms[11];
            }
        else if(DNA1[i]==input4){
                inl=ms[15];
            }
        }
        initial=inl;
    }    
    cout<<"DNA2 is given as input to the Mealy machine to generate another DNA sequence i.e.: \n";
    for(int i=0;i<dn;i++){
        cout<<DNA1[i];
    }
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
    int bl=0;
    for(int i=0;i<dn;i++){
        if(DNA1[i]==B1){
            cbinary[bl]=0;
            bl++;
            cbinary[bl]=0;
            bl++;
        }
        else if(DNA1[i]==B2){
            cbinary[bl]=0;
            bl++;
            cbinary[bl]=1;
            bl++;
        }
        else if(DNA1[i]==B3){
            cbinary[bl]=1;
            bl++;
            cbinary[bl]=0;
            bl++;
        }
        else if(DNA1[i]==B4){
            cbinary[bl]=1;
            bl++;
            cbinary[bl]=1;
            bl++;
        }
    }
    cout<<"The binary of the DNA sequence is: \n";
    for(int i=0;i<bl;i++){
        cout<<cbinary[i];
    }
    cout<<endl<<"Reverse of the binary string is: \n";
    int j=0;
    for(int i=bl-1;i>=0;i--){
        rev_cbinary[j]=cbinary[i];
        cout<<rev_cbinary[j];
        j++;
    }
    cout<<endl<<"First half blocks: ";
    j=0;
    for(int i=0;i<bl/2;i++){
        rev_cbinary1[i]=rev_cbinary[i];
        cout<<rev_cbinary1[i];
    }
    cout<<endl<<"Second half blocks: ";
    for(int i=bl/2;i<bl;i++){
        rev_cbinary2[j]=rev_cbinary[i];
        cout<<rev_cbinary2[j];
        j++;
    }
    cout<<endl<<"Enter the key : ";         //*******************************************
    cin>>key_binary;
    for(int i=0;i<256;i++){
        keyb[i]=key_binary[i];
    }
    for (int i = 0; i<256; i++){      
		keyb[i] = keyb[i]-48;
    }
    cout<<"Enter the intron sequence : ";         //*******************************************
    cin>>intron_binary;
    for(int i=0;i<128;i++){
        intronb[i]=intron_binary[i];
    }
    for (int i = 0; i<128; i++){      
		intronb[i] = intronb[i]-48;
    }
    j=0;
    for(int i=0;i<256;i++){
        intronb1[i]=intronb[j];
        if(j==128){
            j=0;
        }
        j++;
    }
    for(int i=0;i<256;i++){
    	xor_c[i] = (keyb[i]^intronb1[i]);
	}
    cout<<"xor:"<<endl;
	for(int i=0;i<256;i++){
    	cout<<xor_c[i];
	}
	cout<<endl;
	for(int i=0;i<256;i++){
		if(xor_c[i]==1){
			xnor_c[i]=0;
		}
		else{
			xnor_c[i]=1;
		} 
	}
    cout<<"Xnor: "<<endl;
	for(int i=0;i<256;i++){
    	cout<<xnor_c[i];
	}
    cout<<endl<<"XOR operation of first blocks: ";
    if(bl>=256){
        int k=0;
        for(j=0;j<bl/2;j++){
            xor_co[j]=(rev_cbinary1[j]^xnor_c[k]);
            k++;
            if(k>=256){
                k=0;
            }
            cout<<xor_co[j];    
        }       
    }
    else{
        j=0;
        int k=0;
        k=256-bl/2;
        for(int i=k;i<256;i++)
        {
            xor_co[j]=(rev_cbinary1[j]^xnor_c[i]);   
            cout<<xor_co[j];     
            j++;
        }
    }
    cout<<endl<<"XNOR operation of even blocks: ";
    if(bl>=256){
        int k=0;
        for(j=0;j<bl/2;j++){
            xnor_ce[j]=(rev_cbinary2[j]^xor_c[k]);
            k++;
            if(k>=256){
                k=0;
            }
            if(xnor_ce[j]==0){
                xnor_ce[j]=1;
            }
            else{
                xnor_ce[j]=0;
            }
            cout<<xnor_ce[j];    
        }       
    }
     else{
        j=0;
        int k=0;
        k=256-bl/2;
        for(int i=k;i<256;i++){
            xnor_ce[j]=(rev_cbinary2[j]^xor_c[i]);   
            if(xnor_ce[j]==0){
                xnor_ce[j]=1;
            }
            else{
                xnor_ce[j]=0;
            }
            cout<<xnor_ce[j];     
            j++;
        }
    }
    j=0;
    for(int i=0;i<bl;i++){
        c_oe[i]=xor_co[j];
        i++;
        c_oe[i]=xnor_ce[j];
        j++;
    }
    cout<<endl<<"Merging the two blocks: ";
    for(int i=0;i<bl;i++){
        cout<<c_oe[i];
    }
    int temp;
    for(int i=0;i<5;i++){
        temp=c_oe[0];
        for(j=0;j<bl-1;j++){
            c_oe[j]=c_oe[j+1];
        }
        c_oe[bl-1]=temp;
    }
    cout<<endl<<"After left shifting string 5 times: "<<endl;
    for(int i=0;i<bl;i++){
        cout<<c_oe[i];
    }
    cout<<endl;
    j=0;
    k=0;
    string bstr;
    int num=0,intdata,intdata1=0;
    for(int i=0;i<bl;i++){
        num=c_oe[i];
        bin_app = to_string(num);
        bin_str=bin_str + bin_app;
    }
    cout<<endl<<"The binary string are: ";
    for(int i=0;i<bl;i++){
        cout<<bin_str[i];
    }
    cout<<endl;
    int temp1,rem,dec=0,b=1; j=0;
    //stringstream obj;
    for(int i=0;i<bl;i++){
        if(k<8){
            k++;
            intdata=bin_str[i]-48;
            intdata1= intdata1+intdata;
            if(k==8){
                temp1=intdata1;
                while(temp1>0){
                    rem = temp1 % 10;
                    dec = dec + rem*b;
                    b *= 2;
                    temp1 /= 10;
                }
                CT[j]=dec;
                j++;
                dec=0,b=1;
                intdata1=0;
                k=0;
            }
            intdata1 = intdata1*10;
        } 
    }
    cout<<endl<<"The value of binarys are: ";
    for(int i=0;i<dn/4;i++){
        cout<<CT[i]<<" ";
    }
    cout<<endl<<"The Plaintext of Cipher:  ";
    for(int i=0;i<dn/4;i++){
        plaintext[i]=CT[i];
        cout<<plaintext[i];
    }
    return 0;
}