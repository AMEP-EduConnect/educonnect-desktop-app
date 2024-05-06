#pragma once
#include "UsuariRepository.h"
#include "UsuariRolRepository.h"
#include <vector>

public ref class BaixaProveidorService
{
public:
    BaixaProveidorService();
    bool BaixaProveidor(String^ value);
    List<Usuari^>^ ListProveidors();
    Usuari^ GetProveidorByEspaiId(Int64^ espai_id);
private:
    UsuariRepository^ usuariRepository;
    UsuariRolRepository^ usuariRolRepository;
};