//include matching header
#include "Customer.h"
#include "Defines.h"

//use namespace std
using namespace std;

//external variables
extern const int MAX_CUPS;
extern const int MIN_CUPS;

//random cup number gen
int iCups = rand()%( MAX_CUPS - MIN_CUPS ) + MIN_CUPS;

void updateCustomerTimer()
{

}