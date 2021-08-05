#include "hwlib.hpp"

class decorator_AND : public hwlib::pin_in{
private:
	hwlib::pin_in & pin1;
	hwlib::pin_in & pin2;
public:
	decorator_AND(hwlib::target::pin_in & p1, hwlib::target::pin_in & p2) :
	pin1(p1),
	pin2(p2){}
	
	bool read() override{
		return pin1.read();
	}
	
	void refresh() override{
		pin1.refresh();
	}
	
	bool get(){
		if(pin1.read() == 1 && pin2.read() == 1){
			return 1;
		}else{
			return 0;
		}
	}
};
