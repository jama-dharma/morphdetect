#include <vector>
#include <finddecryptor/reader.h>
#include <finddecryptor/emulator.h>
#include <finddecryptor/emulator_libemu.h>
//#include <finddecryptor/emulator_qemu.h>
#include <finddecryptor/data.h>

namespace detect_similar
{

using namespace std;
using namespace find_decryptor;
typedef pair <unsigned int,unsigned int> IntPair;

class ChangedMemory
{
public:
	ChangedMemory(char* filename, int emulator_type);
	ChangedMemory(unsigned char* data, int datasize, int emulator_type);
	~ChangedMemory();
	int compute(int entry_point);
	void getsizes(int* shellcode_size);
	void getmem(unsigned char** shellcode);
private:
	void clear();
	bool contains(IntPair new_p, IntPair cur_p);
	bool intersect_left(IntPair new_p, IntPair cur_p);
	bool intersect_right(IntPair new_p, IntPair cur_p);
	bool is_contained_by(IntPair new_p, IntPair cur_p);
	Data::Register convertRegister(int beareg);
	Data::Register convertSegmentRegister(int beareg);
	//bool is_ok(vector<IntPair> intervals);
	//Emulator_LibEmu* emulator;
	Emulator* emulator;
	Reader *reader;
	unsigned char** shellcode;
	int* shellcode_size;
	int amount_shellcodes;	
};

} //namespace detect_similar

