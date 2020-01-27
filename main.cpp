#include <iostream>
#include <sys/time.h>

int main() {
	std::cout << "Hello, World! VERSION 2.0" << std::endl;

	struct timeval tvBefore;
	struct timeval tvAfter;
//	tv.tv_sec = 10;
	gettimeofday(&tvBefore, NULL);
	std::cout << " time try:" << tvBefore.tv_sec << std::endl;
//	while(tv.tv_sec > gettimeofday(&tv, NULL)){
////		if (tv.tv_sec % 10 == 0){
////			std::cout << "thing" << std::endl;
////		}
//	}
	int i = 0;
	while (i < 1000000000) {
		++i;
	}
	gettimeofday(&tvAfter, NULL);
	std::cout << "time ended: " << tvAfter.tv_sec << " i is : " << i << std::endl;
	return 0;
}
