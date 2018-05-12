/* Pablo Ibañez Freire, pablo.ibannez@uam.es

Tools for encoding variables of different types into larger ones.
An interface is also provided to quickly access them, 
both for setting their value and for reading it.

USAGE:

encoding3<uint32_t,6,12,14> x; //Three unsigned integers of size 6,12 and 14 bits 
                               //are encoded in an unsigned integer of size 32 bits. 

x.set_st(10)   // The firST value is set to 10
x.set_nd(125)  // The secoND value is set to 125
x.set_rd(2435) // The thiRD value is set to 2435

printf("%u %u %u\n",x.get_st,x.get_nd,x.get_rd); // The different values are printed
*/

#ifndef __ENCODING__
#define __ENCODING__

#include <cstdint>

#ifdef __CUDACC__
#define INLINE inline __host__ __device__
#else
#include <cstdio>  //printf
#define INLINE inline
#endif

template<typename baseType, uint8_t st_l,uint8_t nd_l,uint8_t rd_l>
class encoding3{
    
    static_assert ( (st_l+nd_l+rd_l) == sizeof(baseType)*8, 
    "The sum of the size of the three encoded types has to match the size of the variable where they are encoded.");
    
    private:
    
	baseType base;
	
	//Masks for each value
	static const baseType mask_st=baseType((baseType(1)<<st_l)-1)<<(nd_l+rd_l);
	static const baseType mask_nd=baseType((baseType(1)<<nd_l)-1)<<(rd_l);
	static const baseType mask_rd=baseType((baseType(1)<<rd_l)-1);
	
	static const baseType mask_st_nd=baseType((baseType(1)<<(st_l+nd_l))-1)<<(rd_l);
    
    public:
    
	INLINE encoding3(baseType base):base(base){}
	INLINE encoding3(){encoding3(0);}
	
	INLINE baseType get_base(){return base;}
	
	INLINE void set_st(baseType st){
	    if( st > baseType((1<<st_l)-1)){
		std::printf("ERROR: The maximum size of the first encoded variable is: %u",(1<<st_l)-1);
	    } else {
		base = (base & ~mask_st) | ((st<<(nd_l+rd_l)) & mask_st);
	    }
	}
	
	INLINE void set_nd(baseType nd){
	    if( nd > baseType((1<<nd_l)-1)){
		std::printf("ERROR: The maximum size of the second encoded variable is: %u",(1<<nd_l)-1);
	    } else {
		base = (base & ~mask_nd) | ((nd<<rd_l) & mask_nd);
	    }
	}
	
	INLINE void set_rd(baseType rd){
	    if( rd > baseType((1<<rd_l)-1)){
		std::printf("ERROR: The maximum size of the third encoded variable is: %u",(1<<rd_l)-1);
	    } else {
		base = (base & ~mask_rd) | (rd & mask_rd);
	    }
	}
	
	INLINE baseType get_base() const {return base;}
	INLINE baseType get_st() const {return base >> (nd_l+rd_l);}
	INLINE baseType get_nd() const {return (base & mask_nd) >> rd_l;}
	INLINE baseType get_rd() const {return (base & mask_rd);}
	
	INLINE bool comp_st_nd(const encoding3<baseType,st_l,nd_l,rd_l> &j) const {return (base & mask_st_nd) == (j.get_base() & mask_st_nd);}
};


template<uint8_t st_l,uint8_t nd_l,uint8_t rd_l>
using encoding3_32 = encoding3<uint32_t,st_l,nd_l,rd_l>;

template<uint8_t st_l,uint8_t nd_l,uint8_t rd_l>
using encoding3_64 = encoding3<uint64_t,st_l,nd_l,rd_l>;

#undef INLINE

#endif
