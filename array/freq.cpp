#include <iostream>
#include <vector>
using namespace std;

int left_occurence(vector<int> &array,int x,int low,int high){
    int result = -1;
    while(low <= high){
        int mid = low+(high-low)/2;
        if(array[mid] == x){
            result = mid;
            high = mid-1;
        }else if(array[mid] < x){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return result;
}

int right_occurence(vector<int> &array,int x,int low,int high){
    int result = -1;
    while(low <= high){
        int mid = low+(high-low)/2;
        if(array[mid] == x){
            result = mid;
            low = mid+1;
        }else if(array[mid] < x){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return result;
}

int count_occurence(vector<int> &array,int x){
    int left = left_occurence(array,x,0,array.size()-1);
    int right = right_occurence(array,x,0,array.size()-1);

    if(left == -1){
        return 0;
    }
    int count = right-left+1;
    return count;
}

int main(){
    vector<int> array = {1,2,2,3,3,3,4,5,5};
    int x = 3;
    int occurence = count_occurence(array,x);
    cout<<x<<": "<<occurence<<endl;
    return 0;
}

