/* Pablo Ibañez Freire, pablo.ibannez@uam.es

A simple class to manage data pairs.

Constraints:

-Data types have to be different
-All entries of the same type must be different

USAGE:

dictionary<int,std::string> dict; //int-string pairs

dict.addEntry(1,"test");

std::cout << dict(1) << std::endl; // It will print "test"
std::cout << dict("test") << std::endl; // It will print "1"

*/

#ifndef __DICTIONARY__
#define __DICTIONARY__

#include <type_traits>
#include <iostream>

#include <algorithm>

template<typename leftEntryType, typename rightEntryType>
class dictionary{
    
    static_assert ( !std::is_same<leftEntryType, rightEntryType>::value, 
    "The types of dictionary entries cannot be equal.");
    
    private:
    
	std::vector<leftEntryType> leftEntryVector;
	std::vector<rightEntryType> rightEntryVector;
    
    public:
    
	void addEntry(leftEntryType lE, rightEntryType rE){
	    
	    if(std::find(leftEntryVector.begin(), leftEntryVector.end(), lE) != leftEntryVector.end()) {
		std::cerr << "ERROR (class dictionary). The entry \"" << lE << "\" has been added before." << std::endl;
		exit(0);
	    }
	    if(std::find(rightEntryVector.begin(), rightEntryVector.end(), rE) != rightEntryVector.end()) {
		std::cerr << "ERROR (class dictionary). The entry \"" << rE << "\" has been added before." << std::endl;
		exit(0);
	    }
	    
	    leftEntryVector.push_back(lE);
	    rightEntryVector.push_back(rE);
	}
	
	const leftEntryType& operator()(rightEntryType rE){
	    
	    auto iterPos = std::find(rightEntryVector.begin(), rightEntryVector.end(), rE);
	    
	    if(iterPos == rightEntryVector.end()){
		std::cerr << "ERROR (class dictionary). The entry \"" << rE << "\" has not been added." << std::endl;
		exit(0);
	    }
	    
	    return leftEntryVector[std::distance(rightEntryVector.begin(),iterPos)];	    
	}
	
	const rightEntryType& operator()(leftEntryType lE){
	    
	    auto iterPos = std::find(leftEntryVector.begin(), leftEntryVector.end(), lE);
	    
	    if(iterPos == leftEntryVector.end()){
		std::cerr << "ERROR (class dictionary). The entry \"" << lE << "\" has not been added." << std::endl;
		exit(0);
	    }
	    
	    return rightEntryVector[std::distance(leftEntryVector.begin(),iterPos)];	    
	}
};

#endif
