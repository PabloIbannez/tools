#include "encoding.hpp"

#include <iostream>

#include <cinttypes>
#include <bitset>

int main(){
    
    const int st_l = 6;
    const int nd_l = 12;
    const int rd_l = 14;
    
    encoding3_32<st_l,nd_l,rd_l> test;
    
    std::cout << std::endl;
    
    std::printf("Base  : %" PRIu32 ", %#" PRIx32  "\n", test.get_base(), test.get_base());
    std::cout << "Size: " << sizeof(encoding3_32<6,12,14>) << " " << sizeof(uint32_t) << std::endl;
    
    std::cout << std::endl;
    
    std::bitset<32> mask_st_6 =((1<<st_l)-1)<<(nd_l+rd_l);
    std::bitset<32> mask_nd_12=((1<<nd_l)-1)<<(rd_l);
    std::bitset<32> mask_rd_14=((1<<rd_l)-1);
    
    std::printf("Mask First : %s \n",mask_st_6 .to_string().c_str());
    std::printf("Mask Second: %s \n",mask_nd_12.to_string().c_str());
    std::printf("Mask Three : %s \n",mask_rd_14.to_string().c_str());
    
    std::cout << std::endl;
    
    test.set_st(12);
    test.set_nd(1234);
    test.set_rd(4321);
    
    std::bitset<32> base(test.get_base());
    std::bitset<32> st(test.get_st());
    std::bitset<32> nd(test.get_nd());
    std::bitset<32> rd(test.get_rd());
    
    std::printf("Base  : %" PRIu32 ", %#" PRIx32  "\n", test.get_base(), test.get_base());
    std::printf("First : %" PRIu32 ", %#" PRIx32  "\n", test.get_st(), test.get_st());
    std::printf("Second: %" PRIu32 ", %#" PRIx32  "\n", test.get_nd(), test.get_nd());
    std::printf("Three : %" PRIu32 ", %#" PRIx32  "\n", test.get_rd(), test.get_rd());
    
    std::cout << std::endl;
    
    std::printf("Base  : %s \n",base.to_string().c_str());
    std::printf("First : %s \n",st.to_string().c_str());
    std::printf("Second: %s \n",nd.to_string().c_str());
    std::printf("Three : %s \n",rd.to_string().c_str());
    
    std::cout << std::endl;
    
    std::cout << "Testing ..." << std::endl;
    
    for(uint32_t i=0;i<((1<<st_l)-1);i++){
	test.set_st(i);
	for(uint32_t j=0;j<((1<<nd_l)-1);j++){
	    test.set_nd(j);
	    for(uint32_t k=0;k<((1<<rd_l)-1);k++){
		test.set_rd(k);
		
		if(test.get_st() != i) std::cout << "ERROR: st = " << test.get_st() << ", i = " << i << std::endl;
		if(test.get_nd() != j) std::cout << "ERROR: nd = " << test.get_nd() << ", j = " << j << std::endl;
		if(test.get_rd() != k) std::cout << "ERROR: rd = " << test.get_rd() << ", k = " << k << std::endl;
		
	    }
	}
    }
    
    std::cout << "All correct!!!" << std::endl;
    
    return 0;
}
