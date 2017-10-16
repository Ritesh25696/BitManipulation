There are N persons and N tasks, each task is to be alloted to a single person. We are also given a matrix costcost of size N×N, 
where cost[i][j] denotes, how much person i is going to charge for task j. Now we need to assign each task to a person in such a way 
that the total cost is minimum. Note that each task is to be alloted to a single person, and each person will be alloted only one task.

***************************************************************************************************


#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int setbitcount(int n){
int c = 0;
while(n){
    if(n & 1)c++;
    n>>=1;
}
return c;
}

void mincost(vector<vector<int>>cost , int n){
    cout<<"here"<<endl;
vector<int> dp(pow(2,n), INT_MAX);
dp[0] = 0;
for(int m = 0 ; m<pow(2,n) ; m++){
    int x = setbitcount(m);
    for(int j=0 ; j<n ; j++){
        if(!(m & 1<<j)){
                cout<<"m is "<<m<<" j is "<<j<<endl;
            dp[m|1<<j] = min(dp[m|1<<j], dp[m] + cost[x][j]);
        }
    }
    for(int i=0 ; i<pow(2,n) ; i++)cout<<dp[i]<<" ";
    cout<<endl;
}
cout<<dp[pow(2,n)-1]<<endl;
}

int main(){
    int n=3;
    vector<vector<int>> cost = {
    {5,7,3},
    {2,9,7},
    {4,6,4}
    };
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    mincost(cost, n);
return 0;}
