#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* strand sort is implemnted in stl::list because it recquires frequent operations in the middle of the list 
which would otherwise be expensive if an array is used*/
void strandSort(list<int> &ip, list<int> &op)
{
    
    if (ip.empty())
        return;
  
    list<int> sublist;
    sublist.push_back(ip.front());
    ip.pop_front();
    
    for (list<int>::iterator it = ip.begin(); it != ip.end(); ) {

      /* this section of code implements the ascending direction of sorting 
      the list*/ 
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

int main(void)
{
    list<int> ip;
ip.push_back(10);
ip.push_back(5);
ip.push_back(30);
ip.push_back(40);
ip.push_back(2);
ip.push_back(4);
ip.push_back(9);

   
    list<int> op;

    
    strandSort(ip, op);
for (list<int>::iterator it = op.begin(); it != op.end(); ++it) {
    int x = *it;
    cout << x << " ";
}
    return 0;
}

