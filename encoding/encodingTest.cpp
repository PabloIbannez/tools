#include "encoding.cuh"

#include <iostream>

#include <cinttypes>
#include <bitset>

int main(){
    
    const int st_l = 8;
    const int nd_l = 28;
    const int rd_l = 28;
    
    encoding3_64<st_l,nd_l,rd_l> test;
    encoding3_64<st_l,nd_l,rd_l> test2;
    
    std::cout << std::endl;
    
    std::printf("Base  : %" PRIu64 ", %#" PRIx64  "\n", test.get_base(), test.get_base());
    std::cout << "Size: " << sizeof(encoding3_64<8,28,28>) << " " << sizeof(uint64_t) << std::endl;
    
    std::cout << std::endl;

    std::bitset<64> mask_st_8 =uint64_t((uint64_t(1)<<st_l)-1)<<(nd_l+rd_l);
    std::bitset<64> mask_nd_28=uint64_t((uint64_t(1)<<nd_l)-1)<<(rd_l);
    std::bitset<64> mask_rd_28=uint64_t((uint64_t(1)<<rd_l)-1);
    
    std::bitset<64> mask_st_8_nd_28=uint64_t((uint64_t(1)<<(st_l+nd_l))-1)<<(rd_l);
    
    std::printf("Mask First : %s \n",mask_st_8 .to_string().c_str());
    std::printf("Mask Second: %s \n",mask_nd_28.to_string().c_str());
    std::printf("Mask Three : %s \n",mask_rd_28.to_string().c_str());
    
    std::printf("Mask st-nd : %s \n",mask_st_8_nd_28.to_string().c_str());
    
    std::cout << std::endl;
    
    test.set_st(12);
    test.set_nd(1234);
    test.set_rd(4321);
    
    std::bitset<64> base(test.get_base());
    std::bitset<64> st(test.get_st());
    std::bitset<64> nd(test.get_nd());
    std::bitset<64> rd(test.get_rd());
    
    std::printf("Base   : %" PRIu64 ", %#" PRIx64  "\n", test.get_base(), test.get_base());
    std::printf("First  : %" PRIu64 ", %#" PRIx64  "\n", test.get_st(), test.get_st());
    std::printf("Second : %" PRIu64 ", %#" PRIx64  "\n", test.get_nd(), test.get_nd());
    std::printf("Three  : %" PRIu64 ", %#" PRIx64  "\n", test.get_rd(), test.get_rd());
    
    std::cout << std::endl;
    
    std::printf("Base   : %s \n",base.to_string().c_str());
    std::printf("First  : %s \n",st.to_string().c_str());
    std::printf("Second : %s \n",nd.to_string().c_str());
    std::printf("Three  : %s \n",rd.to_string().c_str());
    
    std::cout << std::endl;
    
    test2.set_st(12);
    test2.set_nd(1234);
    test2.set_rd(458);
    
    std::bitset<64> base2(test2.get_base());
    std::bitset<64> st2(test2.get_st());
    std::bitset<64> nd2(test2.get_nd());
    std::bitset<64> rd2(test2.get_rd());
    
    std::printf("Base2  : %" PRIu64 ", %#" PRIx64  "\n", test2.get_base(), test2.get_base());
    std::printf("First2 : %" PRIu64 ", %#" PRIx64  "\n", test2.get_st(), test2.get_st());
    std::printf("Second2: %" PRIu64 ", %#" PRIx64  "\n", test2.get_nd(), test2.get_nd());
    std::printf("Three2 : %" PRIu64 ", %#" PRIx64  "\n", test2.get_rd(), test2.get_rd());
    
    std::cout << std::endl;
    
    std::printf("Base2  : %s \n",base2.to_string().c_str());
    std::printf("First2 : %s \n",st2.to_string().c_str());
    std::printf("Second2: %s \n",nd2.to_string().c_str());
    std::printf("Three2 : %s \n",rd2.to_string().c_str());
    
    std::cout << std::endl;
    
    std::cout << "Comparing ..." << std::endl;
    
    std::printf("Comparation : %i \n",test.comp_st_nd(test2));
    
    std::cout << std::endl;
    
    std::cout << "Testing ..." << std::endl;
    
    /*
    for(uint64_t i=0;i<((1<<st_l)-1);i++){
	test.set_st(i);
	for(uint64_t j=0;j<((1<<nd_l)-1);j++){
	    test.set_nd(j);
	    for(uint64_t k=0;k<((1<<rd_l)-1);k++){
		test.set_rd(k);
		
		if(test.get_st() != i) std::cout << "ERROR: st = " << test.get_st() << ", i = " << i << std::endl;
		if(test.get_nd() != j) std::cout << "ERROR: nd = " << test.get_nd() << ", j = " << j << std::endl;
		if(test.get_rd() != k) std::cout << "ERROR: rd = " << test.get_rd() << ", k = " << k << std::endl;
		
	    }
	}
    }
    */
    std::cout << "All correct!!!" << std::endl;
    
    return 0;
}
