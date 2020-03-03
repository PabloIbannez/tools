#ifndef __ICOSPHERE__
#define __ICOSPHERE__

#include "common.h"

class icosphere{
    
    real radius;

    const real H_ANGLE = M_PI/180*72;
    const real V_ANGLE = atan(1.0f/2);

    std::vector<real3> vertices;
    std::vector<int3>  triangles;

    real3 computeHalfVertex(real3& V1,real3& V2){
        real3 newV;

        newV = {(V1.x+V2.x)/2,(V1.y+V2.y)/2,(V1.z+V2.z)/2};
        real scale = radius/sqrt(newV.x*newV.x+newV.y*newV.y+newV.z*newV.z);
        newV = {newV.x*scale,newV.y*scale,newV.z*scale};

        return newV;

    }
    
    public:
        
        icosphere(real radius):radius(radius){
        
            vertices.resize(12,{0,0,0});

            real z, xy;
            real hAngle1 = -M_PI/2-H_ANGLE/2;
            real hAngle2 = -M_PI/2;

            //top vertex
            vertices[0]={0,0,radius};
            
            //compute 10 vertices at 1st and 2nd rows
            for(int i=1; i<=5; i++){

                z  = radius*sin(V_ANGLE);
                xy = radius*cos(V_ANGLE);
                
                //first row
                vertices[i]  ={xy*cos(hAngle1),xy*sin(hAngle1), z};
                //second row
                vertices[i+5]={xy*cos(hAngle2),xy*sin(hAngle2),-z};

                //next horizontal angles
                hAngle1 += H_ANGLE;
                hAngle2 += H_ANGLE;
            }

            //bottom vertex
            vertices[11]={0,0,-radius};

            //populate triangles vector
            triangles.push_back({0,1,2});
            triangles.push_back({0,2,3});
            triangles.push_back({0,3,4});
            triangles.push_back({0,4,5});
            triangles.push_back({0,5,1});

            triangles.push_back({1,6,2});
            triangles.push_back({2,7,3});
            triangles.push_back({3,8,4});
            triangles.push_back({4,9,5});
            triangles.push_back({5,10,1});
            
            triangles.push_back({2,6,7});
            triangles.push_back({3,7,8});
            triangles.push_back({4,8,9});
            triangles.push_back({5,9,10});
            triangles.push_back({1,10,6});

            triangles.push_back({6,11,7});
            triangles.push_back({7,11,8});
            triangles.push_back({8,11,9});
            triangles.push_back({9,11,10});
            triangles.push_back({10,11,6});
        }

        void subdivide(unsigned int subdivision){
            std::vector<real3> tmpVertices;
            std::vector<int3> tmpTriangles;
            
            real3 V1,V2,V3;
            real3 newV1,newV2,newV3;
            int trianglesOffSet;

            for(unsigned int s=0;s<subdivision;s++){

                tmpVertices=vertices;
                tmpTriangles=triangles;

                vertices.clear();
                triangles.clear();
                
                trianglesOffSet=0;

                for(auto& t : tmpTriangles){

                    V1 = tmpVertices[t.i];
                    V2 = tmpVertices[t.j];
                    V3 = tmpVertices[t.k];

                    newV1 = this->computeHalfVertex(V1,V2);
                    newV2 = this->computeHalfVertex(V2,V3);
                    newV3 = this->computeHalfVertex(V3,V1);

                    vertices.push_back(V1);    //0
                    vertices.push_back(newV1); //1
                    vertices.push_back(newV3); //2
                    vertices.push_back(V2);    //3
                    vertices.push_back(newV2); //4
                    vertices.push_back(V3);    //5
                    
                    triangles.push_back({0 + trianglesOffSet,
                                         1 + trianglesOffSet,
                                         2 + trianglesOffSet});
                    triangles.push_back({1 + trianglesOffSet,
                                         3 + trianglesOffSet,
                                         4 + trianglesOffSet});
                    triangles.push_back({1 + trianglesOffSet,
                                         4 + trianglesOffSet,
                                         2 + trianglesOffSet});
                    triangles.push_back({2 + trianglesOffSet,
                                         4 + trianglesOffSet,
                                         5 + trianglesOffSet});

                    trianglesOffSet += 6;
                }
            }
        }
        
        std::vector<real3> getVertices(){

            std::vector<real3> tmpVertices=vertices;
            
            std::sort(tmpVertices.begin(),tmpVertices.end());
            tmpVertices.erase(std::unique(tmpVertices.begin(),tmpVertices.end()),tmpVertices.end());
            
            return tmpVertices;
        }

        void print(){

            std::vector<real3> tmpVertices=this->getVertices();

            for(auto& v : tmpVertices){
                std::cout << v.x << " " <<
                             v.y << " " <<
                             v.z << std::endl;
            }
        }
};

#endif
