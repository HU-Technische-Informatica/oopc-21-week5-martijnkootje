#include "hwlib.hpp"

void switches(hwlib::pin_in_out & swi1, hwlib::pin_in_out & swi2, bool &more, bool &less){
	swi1.refresh();
	swi2.refresh();
	if(swi1.read() == 1){
		more = true;
	}
	if(swi2.read() == 1){
		less = true;
	}
}

int main( void ){
	auto swi1 = hwlib::target::pin_in_out( 2, 17 );
	auto swi2 = hwlib::target::pin_in_out( 2, 15 );
	swi1.direction_set_input();
	swi2.direction_set_input();
	
	auto led0 = hwlib::target::pin_in_out( 3, 1 );
	auto led1 = hwlib::target::pin_in_out( 3, 3 );
	auto led2 = hwlib::target::pin_in_out( 3, 9 );
	auto led3 = hwlib::target::pin_in_out( 3, 10 );
	led0.direction_set_output();
	led1.direction_set_output();
	led2.direction_set_output();
	led3.direction_set_output();	
	namespace target = hwlib::target;
	
	hwlib::wait_ms(1000);
auto ds = target::pin_out(target::pin_out(3, 8));
auto shcp = target::pin_out(target::pin_out(3, 7));
auto stcp = target::pin_out(target::pin_out(2, 21));
auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
shcp, ds, hwlib::pin_in_dummy
);
auto hc595 = hwlib::hc595( spi, stcp);
	
	bool l1 = false;
	bool l2 = false;
	bool l3 = false;
	bool l4 = false;
	bool l5 = false;
	bool l6 = false;
	bool l7 = false;
	bool l8 = false;
	
	bool more = false;
	bool less = false;
	
   while(1){
	   switches(swi1, swi2, more, less);
	   
	   //meer lampjes
	   if(more == true){
		   if(l1 == true){
			   if(l2 == true){
				   if(l3 == true){
					   if(l4 == true){
						   if(l5 == true){
							   if(l6 == true){
								   if(l7 == true){
									   if(l8 == true){
									   }else{
										   l8 = true;
									   }
								   }else{
									   l7 = true;
								   }
							   }else{
								   l6 = true;
							   }
						   }else{
							   l5 = true;
						   }
					   }else{
						   l4 = true;
					   }
				   }else{
					   l3 = true;
				   }
			   }else{
				   l2 = true;
			   }
		   }else{
			   l1 = true;
		   }
		  more = false;
	   }
	   
	   //minder lampjes
	   
		if(less == true){
			if(l8 == true){
				l8 = false;
			}else{
				if(l7 == true){
					l7 = false;
				}else{
					if(l6 == true){
						l6 = false;
					}else{
						if(l5 == true){
							l5 = false;
						}else{
							if(l4 == true){
								l4 = false;
							}else{
								if(l3 == true){
									l3 = false;
								}else{
									if(l2 == true){
										l2 = false;
									}else{
										if(l1 == true){
											l1 = false;
										}
									}
								}
							}
						}
					}
				}
			}
		   less = false;
	   }  

	led0.write(l1);
	led1.write(l2);
	led2.write(l3);
	led3.write(l4);
	hc595.p1.write(l5);
	hc595.p2.write(l6);
	hc595.p3.write(l7);
	hc595.p4.write(l8);
	hc595.p1.flush();
	hc595.p2.flush();
	hc595.p3.flush();
	hc595.p4.flush();
	led0.flush();
	led1.flush();
	led2.flush();
	led3.flush();
	
	hwlib::wait_ms( 150 );
}
}
