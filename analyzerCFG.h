#ifndef __ANALYZER_CFG_H
#define __ANALYZER_CFG_H
#include "analyzer.h"
#include <beaengine/BeaEngine.h>
#include <cstring>
#include <stdint.h>
#include <unordered_set>
#include "instructionQueue.h"
#include "cache.h"

namespace detect_similar
{

class AnalyzerCFG : public Analyzer
{
public:
	AnalyzerCFG(bool brut = true);
	AnalyzerCFG(const unsigned char* data, uint size, bool brut = true);
	~AnalyzerCFG();
	string analyze();
	void loadShellcodes(char* dirname);
	ostream & operator<<(ostream &);
	istream & operator>>(istream &);
private:
	string analyze_single(int pos);
	void clear();
	InstructionQueue buildCFG(int pos, const unsigned char* buf, int buf_size);
	void processShellcodes();
	InstructionQueue _instructions;
	InstructionQueue *_shellcodeInstructions;
	unordered_set<int> _eips_passe;
	bool _brut;
	Cache _cache;
};

} //namespace detect_similar

#endif //__ANALYZER_CFG_H