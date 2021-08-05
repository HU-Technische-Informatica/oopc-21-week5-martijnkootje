#include "decorator_AND.hpp"
int main( void ){
	auto p1 = hwlib::target::pin_in(2,17);
	auto p2 = hwlib::target::pin_in(2,15);
	auto led0 = hwlib::target::pin_in_out( 3, 1 );
	led0.direction_set_output();
	
	decorator_AND deo(p1, p2);
	if(deo.get() == 1){
		led0.write(1);
		led0.flush();
	}
}

         

