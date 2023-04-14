# include <stdexcept>

using namespace std;

class InsanityError: public runtime_error {};
class TypeError: public runtime_error {};