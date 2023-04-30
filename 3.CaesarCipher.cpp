#include<bits/stdc++.h>
using namespace std;
char str[100],str1[100];
void encrypt(int key)
{
    for(int i=0;i<strlen(str);i++)
    {
        if((int)str[i]+key>122)
        {
            str[i] = (char)((int)str[i]+key-26);
            continue;
        }
        else
            {str[i]=(char)((int)str[i]+key);}
    }
    cout<<"Encrypted String is : "<<endl;puts(str);
}
void decrypt(int key)
{
    for(int i=0;i<strlen(str);i++)
    {
        if((int)str[i]-key<97)	str1[i] = (char)((int)str[i]-key+26);
        else	str1[i]=(char)((int)str[i]-key);
    }
    cout<<"Key is : "<<key <<"\nDecrypted String is : ";puts(str1);
}
int main()
{
    int key;
    cout<<"Enter String : "<<endl;
    gets(str);
    cout<<"Enter Key : "<<endl;
    cin >> key;
    encrypt(key);
    decrypt(key);
    cout<<"Attack starts : "<<endl;
    for(int i=0;i<26;i++)
        {
            decrypt(i);
        }
        cout<<endl<<"Made by: AADITYA KEDIYAL "<<endl;
        return 0;
}
