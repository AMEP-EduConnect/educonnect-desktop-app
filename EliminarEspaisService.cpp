#include "pch.h"
#include "EliminarEspaisService.h"

EliminarEspaisService::EliminarEspaisService() {
	espaisRepository = gcnew EspaisRepository();
}

bool EliminarEspaisService::eliminarEspais(String^ name) {
	Espais ^ espai = getEspai(name);
	if (espai != nullptr) return espaisRepository->DeleteEspai(espai->GetEspaiId());
	else return false;
}

Espais^ EliminarEspaisService::getEspai(String^ name) {
	return espaisRepository->GetEspaiByName(name);
}