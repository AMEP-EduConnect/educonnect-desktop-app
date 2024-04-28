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