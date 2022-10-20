#include "PrintEdition.h"

void PrintEdition::SetType(int _type) {
	type = _type;
}
int PrintEdition::GetType() {
	return type;
}
void PrintEdition::SetErr(bool _err) {
	err = _err;
}
bool PrintEdition::GetErr() {
	return err;
}
PrintEdition::~PrintEdition() {

}