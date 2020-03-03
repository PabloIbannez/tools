#ifndef __CONE__
#define __CONE__

#include "common.h"
#include "../primes/prime.h"

class cone{

    real height;
    real angle;
    real dz;

    std::vector<real3> vertices;
    
    std::shared_ptr<prime> prm;

    public:
        cone(real height,real angle,real dz):height(height),angle(angle),dz(dz){
            
            prm = std::make_shared<prime>();

            //angle to radians
            angle *= 0.01745329252;

            real3 position={0,0,0};
            real  offset;
            
            for(int i=0;true;i++){ 
            
                if(position.z  > height){break;}
                
                real R = position.z*std::tan(angle);

                int coneCircvertices = int(2.0*M_PI*R/dz) + 1;
                if(coneCircvertices != 1) {coneCircvertices = prm->nearestPreviousPrimeNumber(coneCircvertices);}
                
                for(int j=0;j<coneCircvertices;j++){
                    position.x = R*std::cos((2.0*M_PI/coneCircvertices)*j+offset);
                    position.y = R*std::sin((2.0*M_PI/coneCircvertices)*j+offset);
                    
                    vertices.push_back(position);
                }
                
                if(i%2==0){
                    offset = 0;
                } else {
                    offset = (2.0*M_PI/coneCircvertices)/2.0;
                }
                
                position.z += dz;
            }

        }

        std::vector<real3> getVertices(){
            return vertices;
        }

        void print(){
            for(auto& p : vertices){
                std::cout << p.x << " " <<
                             p.y << " " <<
                             p.z << std::endl;
            }
        }
};

#endif
