#include "icosphere.h"
#include "cone.h"

#include <fstream>

int main(int argc,char *argv[]){

    auto sphere = icosphere(5.0);
    sphere.subdivide(4);
    auto sphereV = sphere.getVertices();
    
    auto cn = cone(30,25,1);
    auto coneV = cn.getVertices();

    auto sphereFile = std::ofstream("sphere.sp");

    for(auto v : sphereV){
        sphereFile << v.x << " " << v.y << " " << v.z << std::endl;
    }

    sphereFile.close();

    auto coneFile = std::ofstream("cone.sp");

    for(auto v : coneV){
        coneFile << v.x << " " << v.y << " " << v.z << std::endl;
    }
    
    coneFile.close();
    
    return EXIT_SUCCESS;
}
