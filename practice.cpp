#include<stdio.h>
#include<iostream>
#include<bitset>
#include<string>

using namespace std;


string xorfun(string encoded, string crc)
{
    for(int i=0;i<=(encoded.length()-crc.length());)
    {
        for(int j=0;j<crc.length();j++)
        {
            encoded[i+j] = encoded[i+j] == crc[j] ? '0':'1';
        }
        for(;i<encoded.length() && encoded[i]!='1';i++);
    }
    return encoded;
}

int main()
{
    string data;
    string crc;
    cout<<"Enter data to be transmitted:";
    cin>>data;
    cout<<endl;

    cout<<"Enter the crc polynomial";
    cin>>crc;
    cout<<endl;

    string encoded= "";
    encoded += data;
    for(int i=1;i<crc.length();i++)
    {
        encoded += '0';
    }

    encoded = xorfun(encoded, crc);
    string checksum = encoded.substr(encoded.length() - crc.length() + 1);

    // Display results
    cout << "Checksum generated is: " << checksum << endl;
    cout << "Message to be transmitted over the network: " 
         << data + checksum << endl;

    string trasmit;
    cout<<"Enter data to be transmistted:";
    cin>>trasmit;

    string newE = "";
    newE = xorfun(trasmit,crc);
    cout<<endl<<"Received:"<<newE;

}