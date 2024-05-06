#include "pch.h"
#include "BaixaProveidorService.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"
using namespace System::Collections::Generic;

BaixaProveidorService::BaixaProveidorService() {
    usuariRepository = gcnew UsuariRepository();
    usuariRolRepository = gcnew UsuariRolRepository();
}

bool BaixaProveidorService::BaixaProveidor(String^ username) {
    Int64^ id_user = usuariRepository->GetUserId(username);
    Int64^ not_id;
    if (id_user != not_id) {
        Int64^ rol_id = usuariRolRepository->GetRolId(id_user);
        if (*rol_id == 3LL) return usuariRepository->DeleteUser(id_user);
        else return false;
    }
    else return false;
}


List<Usuari^>^ BaixaProveidorService::ListProveidors() {
    List<Usuari^>^ providers = gcnew List<Usuari^>(0);
    providers = usuariRepository->GetUsersByRolId(3LL);
    return providers;
}

Usuari^ BaixaProveidorService::GetProveidorByEspaiId(Int64^ espai_id) {
	Usuari^ proveidor = usuariRepository->GetProveidorByEspaiId(espai_id);
	return proveidor;
}