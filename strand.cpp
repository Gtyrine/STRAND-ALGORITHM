#include <iostream>
#include <bits/stdc++.h>
using namespace std;
oid strandSort(list<int> &ip, list<int> &op)
{
    
    if (ip.empty())
        return;
  
    list<int> sublist;
    sublist.push_back(ip.front());
    ip.pop_front();
    
    for (list<int>::iterator it = ip.begin(); it != ip.end(); ) {

       
        if (*it > sublist.back()) {
            sublist.push_back(*it);   
            it = ip.erase(it);
        }  
        else{
            it++;
        }
    } 
  op.merge(sublist);
    
    strandSort(ip, op);
}

