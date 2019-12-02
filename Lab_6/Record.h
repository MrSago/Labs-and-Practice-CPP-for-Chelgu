#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <xstring>

class Record
{
public:
	std::vector<Record> arr;
	std::string Name = "";
	std::string Age = "";
};

#endif //RECORD_H