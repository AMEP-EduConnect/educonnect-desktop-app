#include "pch.h"
#include "BaixaProveidorService.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"

BaixaProveidorService::BaixaProveidorService() {
    usuariRepository = gcnew UsuariRepository();
    usuariRolRepository = gcnew UsuariRolRepository();
}

bool BaixaProveidorService::BaixaProveidor(String^ username) {
    Int64^ id_user = usuariRepository->GetUserId(username);
    Int64^ not_id;
    if(id_user != not_id) {
        Int64^ rol_id = usuariRolRepository->GetRolId(id_user);
        if(*rol_id == 3LL) return usuariRepository->DeleteUser(id_user);
        else return false;
    }
    else return false;
}


