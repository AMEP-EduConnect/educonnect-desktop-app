#include "pch.h"
#include "BaixaProveidorService.h"
#include "DatabaseConnector.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"

BaixaProveidorService::BaixaProveidorService() {
    proveidorRepository = gcnew ProveidorRepository();
}

bool BaixaProveidorService::BaixaProveidor(String^ username) {

    if (this->CheckIfProveidorExists(username)) {
        MessageManager::WarningMessage("El proveedor no existe.");
        return false;
    }
    proveidorRepository->BaixaProveidor(username);
    return true;
}

bool BaixaProveidorService::CheckIfProveidorExists(String^ username) {
    return proveidorRepository->CheckIfProveidorExists(username);
}
