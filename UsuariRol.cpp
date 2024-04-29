#include "pch.h"
#include "UsuariRol.h"

UsuariRol::UsuariRol()
{
}
UsuariRol::UsuariRol(Int64^ user_id, Int64^ rol_id) {
	this->user_id = user_id;
	this->rol_id = rol_id;
}
void UsuariRol::SetUserId(Int64^ value) {
	this->rol_id = value;
}
Int64^ UsuariRol::GetUserId() {
		return user_id;
}
void UsuariRol::SetRolId(Int64^ value) {
	this->rol_id = value;
}
Int64^ UsuariRol::GetRolId() {
	return rol_id;
}

