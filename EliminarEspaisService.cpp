#include "pch.h"
#include "EliminarEspaisService.h"

EliminarEspaisService::EliminarEspaisService() {
	espaisRepository = gcnew EspaisRepository();
}

bool EliminarEspaisService::eliminarEspais(String^ name) {
	Espai ^ espai = getEspai(name);
	if (espai != nullptr) return espaisRepository->DeleteEspai(espai->GetEspaiId());
	else return false;
}

Espai^ EliminarEspaisService::getEspai(String^ name) {
	return espaisRepository->GetEspaiByName(name);
}