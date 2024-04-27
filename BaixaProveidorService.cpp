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

    List<Int64>^ providers_id = gcnew List<Int64>(0);
    Int64 rol = 3LL;
    providers_id = usuariRolRepository->GetUsersByRolId(rol);
    IEnumerator<Int64>^ enumerator = providers_id->GetEnumerator();

    while (enumerator->MoveNext())
        providers->Add(usuariRepository->GetUsuariById(enumerator->Current));

    return providers;
}