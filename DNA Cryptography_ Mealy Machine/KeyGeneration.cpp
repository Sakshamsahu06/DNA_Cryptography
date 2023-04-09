#include<bits/stdc++.h>
#include <regex>

using namespace std;

//*********************************************** Email
bool isChar(char c)                               //is character or not
{
	return ((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)                       //is digit or not
{
	return (c >= '0' && c <= '9');
}

bool is_valid(string email)                      //function to check email is valid or not
{
	if (!isChar(email[0]))                       //Check the first character is an alphabet or not
	{
		return 0;
	}
	int At = -1, Dot = -1;

	for (int i = 0;i < email.length(); i++) 
		{
		if (email[i] == '@') 
		{
			At = i;
		}
		else if (email[i] == '.') 
		{
			Dot = i;
		}
	}

	if (At == -1 || Dot == -1)                                     // If At or Dot is not present
		return 0;
	
	if (At > Dot)                                                  // If Dot is present before At
		return 0;

	return !(Dot >= (email.length() - 1));                         // If Dot is present at the end
} 

//**************************************************************MAC
bool isValidMACAddress(string macaddress)                          // Function to validate the MAC address
{

	const regex pattern(                                           // Regex to check valid MAC address
	"^([0-9A-Fa-f]){5}"
	"([0-9A-Fa-f]{2})|([0-9a-"
	"fA-F]{4}[0-9a-fA-F]"
	"{4}[0-9a-fA-F]{4})$");

	if (macaddress.empty())
	{
		return false;
	}
	if (regex_match(macaddress, pattern))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//*************************************************************PAN
bool isValidalphanumeric(string alphanumeric)
{
	const regex pattern("[A-Za-z0-9]{10}");
	if (alphanumeric.empty()) {
		return 0;
	}
	if (regex_match(alphanumeric, pattern))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//********************************************************************

//*********************************************************************

int main()
{
	string ss=" ";
	int EM[200],con[200],PN[50],EMP[300],empbinary[1000],emprask[1000];
	int emp_len=0;
	char email[100], email_mac[200], e_m_p[200];
    cout << "Enter your email address\n";
    gets(email);
	strcpy(email_mac,email);
	char alphanumeric[11];
    cout<<"Enter the alpha-numeric\n";
	gets(alphanumeric);
	strcpy(e_m_p,alphanumeric);
	char MAC[18], MAC2[13];
    cout<<"Enter the MAC Address\n";
	gets(MAC);
	
	int email1 = is_valid(email);
	int alphanumeric1 = isValidalphanumeric(alphanumeric);
	int MAC1 = isValidMACAddress(MAC);
	if(email1==alphanumeric1==MAC1==1)
	{
    	cout<< strcat(email_mac, MAC)<<endl;
		strcat(e_m_p,email_mac);
		
		for (int i = 0; i < strlen(email_mac); i++)              // converting to ascii value
		{
			con[i] = int (email_mac[i]);
		    EM[i]= con[i];
		}
		cout<<"ASCII value of mail and MAC ";
		for (int j = 0; j < strlen(email_mac); j++)
		{
			cout<<EM[j]<<" ";
		}

		for (int i = 0; i < strlen(alphanumeric); i++)              // converting PAN to ascii value
		{
			con[i] = int (alphanumeric[i]);
		    PN[i]= con[i];
		}
		cout<<endl;
		cout<<"ASCII value of alpha-numeric ";
		for (int j = 0; j < strlen(alphanumeric); j++)
		{
			cout<<PN[j]<<" ";
		}
		cout<<endl;

        //*****************************************************
		//merging
		int k=-1,panl=0;
		for(int i=0;i<strlen(email_mac);i++)
		{
			if(panl<10)
			{
				k++;
			    for(int j = panl ; j<=panl;j++)
		     	{
			    	EMP[k]= PN[j];
				}
				panl++;
			}
			k++;
			EMP[k]=email_mac[i];	
			
		}
		cout<<"After merging : \n";
		for(int i=0;i<strlen(e_m_p);i++)
		{
			cout<<EMP[i]<<" ";
		}
		//********************************************converting to binary
		int binaryNum[50];
        for(int i=0;i<strlen(e_m_p);i++)
	   {
	       if(EMP[i] >= 0 || EMP[i]<= 255)
	        {
	        	int j=0;
            	while (EMP[i] > 0) 
	        	{    
	     	        // storing remainder in binary array
		            binaryNum[j] = EMP[i] % 2;
		            EMP[i] = EMP[i] / 2;
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
		                	empbinary[emp_len] = 0;
		                    emp_len++;
		                    j2++;
	                	}
    	            }
	                empbinary[emp_len]=binaryNum[k];
		            emp_len++;
            	}
            }
        }
        cout<<endl;
   }
   for(int i = 0;i<emp_len;i++)
    {
	     cout<<empbinary[i];
    }
    cout<<endl;
    cout<<"total bit of binary :"<<emp_len<<endl;
	if(emp_len>=256)
	{
		for(int i=0;i<256;i++)
		{
			emprask[i]=empbinary[i];
		}
	}
	else
	{
		for(int i=0;i<emp_len;i++)
		{
			emprask[i]=empbinary[i];
		}
		for(int i=emp_len;i<256;i++)
		{
			emprask[i]=0;
		}
	}
	cout<<"After converting binary to 256 bit :"<<endl;
	for(int i=0;i<256;i++)
	{
		cout<<emprask[i];
	}
	return 0;
}
