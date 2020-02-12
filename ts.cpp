/*
Title: ts.cpp
Abstract: Your program should read an input file name. 
Then it should display the topological ordering. 
In the problem, you can assume that the number of vertices in the input file is less than 50. 
Additionally, you can assume that the input graph is always a DAG (= Directed Acyclic Graph). 
Author: Mark Mariscal
ID: 7198
Date: 02/08/2020
*/

#include<iostream>
#include <fstream>
using namespace std;
int main()

{
    int count = 0;
    string fileName;
    int beginning;
    cout << "Enter input file name: "; //asks input
    cin >> fileName;
    ifstream infile(fileName);
    int N;
    infile >> N; 

    int adjacency[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            infile >> adjacency[i][j];
    }
    infile.close();
  
    int vertices[N];
    int flag[N];

    for(int i=0;i<N;i++){
        vertices[i]=0;
        flag[i]=0;
    }


    
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N; j++)
            vertices[i]=vertices[i]+adjacency[j][i];

    cout << "\nThe topological order is " << endl;
    int arrows = 0;
    while(count< N){
        for(int k = 0; k < N;k++){
            if((vertices[k]==0) && (flag[k]==0)){
                 cout<< k <<" ";
                flag [k]=1;
                if(arrows < (N-1)){
                    cout << "-->";
                    arrows++;
                }

            }
 
            for(int s = 0; s < N;s++){
                if(adjacency[s][k]==1)
                    vertices[k]--;
            }
        }
 
        count++;
    }
    cout << endl;
 
    return 0;
}
