#include <bits/stdc++.h>
using namespace std;

//O(nlogn) Time

//Merges two sorted array
void mergesort(int input[],int start1,int end1,int start2,int end2){
    int counter1=start1,counter2=start2,counter_ans=0;
    int ans[end2-start1+1];
    while(counter1<=end1 and counter2<=end2){
        if(input[counter2]<input[counter1]){
            ans[counter_ans++]=input[counter2++];
        }
        else{
            ans[counter_ans++]=input[counter1++];
        }
    }

    while(counter1<=end1){ans[counter_ans++]=input[counter1++];}
    while(counter2<=end2){ans[counter_ans++]=input[counter2++];}
    counter_ans=0;
    for(int i=start1;i<=end2;i++){
        input[i]=ans[counter_ans++];
    }
    return ;
}

//Dividing array into two sorted halves
void merge(int input[],int start,int end){
    if(start==end){return ; }
    int start1,start2,end1,end2;
    start1=start;end1=(end+start)/2;
    start2=end1+1;end2=end;

    merge(input,start1,end1);
    merge(input,start2,end2);


    mergesort(input,start1,end1,start2,end2);


}


int main(){

    int input[]={0,2,3,1};
    int size=sizeof(input)/sizeof(int);
    merge(input,0,size-1);
    for(int i=0;i<size;i++){
        cout<<input[i]<<" ";
    }
    return 0;
    
}
