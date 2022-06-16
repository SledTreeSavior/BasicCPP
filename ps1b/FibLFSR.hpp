#include <vector>
#include <iostream>
class FibLFSR {
	public:
		//constructor to create LFSR with
		//the given initial seed and tap
		FibLFSR(std::string seed);	
		//simulate one step and return the
		//new bit as 0 or 1
		int step();
		//simulate k steps and return
		//k-bit integer
		int generate(int k);

		friend std::ostream& operator<<(std::ostream& out, const FibLFSR& right);
	private:
		int length;
		std::vector<short> data;
};
