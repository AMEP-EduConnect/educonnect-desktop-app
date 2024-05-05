#include "pch.h"
#include "ConsultaEspaisService.h"

ConsultaEspaisService::ConsultaEspaisService() {
    espaisRepository = gcnew EspaisRepository();
}

List<Espai^>^ ConsultaEspaisService::ListEspais(Int64^ id_prov) {
    List<Espai^>^ espais = gcnew List<Espai^>(0);
    espais = espaisRepository->GetEspaisById(id_prov);
    return espais;
}

bool ConsultaEspaisService::CheckIfEspaiExistsByName(String^ name)
{

	Espai^ exists = this->espaisRepository->GetEspaiByName(name);
	if (exists == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Int64^ ConsultaEspaisService::GetEspaiIdByName(String^ name)
{
	Espai^ espai = this->espaisRepository->GetEspaiByName(name);
	return espai->GetEspaiId();
}

Espai^ ConsultaEspaisService::GetEspaiByEspaiId(Int64^ id)
{
	return this->espaisRepository->GetEspaiByEspaiId(id);
}

String^ ConsultaEspaisService::GetEspaiInfoById(Int64^ id)
{
	return this->espaisRepository->GetInfoEspaiById(id);
}