#pragma once
#include "pch.h"
#include "UsuariRepository.h"

public ref class TxIniciSessio
{
public:
	TxIniciSessio();
	GetUsuariById(Int64^ id);


private:
	UsuariRepository^ UsuariRepository;

};