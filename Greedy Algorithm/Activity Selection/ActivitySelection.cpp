
// Md Amanullah
// H
// 2016852
// 70




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> start ={1,3,0,5,8,5};
    vector <int> end ={2,4,6,7,9,9};
    
    int maxAct =0;
    vector<int> ans;
    
    maxAct =1;
    ans.push_back(0);
 
    int lastEnd= end[0];
    
    for(int i=0 ;i<end.size();i++){
        if(start[i]>=lastEnd){
            
            maxAct++;
            ans.push_back(i);
            lastEnd=end[i];
        }
    }
    
    std::cout << maxAct<<" " << std::endl;
    
    

    return 0;
}
