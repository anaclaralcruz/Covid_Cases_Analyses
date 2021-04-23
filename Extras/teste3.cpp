// CPP code for resize (size_type num)
  
#include <iostream>
#include <string>
using namespace std;
   
// Function to demonstrate insert
void resizeDemo(string str)
{
   
    // Resizes str to a string with
    // 5 initial characters only 
    str.resize(5);
    cout << "Using resize : ";
    cout << str;
}
  
// Driver code
int main()
{
    string str("GeeksforGeeks ");
   
    cout << "Original String : " << str << endl;
    resizeDemo(str);
   
    return 0;
}