#include<iostream>

using namespace std;

unsigned char calculateCheckSum(const int data[], int size){
    unsigned int sum = 0;
    for(int i=0;i<size;i++)
    {
        sum += data[i];
    }

    while(sum>>8){
        sum = (sum& 0xFF) + (sum>>8);
    }

    return static_cast<unsigned char> (~sum);
}

int main(){
    const int size =8;
    int data[size];
    cout<<"Enter:"<<size<<" integers:\n";
    for(int i=0;i<size;i++){
        cin>>data[i];
    }
    unsigned char checksum = calculateCheckSum(data,size);
    cout<<"Checksum: "<< static_cast<int>(checksum) <<endl;
    return 0;
}