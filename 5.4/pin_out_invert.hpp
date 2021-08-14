#include "hwlib.hpp"

class pin_out_invert : public hwlib::pin_out{
private:
	hwlib::all_from_pin_out_t g1;
	hwlib::all_from_pin_out_t g2;
public:
	pin_out_invert(hwlib::target::pin_out & p1, hwlib::target::pin_out & p2, hwlib::target::pin_out & p3, hwlib::target::pin_out & p4, hwlib::target::pin_out & p5, hwlib::target::pin_out & p6, hwlib::target::pin_out & p7, hwlib::target::pin_out & p8):
		g1(hwlib::all_from_pin_out_t(p1, p2, p3, p4, hwlib::pin_out_dummy,  hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, 
			hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy)), 
		g2(hwlib::all_from_pin_out_t(p5, p6, p7, p8, hwlib::pin_out_dummy,  hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy,
			hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy, hwlib::pin_out_dummy))
	{}
	void write(bool value) override{
		g1.write(value);
		g2.write(!value);
	}
	void flush() override{
		g1.flush();
		g2.flush();
	}
};
