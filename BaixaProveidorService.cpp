#include "pch.h"
#include "BaixaProveidorService.h"
#include "DatabaseConnector.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"

BaixaProveidorService::BaixaProveidorService() {
    proveidorRepository = gcnew ProveidorRepository();
}

bool BaixaProveidorService::BaixaProveidor(String^ username) {
    Int64^ id_user = CheckProveidorExists(username);
    Int64^ not_id;
    if(id_user != not_id) {
        bool check_proveidor = CheckIsProveidor(id_user);
        if(check_proveidor == true) {
            proveidorRepository->DeleteProveidor(username);
            return true;
        }
        else return false;
    }
    else return false;
}

Int64^ BaixaProveidorService::CheckProveidorExists(String^ username) {
    return proveidorRepository->CheckProveidorandGetId(username);
}

bool BaixaProveidorService::CheckIsProveidor(Int64^ id_role) {
    return proveidorRepository->CheckIfIsProveidor(id_role);
}

