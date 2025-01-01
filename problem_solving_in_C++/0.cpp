
#include <iostream> 
using namespace std;  
string repeatStringOptimized(string str, int n) {
    string result = "";  
    for (int i = 0; i < n; i++) {  
        result += str;  
    }
    return result; 
     }

int main() {
    string str;  
    int n;  
    cout << "Enter the string: ";  
    cin >> str;   
    cout << "Enter the number of repetitions: ";  
    cin >> n; 
    cout << "Repeated String: " << repeatStringOptimized(str, n) << endl;
    return 0;  
}
/*
#include <iostream>  
#include <sstream>  
using namespace std;

string repeatStringStream(string str, int n) {
    stringstream ss;  
    
    for (int i = 0; i < n; i++) {
        ss << str; 
    }
    return ss.str();  
}

int main() {
    string str;  
    int n; 
    
    cout << "Enter the string: ";  
    cin >> str; 
    
    cout << "Enter the number of repetitions: ";  
    cin >> n;  
    cout << "Repeated String: " << repeatStringStream(str, n) << endl;
    
    return 0;  
}
*/

