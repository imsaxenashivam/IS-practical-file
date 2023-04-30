#include<iostream>
#include<cmath>
using namespace std;
float encrypt[3][2], decrypt[3][2], a[3][3], b[3][3],
mes[3][2], c[3][3];
void encryption(); //encrypts the message
void decryption(); //decrypts the message
void getKeyMessage(); //gets key and message from user
void inverse(); //finds inverse of key matrix
int main()
{
 getKeyMessage();
 encryption();
 decryption();
         cout<<endl<<"Made by: AADITYA KEDIYAL "<<endl;

 return 0;
}
void encryption()
{
 int i, j, k;
 for(i = 0; i < 3; i++)
 for(j = 0; j < 2; j++)
 for(k = 0; k < 3; k++)
 encrypt[i][j] = encrypt[i][j] + a[i][k] *
 mes[k][j];
 cout << "\nEncrypted string is : ";
 for(i = 0; i < 3; i++)
 for(j = 0; j<2; j++)
 cout << (char)(fmod(encrypt[i][j], 26) + 97);
}
void decryption()
{
 int i, j, k;
 inverse();
 for(i = 0; i < 3; i++)
 for(j = 0; j < 2; j++)
 for(k = 0; k < 3; k++)
 decrypt[i][j] = decrypt[i][j] + b[i][k] *
 encrypt[k][j];
 cout << "\nDecrypted string is : ";
 for(i = 0; i < 3; i++)
 for(j = 0; j<2; j++)
 cout << (char)(fmod(decrypt[i][j], 26) + 97);
 cout << "\n";
}
void getKeyMessage()
{
 int i, j;
 char msg[6], y;
 cout << "Enter 9 letter string for key : ";
 for(i = 0; i < 3; i++)
 for(j = 0; j < 3; j++)
 {
    cin >> y;
    a[i][j] = y - 'a';
    c[i][j] = a[i][j];
 }
 cout << "\nEnter a 6 letter message: ";
 cin >> msg;
 for(i = 0; i < 3; i++)
    for(j = 0; j<2; j++)
        mes[i][j] = msg[i*2 + j] - 97;
}
void inverse()
{
 int i, j, k;
 float p, q;
 for(i = 0; i < 3; i++)
     for(j = 0; j < 3; j++)
     {
         if(i == j)
            b[i][j] = 1;
         else
            b[i][j] = 0;
     }
 for(k = 0; k < 3; k++)
 {
     for(i = 0; i < 3; i++)
 {
 p = c[i][k];
 q = c[k][k];
 for(j = 0; j < 3; j++)
 {
 if(i != k)
 {
 c[i][j] = c[i][j] * q - p * c[k][j];
 b[i][j] = b[i][j] * q - p * b[k][j];
 }
 }
 }
 }
 for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
        b[i][j] = ceil((b[i][j] / c[i][i])*10000)/10000.0;
 
 cout << "\n\nInverse Matrix is:\n";
 for(i = 0; i < 3; i++)
 {
 for(j = 0; j < 3; j++)
 cout << b[i][j] << "\t";
 cout << "\n";
 }
}
