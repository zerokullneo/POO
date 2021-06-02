#include <iostream>
#include <vector>

using namespace std;

template <typename T = char, size_t item_ = 256> class Buffer
{
    private:
        vector<item_> items_{256};

	public:
        Buffer(vector<item_> items);
		void f(){ cout << "función de B." << endl; }
};
