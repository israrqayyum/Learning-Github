#include<iostream>
 using namespace std;
 int main(){
    int row,col;
    cout<<"Enter number of rows:";
    cin>>row;
    cout<<"Enter number of columns:";
    cin>>col;
    int matrixArray[row][col];
    cout<<"Enter Matrix of "<<row<<" * "<<col<<":"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrixArray[i][j];
        }
    }
    cout<<"Array before Transpose:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrixArray[i][j]<<"\t";
        }
        cout<<endl;
    }
    int temp[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp[j][i]=matrixArray[i][j];
        }
    }
    //-----
    cout<<"Array After Transpose:"<<endl;
    for (int i=0;i<col;i++) {  
        // Iterate over the columns
        for (int j=0;j<row;j++){  
            // Iterate over the rows
            cout<<temp[i][j]<<"\t";
        }
        cout<<endl;
    }
 return 0;
}