#include <bits/stdc++.h>

using namespace std;
    string s ={}, s1={};
    int key;
void encryption(){

    cout<<endl<<"--------encryption---------"<<endl;

    int len;
    
    cout<<"Enter Text :- ";
    getline (cin,s);
    len=s.length();
    
    cout<<"Enter Key :- ";
    cin>>key;
    
    char ans[key][len]={};
    
    for(int i = 0; i < key; ++i)
        {for(int j = 0; j < len; ++j)
            {ans[i][j] = '\n';}}
    
    int j=-1,row=0;
    
    for(int i=0;i<len;i++)
    {
        if(row==0 || row==key-1){
            j=j*(-1);
        }
        ans[row][i] = s[i];
        row=row+j;
    }

    for(int i=0;i<key;i++)
    {
        for (int j = 0; j < len; j++) {
            if(ans[i][j]!='\n'){
                // cout<<ans[i][j];
                s1+=ans[i][j];
            }
            else{ans[i][j]='-';}
        }
    }
    
    cout<<endl;
    for(int i=0;i<key;i++)
    {
        for (int j = 0; j < len; j++) {
                cout<<ans[i][j];
        }
        cout<<endl;
    }

     cout<<endl;
     cout<<"encryption message : - ";
     cout<<s1;
}

void decryption(){

    cout<<endl<<"--------decryption---------"<<endl;

    int len,m=0;
    
    len=s1.length();
    
    char ans[key][len]={};
    
    for(int i = 0; i < key; ++i)
        {for(int j = 0; j < len; ++j)
            {ans[i][j] = '\n';}}
    
    int j=-1,row=0;
    
    for(int i=0;i<len;i++)
    {
        if(row==0 || row==key-1){
            j=j*(-1);
        }
        ans[row][i] = '*';
        row=row+j;
    }
    
    cout<<endl;
    for(int i=0;i<key;i++)
    {
        for (int j = 0; j < len; j++) {
            if(ans[i][j]=='*'){ans[i][j]=s1[m++];}
        }
    }
    
    for(int i=0;i<key;i++)
    {
        for (int j = 0; j < len; j++) {
            if(ans[i][j]=='\n'){cout<<"-";}
            else {cout<<ans[i][j];}
        }
        cout<<endl;
    }
    
    cout<<endl;
    cout<<"decryption message : - ";
    row =0, j=-1;
    for(int i = 0; i < len; i++){
 
        if(row == 0 || row == key-1)
            {j= j * (-1);}
        cout<<ans[row][i];
        row = row + j;
    }

}

int main()
{
    encryption();
    decryption();
            cout<<endl<<"Made by: AADITYA KEDIYAL "<<endl;

    return 0;
}
