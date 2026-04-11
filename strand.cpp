#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* strand sort is implemnted in stl::list because it recquires frequent operations in the middle of the list 
which would otherwise be expensive if an array is used. the list is imlemented as a doubly linked list.*/
void strandSort(list<int> &ip, list<int> &op)
{
    /*we use recursion to implement strand as it is a recursive algorithm. this line of code is the base case.*/
    if (ip.empty())
        return;
      /*we are using class templates here.*/
     //here we are assigning the first element to be added  to be the first item of the sublist.
    list<int> sublist;
    sublist.push_back(ip.front());
    ip.pop_front();
    // we use this for loop to traverse the rest of the items in the list.
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
    
    strandSort(ip, op);//recursive case
}

int main(void)
{
    /*adding element to the list*/
    list<int> ip;
ip.push_back(21);
ip.push_back(43);
ip.push_back(27);
ip.push_back(14);
ip.push_back(0);
ip.push_back(5);
ip.push_back(70);
#include <iostream>
using namespace std;

void f(int n) {
    
    cout << "F(" << n << ")'s Stack Frame Pushed\n";
    if (n > 1) {
        f(n - 1);
        f(n - 1);
    }
    cout << "F(" << n << ")'s Stack Frame Removed\n";
}

int main() {
    f(3);
    return 0;
}
    list<int> op;
    
    strandSort(ip, op);//sorting the list 
    
for (list<int>::iterator it = op.begin(); it != op.end(); ++it) {
    int x = *it;
    cout << x << " ";//printing the sorted list
    
}
    return 0;
}

