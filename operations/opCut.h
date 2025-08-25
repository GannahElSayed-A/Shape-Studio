#include "../operations/operation.h"
class opcut : public operation
{
public:
	opcut(controller* pCont);

	virtual void Execute();
};
