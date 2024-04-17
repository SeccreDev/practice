#include "Person.h"

// Static Member Variable must be initialized outside of the class declaration
int Person::personCount = 0; // Static Member Variable initialized to 0

void Person::incrementPersonCount() // The definition of a static function is not preceded by the keyword static, but the prototype is.
{
	personCount++;
}
