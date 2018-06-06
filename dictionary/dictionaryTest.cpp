#include "dictionary.cuh"

#include <iostream>
#include <string>

int main(){
    
    dictionary<int,std::string> dict;
    
    dict.addEntry(1,"one");
    dict.addEntry(2,"two");
    dict.addEntry(3,"three");
    
    //dict.addEntry(3,"three"); // Error detected->OK
    //dict.addEntry(4,"three"); // Error detected->OK
    //dict.addEntry(3,"four");  // Error detected->OK
    
    std::cout << dict(1)<< std::endl;
    std::cout << dict(2)<< std::endl;
    std::cout << dict(3)<< std::endl;
    //std::cout << dict(4)<< std::endl; // Error detected->OK
    
    std::cout << dict("one")<< std::endl;
    std::cout << dict("two") << std::endl;
    std::cout << dict("three") << std::endl;
    //std::cout << dict("four")<< std::endl; // Error detected->OK
    
    //dictionary<int,int> dictSame; // Error detected->OK
    
    return 0;
}
