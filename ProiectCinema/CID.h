#pragma once
class CID
{

public:
	static CID& get_instance();
	static CID& get_first_instance(int id);
	static void destroy_instance();
	unsigned int getID();

private:     
	CID();
	~CID();
	CID(int id); 

	static CID* instance;
	unsigned int last_ID;

};

