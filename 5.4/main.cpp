#include "pin_out_invert.hpp"

int main(void){
	auto p1 = hwlib::target::pin_out( 3, 1 );
	auto p2 = hwlib::target::pin_out( 3, 3 );
	auto p3 = hwlib::target::pin_out( 3, 9 );
	auto p4 = hwlib::target::pin_out( 3, 10 );
	auto p5 = hwlib::target::pin_out(2,2);
	auto p6 = hwlib::target::pin_out(2,4);
	auto p7 = hwlib::target::pin_out(2,6);
	auto p8 = hwlib::target::pin_out(2,8);

	pin_out_invert pout1(p1, p2, p3, p4, p5, p6, p7, p8);
	
	while(1){
		pout1.write(1);
		pout1.flush();
		
		hwlib::wait_ms(500);
		
		pout1.write(0);
		pout1.flush();
		
		hwlib::wait_ms(500);
	}
}
