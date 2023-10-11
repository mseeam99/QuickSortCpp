#include <vector>
#include <iostream>
using namespace std;

int partition(std::vector<int>& array, int start, int end) {
    int pivot = array[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (array[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    std::swap(array[pivotIndex], array[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex){
        while(array[i] <= pivot) {
            i++;
        }
        while(array[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            std::swap(array[i++], array[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(std::vector<int>& array, int start, int end) {
    if (start >= end)
        return;
    int p = partition(array, start, end);
    quickSort(array, start, p - 1);
    quickSort(array, p + 1, end);
}

int main(){
    cout<<"Program Starts ....."<<endl;
    vector <int> elements;
    // populating the vector with random integer
    for(int i=0;i<15;i++){
        int randomValue = rand() % 50 + 1; //range 1 to 50
        elements.push_back(randomValue);
    }
    cout<<"Before using Quick Sort: "<<endl;
    for(int i=0;i<elements.size()-1;i++){
        cout<<elements.at(i)<<" ";
    }
    cout<<endl;
    quickSort(elements,0,elements.size()-1);
    cout<<"After using Quick Sort: "<<endl;
    for(int i=0;i<elements.size()-1;i++){
        cout<<elements.at(i)<<" ";
    }
    cout<<endl;
    cout<<"Program Ends ....."<<endl;
}