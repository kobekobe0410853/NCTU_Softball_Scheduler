#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define n 6
#define each 2

int** generate_array()
{
    int **a = new int* [n];
    for(int i = 0 ; i<n ; i++)
    {
        a[i] = new int [n];
        for(int j = 0 ; j< n ; j++)
            a[i][j] = 0;
    }
    return a ;
}
void rand_pick(int **a)
{
    int jump = 0 ;
    int temp[3] ;
    do
    {
        temp[0] = rand()%(n-2);
        temp[1] = rand()%(n-2-temp[0]) + (temp[0]+1) ;
        temp[2] = rand()%(n-1-temp[1]) + (temp[1]+1) ;
        jump++;
        if (jump==100)
            return;
    }
    while(a[temp[0]][temp[1]]==each||a[temp[0]][temp[2]]==each||a[temp[1]][temp[2]]==each);
    a[temp[0]][temp[1]] ++ ;
    a[temp[0]][temp[2]] ++ ;
    a[temp[1]][temp[2]] ++ ;
    cout << temp[0] << " " << temp[1] << " " << temp[2] << endl ;

    
}

int main()
{
    srand(time(NULL));
    int **a = generate_array();
    for(int i=0 ;i<n*(n-1)/2 ;i++)
        rand_pick(a);
    for(int i=0 ; i<n ; i++)
    {
        for(int j= 0 ; j<n ; j++)
            cout << a[i][j] <<" ";
        cout << endl ;
    }
    return 0 ;
    
    
    
    
    
}
