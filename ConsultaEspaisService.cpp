#include "pch.h"
#include "ConsultaEspaisService.h"

ConsultaEspaisService::ConsultaEspaisService() {
    espaisRepository = gcnew EspaisRepository();
}

List<Espais^>^ ConsultaEspaisService::ListEspais(Int64^ id_prov) {
    List<Espais^>^ espais = gcnew List<Espais^>(0);
    espais = espaisRepository->GetEspaisById(id_prov);
    return espais;
}