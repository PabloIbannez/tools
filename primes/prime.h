#ifndef __PRIME__
#define __PRIME__

#include <vector>

class prime{

    int max = 1e4;
    std::vector<int> primeList;

    void updatePrimeList(){
        
        bool isPrime;
        int i0; 
        
        if(primeList.empty()){
            i0 = 2;
        } else {
            i0 = primeList.back()+1;
        }

        for(int i=i0;i<=max;i++){
            isPrime = true;
            for(int p : primeList){
                if(i%p==0){ isPrime = false; break;} 
            }
            if(isPrime){
                primeList.push_back(i);
            }
        }

    }
    public:
        
        prime(){
            this->updatePrimeList();
        }

        prime(int max):max(max){
            prime();
        }

        void print(){
            for(int p : primeList){
                std::cout << p << std::endl;
            }
        }
        
        bool isPrime(int inputNumber){
            if(inputNumber > max){ max=inputNumber; this->updatePrimeList();}

            for(int i=0;i<primeList.size() and primeList[i] <= inputNumber;i++){
                if(primeList[i]==inputNumber) {return true;}
            }

            return false;
        }

        int nearestPreviousPrimeNumber(int inputNumber){
            if(inputNumber > max){ max=inputNumber; this->updatePrimeList();}

            for(int i=0;i<primeList.size();i++){
                if(primeList[i]>inputNumber) {return primeList[i-1];}
            }

            return primeList.back();
        }

        std::vector<int> numberFactors(int inputNumber){
            if(inputNumber > max){ max=inputNumber; this->updatePrimeList();}
            
            std::vector<int> factors;

            if(this->isPrime(inputNumber)){
                factors.push_back(inputNumber);
            } else {
                for(int i=0;i<primeList.size();i++){
                    int p = primeList[i];
                    if(inputNumber % p == 0){
                        factors.push_back(p);
                        inputNumber=inputNumber/p;
                        i=-1;
                        if(inputNumber == 1){break;}
                    }
                }
            }

            return factors;
                
        }
};

#endif
